#include "window.h"
#include"error.h"
#include "vars.h"
#include "coord.h"
#include <Windows.h> 

WINDOW *
initscr				(void)
{
	_vars_reset();

	CONSOLE_SCREEN_BUFFER_INFO  console_info;

	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_info))
		AN_ERROR();

	stdscr = newwin(
		console_info.srWindow.Bottom - console_info.srWindow.Top + 1,
		console_info.srWindow.Right - console_info.srWindow.Left + 1,
		0, 0);

	if (!stdscr)
		AN_ERROR();

	console_buffer_size = stdscr->_size;

	console_buffer = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	if (!console_buffer)
		AN_ERROR();

	if (!SetConsoleScreenBufferSize(
		console_buffer,
		console_buffer_size))
		AN_ERROR();

	refresh();

	if (!SetConsoleActiveScreenBuffer(console_buffer))
		AN_ERROR();

	return stdscr;
}

int
endwin				(void)
{
	delwin(stdscr);
	stdscr = NULL;
	CloseHandle(console_buffer);
	return OK;
}

BOOL
isendwin			(void)
{
	return stdscr == NULL;
}

WINDOW*
newwin				(int nlines, int ncols, int begin_y, int begin_x)
{
	WINDOW *_tmp_window = (WINDOW *)malloc(sizeof(WINDOW));
	if (_tmp_window == NULL)
        AN_ERROR();

	_coord_init(&_tmp_window->_pos, begin_y, begin_x);
	_coord_init(&_tmp_window->_size, nlines, ncols);
	_coord_init(&_tmp_window->_cur, 0, 0);

	_tmp_window->_bkgd_ch = ' ';
	_tmp_window->_bkgd_color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	// the default input is blocking
	_tmp_window->_delay = -1;
	_tmp_window->_immed = FALSE;
	_tmp_window->_keypad = TRUE;
	_tmp_window->_leaveok = FALSE;
    int tmp_length = nlines * ncols;
    _tmp_window->_buffer = (CHAR_INFO *)malloc(tmp_length * sizeof(CHAR_INFO));
    for (int i = 0; i < tmp_length; ++i) {
        _tmp_window->_buffer[i].Attributes = _tmp_window->_bkgd_color;
        _tmp_window->_buffer[i].Char.UnicodeChar = _tmp_window->_bkgd_ch;
    }
	return _tmp_window;
}

int
delwin				(WINDOW *window)
{
    if (!window)
        return ERR;
    free(window->_buffer);
	free(window);
	window = NULL;
	return OK;
}

int
mvwin               (WINDOW *window, int y, int x)
{
    if (!window)
        return ERR;
    if (y >= console_buffer_size.Y)
        return ERR;
    if (x >= console_buffer_size.X)
        return ERR;
    window->_pos.Y = y;
    window->_pos.X = x;
	return OK;
}

int
refresh				(void)
{
	return wrefresh(stdscr);
}

int
wrefresh			(WINDOW *window)
{
	return _wrefresh_raw(window);
}

int
_wrefresh_raw		(WINDOW *window)
{
	if (!SetConsoleCursorPosition(
            console_buffer,
            _coord_create(window->_cur.Y, window->_cur.X)))
        return ERR;

	SMALL_RECT _reg = {
        window->_pos.X,
        window->_pos.Y,
		window->_pos.X + window->_size.X - 1,
		window->_pos.Y + window->_size.Y - 1
	};

	if (!WriteConsoleOutputW(
        console_buffer,
		window->_buffer,
		_coord_create(window->_size.Y, window->_size.X),
		_coord_create(0, 0),
		&_reg))
		return ERR;

	return OK;
}

int
doupdate			(void)
{
	return _wrefresh_raw(stdscr);
}

int
redrawwin			(WINDOW *window)
{
	if (!window)
		return ERR;
	_wrefresh_raw(window);
	return OK;
}

int
wredrawln			(WINDOW *window, int beg_line, int num_lines)
{
	if (!window)
		return ERR;

	if ( num_lines <= 0 || beg_line + num_lines >= window->_size.Y)
		return ERR;

	SMALL_RECT _reg = {
        window->_pos.X,
        window->_pos.Y + beg_line,
		window->_pos.X + window->_size.X - 1,
		window->_pos.Y + beg_line + num_lines
	};

	if (!WriteConsoleOutputW(
        console_buffer,
		window->_buffer,
		_coord_create(window->_size.Y, window->_size.X),
		_coord_create(0, 0),
		&_reg))
		return ERR;

	return OK;
}

