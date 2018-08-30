#include <Windows.h>
#include "wncurses.h"

WINDOW*				initscr				(void);
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
		printf("Cannot malloc the window!\n");
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_info))
		printf("Cannot get the console screen buffer info\n");

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
		printf("Cannot create the swapbuffers\n");
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
		printf("Cannot set swap buffer size\n");
	//unifinished :clear the created buffer

}
inline COORD	
_coord_create	(short y, short x)
{
	COORD _tmp;
	_tmp.X = x;
	_tmp.Y = y;
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