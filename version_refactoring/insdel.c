#include"insdel.h"
#include"coord.h"
#include"window.h"
#include"utils.h"

int
delch				(void)
{
	return wdelch(stdscr);
}

int
wdelch				(WINDOW *window)
{
	COORD _buffer_size = _coord_create(1, window->_size.X - window->_cur.X);
	SMALL_RECT _region = {
		window->_cur.X + 1,
		window->_cur.Y,
		window->_size.X - 1,
		window->_cur.Y};
	CHAR_INFO *_buffer = (CHAR_INFO *)malloc(_buffer_size.X * sizeof(CHAR_INFO));
	if (_buffer == NULL)
		return ERR;

	if (
		!ReadConsoleOutputW(
			window->_swapbuffer[SWAPBUFFER_BACK],
			_buffer, _buffer_size,
			_coord_create(0, 0),
			&_region))
		return ERR;

	//the last cell of buffer is empty
	_buffer[_buffer_size.X - 1].Char.UnicodeChar = window->_bkgd_ch;
	_buffer[_buffer_size.X - 1].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;

	_region.Left -= 1;
	if (!WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_buffer, _buffer_size,
		_coord_create(0, 0),
		&_region))
		return ERR;

	free(_buffer);

	_buffer = NULL;

	if (window->_immed)
		if (_wrefresh_pure(window) == ERR)
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
	//Unicode
	COORD _buffer_size = _coord_create(
		window->_size.Y - window->_cur.Y,
		window->_size.X);

	SMALL_RECT _region = {
		0,
		window->_cur.Y + 1,
		window->_size.X - 1,
		window->_size.Y - 1};

	CHAR_INFO *_buffer = (CHAR_INFO *)malloc(
		_buffer_size.Y * _buffer_size.X
		* sizeof(CHAR_INFO));
	if (!_buffer)
		return ERR;

	if (!ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_buffer, _buffer_size,
		_coord_create(0, 0),
		&_region))
		return ERR;

	for (int i = 0; i < window->_size.X; ++i) {
		//The attribute will be replaced with window->_bkgd_attr in the future
		_buffer[_buffer_size.X * (_buffer_size.Y - 1) + i].Attributes =
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		_buffer[_buffer_size.X * (_buffer_size.Y - 1) + i].Char.UnicodeChar =
			window->_bkgd_ch;
	}

	_region.Top -= 1;
	if (!WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_buffer, _buffer_size,
		_coord_create(0, 0),
		&_region))
		return ERR;
	free(_buffer);
	if (window->_immed)
		if (_wrefresh_pure(window) == ERR)
			return ERR;
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
	COORD _buffer_size = _coord_create(
		window->_size.Y - window->_cur.Y,
		window->_size.X);

	SMALL_RECT _region = {
		0,
		window->_cur.Y,
		window->_size.X - 1,
		window->_size.Y - 2};

	CHAR_INFO *_blank = (CHAR_INFO *)malloc(
		_buffer_size.X * _buffer_size.Y
		* sizeof(CHAR_INFO));
	if (!_blank)
		return ERR;

	for (int i = 0; i < _buffer_size.X; ++i) {
		_blank[i].Attributes =
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		_blank[i].Char.UnicodeChar =
			window->_bkgd_ch;
	}

	if (!ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_blank, _buffer_size,
		_coord_create(1, 0),
		&_region))
		return ERR;

	_region.Bottom += 1;
	if (!WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_blank, _buffer_size,
		_coord_create(0, 0),
		&_region))
		return ERR;

	free(_blank);

	if (window->_immed)
		if (_wrefresh_pure(window) == ERR)
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