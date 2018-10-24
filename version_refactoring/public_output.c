#include"public_output.h"
#include"swapbuffer.h"
#include"coord.h"
#include"window.h"
#include"cursor.h"
#include"utils.h"
#include<stdio.h>
#include<stdarg.h>

static int
_vwprintw			(WINDOW *window, const char *input, va_list args)
{
	char *_buffer = (char *)malloc(window->_size.X * window->_size.Y * sizeof(char));
	if (!_buffer)
		return ERR;
	if (vsprintf_s(_buffer, window->_size.X * window->_size.Y, input, args) < 0)
		return ERR;
	if (!waddstr(window, _buffer))
		return ERR;
	free(_buffer);
	return OK;
}


int
_waddch_pure		(WINDOW *window, chtype input)
{
	CHAR_INFO _input_ch;
	_input_ch.Char.UnicodeChar = input;
	_input_ch.Attributes = window->_cur_color;

	COORD _size = _coord_create(1, 1);
	COORD _begin = _coord_create(0, 0);
	SMALL_RECT _region = {
		window->_cur.X,
		window->_cur.Y,
		window->_cur.X + _size.X - 1,
		window->_cur.Y + _size.Y - 1
	};

	//Without the judgment, actually the '\r' and '\n' can be print to the screen but seems like a square.
	//In the getch function, we call the waddch to output the char gotten.
	//However the message of enter key in windows seems to be '\r' only, different from '\r\n' we always thought.
	//And to input '\n', you should press ctrl and then press '\r'.
	if (input == '\r') {
		window->_cur.Y++;
		window->_cur.X = 0;
	} else if (input == '\n') {
		window->_cur.Y++;
		window->_cur.X = 0;
	} else {
		if (!WriteConsoleOutputW(
			window->_swapbuffer[SWAPBUFFER_BACK],
			&_input_ch,
			_size,
			_begin,
			&_region))
			return ERR;
		window->_cur.X = (window->_cur.X + 1) % (window->_size.X);
		window->_cur.Y = MIN(window->_cur.Y + (window->_cur.X == 0), window->_size.Y - 1);
	}
	return OK;
}

int
addch				(chtype input)
{
	return waddch(stdscr, input);
}

int
waddch				(WINDOW* window, chtype input)
{

	if (!_waddch_pure(window, input))
		return ERR;

	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;

	return OK;
}

/*
The main fucking problem why I can't use this convenient function is
the WriteConsole function writes things after the actual cursor position
and most time before refresh was called, the actual cursor position differs
from the window->_cur.

int
waddch				(WINDOW *window,chtype input)
{
	DWORD _written_length;
	if(!WriteConsole(window->_swapbuffer[SWAPBUFFER_BACK],&input,1,&_written_length,NULL))
		return ERR;
	return OK;
}
*/

int
mvaddch				(int y, int x, chtype input)
{
	return mvwaddch(stdscr, y, x, input);
}

int
mvwaddch			(WINDOW *window, int y, int x, chtype input)
{
	wmove(window, y, x);
	return waddch(window, input);
}

int
addstr				(const char *input)
{
	return waddstr(stdscr, input);
}

int
addnstr				(const char *input, int n)
{
	return waddnstr(stdscr, input, n);
}

int
waddstr				(WINDOW *window, const char *input)
{
	return waddnstr(window, input, -1);
}

int
waddnstr			(WINDOW *window, const char *input, int n)
{
	if (n == -1) {
		for (int i = 0; input[i]; ++i)
			if (_waddch_pure(window, input[i]) == ERR)
				return ERR;
	} else if (n < 0)
		return ERR;
	else
		for (int i = 0; i < n && input[i]; ++i)
			if (_waddch_pure(window, input[i]) == ERR)
				return ERR;
	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;
	return OK;
}

int
mvaddstr			(int y, int x, const char *input)
{
	return mvwaddstr(stdscr, y, x, input);
}

int
mvaddnstr			(int y, int x, const char *input, int n)
{
	return mvwaddnstr(stdscr, y, x, input, n);
}

int
mvwaddstr			(WINDOW *window, int y, int x, const char *input)
{
	return mvwaddnstr(window, y, x, input, -1);
}

int
mvwaddnstr			(WINDOW *window, int y, int x, const char *input, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return waddnstr(window, input, n);
}

int
erase				(void)
{
	return werase(stdscr);
}

int
werase				(WINDOW *window)
{
	if (_swapbuffer_clear(
		window->_swapbuffer[SWAPBUFFER_BACK],
		window->_bkgd_ch) == FALSE)
		return ERR;
	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;
	return OK;
}

int
printw				(const char *input, ...)
{
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(stdscr, input, _args);
	va_end(_args);
	if (stdscr->_immed)
		if (!_wrefresh_pure(stdscr))
			return ERR;
	return _result;
}

int
mvprintw			(int y, int x, const char *input, ...)
{
	move(y, x);
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(stdscr, input, _args);
	va_end(_args);
	if (stdscr->_immed)
		if (!_wrefresh_pure(stdscr))
			return ERR;
	return _result;
}

int
wprintw				(WINDOW *window, const char *input, ...)
{
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(window, input, _args);
	va_end(_args);
	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;
	return _result;
}

int
mvwprintw			(WINDOW *window, int y, int x, const char *input, ...)
{
	wmove(window, y, x);
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(window, input, _args);
	va_end(_args);
	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;
	return _result;
}