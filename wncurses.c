#include <Windows.h>
//#include <stdio.h>
#include "wncurses.h"

//public functions
WINDOW*				initscr				(void);
int					endwin				(void);

//private functions
inline COORD		_coord_create		(short y, short x);
inline void			_coord_s_init		(COORD_S *coord_s, short y, short x);
inline void			_swapbuffer_swap	(HANDLE *a, HANDLE *b);
inline BOOL			_clear_buffer		(HANDLE buffer);

int LINES;
int COLS;
WINDOW *stdscr;

WINDOW *
initscr(void)
{
	CONSOLE_SCREEN_BUFFER_INFO  console_info;
	stdscr = (WINDOW *)malloc(sizeof(WINDOW));
	if (!stdscr) 
		exit(1);

	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_info))
		exit(1);

	_coord_s_init(
		&(stdscr->_beg),
		console_info.srWindow.Top,
		console_info.srWindow.Left
	);
	_coord_s_init(
		&(stdscr->_max),
		console_info.srWindow.Bottom,
		console_info.srWindow.Right
	);
	_coord_s_init(
		&(stdscr->_size),
		(stdscr->_max._y) - (stdscr->_beg._y) + 1,
		(stdscr->_max._x) - (stdscr->_beg._x) + 1
	);
	LINES				= stdscr->_size._y;
	COLS				= stdscr->_size._x;

	stdscr->_swapbuffer[SWAPBUFFER_FRONT] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		//I dont what the console share mode means, so set it to 0 to see if something wrong happens
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	stdscr->_swapbuffer[SWAPBUFFER_BACK] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		//I dont what the console share mode means, so set it to 0 to see if something wrong happens
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	if (
		stdscr->_swapbuffer[SWAPBUFFER_FRONT] == INVALID_HANDLE_VALUE
		||
		stdscr->_swapbuffer[SWAPBUFFER_BACK] == INVALID_HANDLE_VALUE
		)
		exit(1);
	//The COORD is XY and the COORD_S IS yx so cannot be converted directly
	if (
			!SetConsoleScreenBufferSize (
				stdscr->_swapbuffer[SWAPBUFFER_FRONT],
				_coord_create(stdscr->_size._y,stdscr->_size._x)
			)
			||
			!SetConsoleScreenBufferSize (
				stdscr->_swapbuffer[SWAPBUFFER_BACK],
				_coord_create(stdscr->_size._y,stdscr->_size._x)
			)
		)
		exit(1);
	_clear_buffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT]);
	_clear_buffer(stdscr->_swapbuffer[SWAPBUFFER_BACK]);

	if(!SetConsoleActiveScreenBuffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT]))
		exit(1);

	return stdscr;
}

int 
endwin			(void)
{
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));
	if(
		!CloseHandle(stdscr->_swapbuffer[SWAPBUFFER_FRONT])
		||
		!CloseHandle(stdscr->_swapbuffer[SWAPBUFFER_BACK])
		)
		return ERR;
	free(stdscr);
	return OK;
}


inline COORD	
_coord_create	(short y, short x)
{
	COORD _tmp;
	_tmp.Y = y;
	_tmp.X = x;
	return _tmp;
}

inline COORD_S
_coord_s_create(short y, short x)
{
	COORD_S _tmp;
	_tmp._y = y;
	_tmp._x = x;
	return _tmp;
}

inline void
_coord_s_init		(COORD_S *coord_s,short y,short x)
{
	coord_s->_y = y;
	coord_s->_x = x;
}

inline void
_swapbuffer_swap	(HANDLE *a, HANDLE *b)
{
	//How to xor the void* type..... Temporily use the _tmp.
	HANDLE _tmp;
	_tmp=*a;
	*a = *b;
	*b = _tmp;
}

inline BOOL
_clear_buffer(HANDLE buffer)
{
	CONSOLE_SCREEN_BUFFER_INFO _buffer_info;
	if (!GetConsoleScreenBufferInfo(buffer, &_buffer_info))
		return FALSE;
	DWORD _length = (DWORD)(
		(_buffer_info.srWindow.Bottom-_buffer_info.srWindow.Top)
		*
		(_buffer_info.srWindow.Right-_buffer_info.srWindow.Left)
	);
	//unused
	DWORD _length_written;
	if(!FillConsoleOutputCharacter(buffer,' ',_length,_coord_create(0,0),&_length_written))
		return FALSE;
	return TRUE;
}