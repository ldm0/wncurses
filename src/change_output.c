#include "change_output.h"
#include"window.h"
#include"vars.h"
#include"coord.h"

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


BOOL
_buffer_clear	    (WINDOW *window, chtype input)
{
    if (!window)
        return ERR;
    if (!window->_buffer)
        return ERR;
    for (int i = 0; i < window->_size.Y * window->_size.X; ++i) {
        window->_buffer[i].Char.UnicodeChar = input;
        window->_buffer[i].Attributes = window->_bkgd_color;
    }
	return OK;
}

int
bkgd				(chtype input)
{
	return wbkgd(stdscr, input);
}

int
wbkgd				(WINDOW *window, chtype input)
{
    if (!window)
        return ERR;
	int _buffer_length = window->_size.X * window->_size.Y;
	//change chars
	for (int i = 0; i < _buffer_length; ++i)
		if (window->_buffer[i].Char.UnicodeChar == window->_bkgd_ch) {
			window->_buffer[i].Char.UnicodeChar = input;
            window->_buffer[i].Attributes = window->_bkgd_color;
        }

	SMALL_RECT _reg = {
        window->_pos.X,
        window->_pos.Y,
        window->_pos.X + window->_size.X - 1,
        window->_pos.Y + window->_size.Y - 1};
	//write chars
	WriteConsoleOutputW(
        console_buffer,
		window->_buffer,
		_coord_create(window->_size.Y, window->_size.X),
		_coord_create(0, 0),
		&_reg
	);

	window->_bkgd_ch = input;

	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;

	return OK;
}

void
bkgdset				(const chtype input)
{
	wbkgdset(stdscr, input);
}

void
wbkgdset			(WINDOW *window, const chtype input)
{
	window->_bkgd_ch = input;
}

int
erase				(void)
{
	return werase(stdscr);
}

int
werase				(WINDOW *window)
{
	if (_buffer_clear(window, window->_bkgd_ch) == FALSE)
		return ERR;
	if (wmove(window, 0, 0) == ERR)
		return ERR;
	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;
	return OK;
}

int
clear				(void)
{
	return wclear(stdscr);
}

int
wclear				(WINDOW *window)
{
	if (werase(window) == ERR)
		return ERR;
	return clearok(window, TRUE);
}

int
clrtobot			(void)
{
	return wclrtobot(stdscr);
}

int
wclrtobot			(WINDOW *window)
{
    int _buffer_length = window->_size.Y * window->_size.X;
    int _start_pos = window->_cur.X + window->_cur.Y * window->_size.X;
    for (int i = _start_pos; i < _buffer_length; ++i) {
        window->_buffer[i].Char.UnicodeChar = window->_bkgd_ch;
        window->_buffer[i].Attributes= window->_bkgd_color;
    }

	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;
	return OK;
}

int
clrtoeol			(void)
{
	return wclrtoeol(stdscr);
}

int
wclrtoeol			(WINDOW *window)
{
    int _end_pos = (window->_cur.Y + 1)* window->_size.X;
    int _start_pos = window->_cur.X + window->_cur.Y * window->_size.X;
    for (int i = _start_pos; i < _end_pos; ++i) {
        window->_buffer[i].Char.UnicodeChar = window->_bkgd_ch;
        window->_buffer[i].Attributes= window->_bkgd_color;
    }

	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;
	return OK;
}

int
delch				(void)
{
	return wdelch(stdscr);
}

int
wdelch				(WINDOW *window)
{
	int ptr_base = window->_size.X * window->_cur.Y;
	int i;
	for (i = window->_cur.X; i < window->_size.X; ++i)
		window->_buffer[ptr_base + i].Char.UnicodeChar = window->_buffer[ptr_base + i + 1].Char.UnicodeChar;
	window->_buffer[i].Attributes = window->_bkgd_color;
	window->_buffer[i].Char.UnicodeChar = window->_bkgd_ch;

	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;

	return OK;
}

int
mvdelch				(int y, int x)
{
	return mvwdelch(stdscr, y, x);
}

int
mvwdelch			(WINDOW *window, int y, int x)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return wdelch(window);
}

int
deleteln			(void)
{
	return wdeleteln(stdscr);
}

int
wdeleteln			(WINDOW *window)
{
	for (int y = window->_cur.Y; y < window->_size.Y - 1; ++y)
		for (int x = 0; x < window->_size.X; ++x) 
			window->_buffer[y * window->_size.X + x].Char.UnicodeChar 
				= window->_buffer[(y + 1) * window->_size.X + x].Char.UnicodeChar;
	for (int x = 0; x < window->_size.X; ++x) {
		window->_buffer[(window->_size.Y - 1) * window->_size.X + x].Char.UnicodeChar = window->_bkgd_ch;
		window->_buffer[(window->_size.Y - 1) * window->_size.X + x].Attributes = window->_bkgd_color;
	}
	return OK;
}

int
insertln			(void)
{
	return winsertln(stdscr);
}

int
winsertln			(WINDOW *window)
{
	for (int y = window->_cur.Y; y < window->_size.Y - 1; ++y)
		for (int x = 0; x < window->_size.X; ++x) 
			window->_buffer[(y + 1) * window->_size.X + x].Char.UnicodeChar 
				= window->_buffer[y * window->_size.X + x].Char.UnicodeChar;
	for (int x = 0; x < window->_size.X; ++x) {
		window->_buffer[window->_cur.Y * window->_size.X + x].Char.UnicodeChar = window->_bkgd_ch;
		window->_buffer[window->_cur.Y * window->_size.X + x].Attributes = window->_bkgd_color;
	}
	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;

	return OK;
}

int
insdelln			(int n)
{
	return winsdelln(stdscr, n);
}

int
winsdelln			(WINDOW *window, int n)
{
	if (!n)
		return OK;

	//Basic clip.
	n = MIN(window->_size.Y, n);
	n = MAX(-window->_size.Y, n);

	//KISS
	//When I am free, I will optimize it.
	if (n > 0) {
		for (; n > 0; --n)
			if (!winsertln(window))
				return ERR;
	} else
		for (; n < 0; ++n)
			if (!wdeleteln(window))
				return ERR;

	return OK;
}