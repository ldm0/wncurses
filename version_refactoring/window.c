#include"wncurses.h"
#include"error.h"
#include"coord.h"
#include"window.h"
#include"public_var.h"
#include"swapbuffer.h"

static BOOL
_cursor_sync		(WINDOW *window)
{
	if (!SetConsoleCursorPosition(window->_swapbuffer[SWAPBUFFER_BACK], _coord_create(window->_cur.Y, window->_cur.X)))
		return ERR;
	return OK;
}

int
_wrefresh_pure		(WINDOW *window)
{
	if (_cursor_sync(window) == ERR)
		return ERR;

	_swapbuffer_swap(&(window->_swapbuffer[SWAPBUFFER_BACK]), &(window->_swapbuffer[SWAPBUFFER_FRONT]));

	SetConsoleActiveScreenBuffer(
		stdscr->_swapbuffer[SWAPBUFFER_FRONT]);

	CHAR_INFO *_tmp_data = (CHAR_INFO *)malloc(
		window->_size.X * window->_size.Y
		* sizeof(CHAR_INFO)
	);
	if (!_tmp_data)
		return ERR;

	SMALL_RECT _reg = {
		0, 0,
		window->_size.X - 1,
		window->_size.Y - 1
	};

	if (!ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_FRONT],
		_tmp_data,
		_coord_create(window->_size.Y, window->_size.X),
		_coord_create(0, 0),
		&_reg))
		return ERR;
	if (!WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_tmp_data,
		_coord_create(window->_size.Y, window->_size.X),
		_coord_create(0, 0),
		&_reg))
		return ERR;

	free(_tmp_data);

	_tmp_data = NULL;

	return OK;
}

WINDOW*
newwin				(int nlines, int ncols, int begin_y, int begin_x)
{
	WINDOW *_tmp_window = (WINDOW *)malloc(sizeof(WINDOW));
	if (_tmp_window == NULL)
		ERROR_LOG(cannot malloc the window struct);

	_coord_init(&_tmp_window->_size, nlines, ncols);
	_coord_init(&_tmp_window->_cur, begin_y, begin_x);

	_tmp_window->_bkgd_ch = ' ';
	_tmp_window->_cur_color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	_tmp_window->_delay = TRUE;
	_tmp_window->_immed = FALSE;
	_tmp_window->_keypad = TRUE;
	_tmp_window->_leaveok = FALSE;

	_tmp_window->_swapbuffer[SWAPBUFFER_FRONT] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	_tmp_window->_swapbuffer[SWAPBUFFER_BACK] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	if (
		_tmp_window->_swapbuffer[SWAPBUFFER_FRONT] == INVALID_HANDLE_VALUE
		||
		_tmp_window->_swapbuffer[SWAPBUFFER_BACK] == INVALID_HANDLE_VALUE
		)
		ERROR_LOG(cannot create console screen buffer);
	if (
		!SetConsoleScreenBufferSize (
			_tmp_window->_swapbuffer[SWAPBUFFER_FRONT],
			_coord_create(_tmp_window->_size.Y, _tmp_window->_size.X)
		)
		||
		!SetConsoleScreenBufferSize (
			_tmp_window->_swapbuffer[SWAPBUFFER_BACK],
			_coord_create(_tmp_window->_size.Y, _tmp_window->_size.X)
		)
		)
		ERROR_LOG(cannot set screen buffer size);

	if (!_swapbuffer_clear(_tmp_window->_swapbuffer[SWAPBUFFER_FRONT], ' '))
		ERROR_LOG(cannot clear the front buffer);
	if (!_swapbuffer_clear(_tmp_window->_swapbuffer[SWAPBUFFER_BACK], ' '))
		ERROR_LOG(cannot clear the back buffer);

	return _tmp_window;
}

int
delwin				(WINDOW *window)
{
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));
	if (
		!CloseHandle(window->_swapbuffer[SWAPBUFFER_FRONT])
		||
		!CloseHandle(window->_swapbuffer[SWAPBUFFER_BACK])
		)
		return ERR;
	free(window);

	window = NULL;

	return OK;
}

int
refresh				(void)
{
	return wrefresh(stdscr);
}

//----refresh line
//swapbuffer
//set the current buffer
//due to the cursor position differs in different buffer after the front buffer was modified when its a backbuffer
//so we need to move the back cursor position to the back buffer cursor position 
//and move the front buffer's data to the back buffer

int
wrefresh			(WINDOW *window)
{
	return _wrefresh_pure(window);
}


