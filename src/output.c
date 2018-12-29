#include"output.h"
#include"change_output.h"
#include"coord.h"
#include"window.h"
#include"vars.h"
#include"cursor.h"
#include<stdio.h>
#include<stdarg.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

static int
_vwprintw(WINDOW *window, const char *input, va_list args)
{
	int tmp_buffer_length = (int)window->_size.X * window->_size.Y;
	char *_buffer = (char *)malloc(tmp_buffer_length * sizeof(char));
	if (!_buffer)
		return ERR;
	if (vsprintf_s(_buffer, tmp_buffer_length, input, args) < 0)
		return ERR;
	if (waddstr(window, _buffer) == ERR)
		return ERR;
	free(_buffer);
	return OK;
}


int
_waddch_raw(WINDOW *window, chtype input)
{
	// Without the judgment, actually the '\r' and '\n' can be print to the screen but seems like a square.
	// In the getch function, we call the waddch to output the char gotten.
	// However the message of enter key in windows seems to be '\r' only, different from '\r\n' we always thought.
	// And to input '\n', you should press ctrl and then press enter.
	if (input == '\r' || input == '\n') {
		window->_cur.Y = MIN(window->_cur.Y + 1, window->_size.Y - 1);
		window->_cur.X = 0;
	} else {
		int _ptr = window->_cur.Y * window->_size.X + window->_cur.X;
		window->_buffer[_ptr].Attributes = window->_bkgd_color;
		window->_buffer[_ptr].Char.UnicodeChar = input;
		window->_cur.X = (window->_cur.X + 1) % (window->_size.X);
		window->_cur.Y = MIN(window->_cur.Y + (window->_cur.X == 0), window->_size.Y - 1);
	}
	return OK;
}

int
addch(chtype input)
{
	return waddch(stdscr, input);
}

int
waddch(WINDOW* window, chtype input)
{

	if (_waddch_raw(window, input) == ERR)
		return ERR;
	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;
	return OK;
}

int
mvaddch(int y, int x, chtype input)
{
	return mvwaddch(stdscr, y, x, input);
}

int
mvwaddch(WINDOW *window, int y, int x, chtype input)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return waddch(window, input);
}

int
addstr(const char *input)
{
	return waddstr(stdscr, input);
}

int
addnstr(const char *input, int n)
{
	return waddnstr(stdscr, input, n);
}

int
waddstr(WINDOW *window, const char *input)
{
	return waddnstr(window, input, -1);
}

int
waddnstr(WINDOW *window, const char *input, int n)
{
	if (n == -1) {
		for (int i = 0; input[i]; ++i)
			if (_waddch_raw(window, input[i]) == ERR)
				return ERR;
	} else if (n < 0) {
		return ERR;
	} else
		for (int i = 0; i < n && input[i]; ++i)
			if (_waddch_raw(window, input[i]) == ERR)
				return ERR;
	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;
	return OK;
}

int
mvaddstr(int y, int x, const char *input)
{
	return mvwaddstr(stdscr, y, x, input);
}

int
mvaddnstr(int y, int x, const char *input, int n)
{
	return mvwaddnstr(stdscr, y, x, input, n);
}

int
mvwaddstr(WINDOW *window, int y, int x, const char *input)
{
	return mvwaddnstr(window, y, x, input, -1);
}

int
mvwaddnstr(WINDOW *window, int y, int x, const char *input, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return waddnstr(window, input, n);
}

int
printw(const char *input, ...)
{
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(stdscr, input, _args);
	va_end(_args);
	if (stdscr->_immed)
		if (_wrefresh_raw(stdscr) == ERR)
			return ERR;
	return _result;
}

int
mvprintw(int y, int x, const char *input, ...)
{
	move(y, x);
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(stdscr, input, _args);
	va_end(_args);
	if (stdscr->_immed)
		if (_wrefresh_raw(stdscr) == ERR)
			return ERR;
	return _result;
}

int
wprintw(WINDOW *window, const char *input, ...)
{
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(window, input, _args);
	va_end(_args);
	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;
	return _result;
}

int
mvwprintw(WINDOW *window, int y, int x, const char *input, ...)
{
	wmove(window, y, x);
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(window, input, _args);
	va_end(_args);
	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;
	return _result;
}


int
border(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br)
{
	return wborder(stdscr, ls, rs, ts, bs, tl, tr, bl, br);
}

//the default value haven't been set properly
/*
ls - left side,
rs - right side,
ts - top side,
bs - bottom side,
tl - top left-hand corner,
tr - top right-hand corner,
bl - bottom left-hand corner, and
br - bottom right-hand corner.
*/
int
wborder(WINDOW *window, chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br)
{
	if (!ls)
		ls = ACS_VLINE;
	if (!rs)
		rs = ACS_VLINE;
	if (!ts)
		ts = ACS_HLINE;
	if (!bs)
		bs = ACS_HLINE;
	if (!tl)
		tl = ACS_ULCORNER;
	if (!tr)
		tr = ACS_URCORNER;
	if (!bl)
		bl = ACS_BLCORNER;
	if (!br)
		br = ACS_BRCORNER;

	COORD _tmp_cur_pos = window->_cur;
	//top line
	wmove(window, 0, 0);
	waddch(window, tl);
	for (int x = 1; x < window->_size.X - 1; ++x)
		waddch(window, ts);
	waddch(window, tr);

	//bottom line
	wmove(window, window->_size.Y - 1, 0);
	waddch(window, bl);
	for (int x = 1; x < window->_size.X - 1; ++x)
		waddch(window, bs);
	waddch(window, br);

	//both sides
	for (int y = 1; y < window->_size.Y - 1; ++y) {
		mvwaddch(window, y, 0, ls);
		mvwaddch(window, y, window->_size.X - 1, rs);
	}

	if (wmove(window, _tmp_cur_pos.Y, _tmp_cur_pos.X) == ERR)
		return ERR;
	if (window->_immed)
		if (wrefresh(window) == ERR)
			return ERR;
	return OK;
}

int
box(WINDOW *window, chtype verch, chtype horch)
{
	return wborder(window, verch, verch, horch, horch, 0, 0, 0, 0);
}

int
flash(void)
{
	int tmp_buffer_length = stdscr->_size.X * stdscr->_size.Y;
	CHAR_INFO *tmp_buffer = (CHAR_INFO *)malloc(tmp_buffer_length * sizeof(CHAR_INFO));
	for (int i = 0; i < tmp_buffer_length; ++i) {
		tmp_buffer[i].Attributes = stdscr->_bkgd_color;
		tmp_buffer[i].Char.UnicodeChar = stdscr->_bkgd_color;
	}
	SMALL_RECT tmp_rect = {
		0,
		0,
		stdscr->_size.X,
		stdscr->_size.Y
	};
	if (!WriteConsoleOutputW(
		console_buffer,
		tmp_buffer,
		stdscr->_size,
		_coord_create(0, 0),
		&tmp_rect))
		return ERR;
	Sleep(100);
	if (!WriteConsoleOutputW(
		console_buffer,
		stdscr->_buffer,
		stdscr->_size,
		_coord_create(0, 0),
		&tmp_rect))
		return ERR;
	return OK;
}

int
hline(chtype ch, int n)
{
	return whline(stdscr, ch, n);
}

int
mvhline(int y, int x, chtype ch, int n)
{
	if (move(y, x) == ERR)
		return ERR;
	return hline(ch, n);
}

int
whline(WINDOW *window, chtype ch, int n)
{
	COORD _tmp_cur_pos = window->_cur;
	int _length = MIN(n, (window->_size.X) - (window->_cur.X));
	for (int i = 0; i < _length; ++i)
		if (waddch(window, ch) == ERR)
			return ERR;
	if (window->_immed)
		if (wrefresh(window) == ERR)
			return ERR;
	return wmove(window, _tmp_cur_pos.Y, _tmp_cur_pos.X);
}

int
mvwhline(WINDOW *window, int y, int x, chtype ch, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return whline(window, ch, n);
}

int
vline(chtype ch, int n)
{
	return wvline(stdscr, ch, n);
}

int
mvvline(int y, int x, chtype ch, int n)
{
	if (move(y, x) == ERR)
		return ERR;
	return vline(ch, n);
}

int
wvline(WINDOW *window, chtype ch, int n)
{
	COORD _tmp_cur_pos = window->_cur;
	for (int i = _tmp_cur_pos.Y; i < MIN(_tmp_cur_pos.Y + n, window->_size.Y); ++i)
		if (mvwaddch(window, i, _tmp_cur_pos.X, ch) == ERR)
			return ERR;
	if (wmove(window, _tmp_cur_pos.Y, _tmp_cur_pos.X) == ERR)
		return ERR;
	if (window->_immed)
		if (wrefresh(window) == ERR)
			return ERR;
	return OK;
}

int
mvwvline(WINDOW *window, int y, int x, chtype ch, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return wvline(window, ch, n);
}

int
beep(void)
{
	/*
	In Windows 7,
	Beep was rewritten to pass the beep to the default sound device for the session.
	This is normally the sound card, except when run under Terminal Services,
	in which case the beep is rendered on the client.
	*/
	if (!Beep(750, 300))
		return ERR;
	return OK;
}