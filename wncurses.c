#include <Windows.h>
//#include <stdio.h>
#include "wncurses.h"

//public functions
WINDOW*				initscr				(void);
int					endwin				(void);
int					refresh				(void);
int					wrefresh			(WINDOW *window);
int					addch				(chtype input);
int					waddch				(WINDOW *window, chtype input);
int					mvaddch				(int y,int x,chtype input);
int					mvwaddch			(WINDOW *window, int y,int x,chtype input);
int					addstr				(const char*);
int					waddstr				(WINDOW *window,const char*);
int					mvaddstr			(int y, int x, const char*);
int					mvwaddstr			(WINDOW *window, int y, int x, const char*);
int					move				(int y, int x);
int					wmove				(WINDOW *window, int y, int x);
//the printw cannot convert directly due to the va_list
int					printw				(const char *input,...);
int					mvprintw			(int y,int x,const char *input,...);
int					wprintw				(WINDOW *window, const char*,...);
int					mvwprintw			(WINDOW *window, int y,int x,const char *input,...);


//-------------------private functions
inline COORD		_coord_create		(short y, short x);
inline void			_coord_s_init		(COORD_S *coord_s, short y, short x);
inline void			_swapbuffer_swap	(HANDLE *a, HANDLE *b);
inline BOOL			_clear_buffer		(HANDLE buffer);
//set the real cursor position to the position stored in the window
BOOL				_cursor_sync		(WINDOW *window);			

int LINES;
int COLS;
WINDOW *stdscr;

WINDOW *
initscr				(void)
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
		&(stdscr->_cur),
		0,
		0
	);
	_coord_s_init(
		&(stdscr->_size),
		console_info.srWindow.Bottom - (stdscr->_beg._y) + 1,
		console_info.srWindow.Right - (stdscr->_beg._x) + 1
	);
	
	LINES				= stdscr->_size._y;
	COLS				= stdscr->_size._x;

	stdscr->_cur_color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

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
endwin				(void)
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

int 
refresh				(void)
{
	wrefresh(stdscr);
}

//----refersh line
//swapbuffer
//set the current buffer
//due to the cursor position differs in different buffer after the front buffer was modified when its a backbuffer
//so we need to move the back cursor position to the back buffer cursor position 
//and move the front buffer's data to the back buffer

/*------------------ATTENTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
If there is bug, might be this*/
int
wrefresh			(WINDOW *window)
{
	_swapbuffer_swap(window->_swapbuffer[SWAPBUFFER_FRONT],window->_swapbuffer[SWAPBUFFER_BACK]);

	//unfinished
	//I dont know if this is essential, depends on the implementation of the setconsoleActiveScreenBuffer
	SetConsoleActiveScreenBuffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT]);

	if(_cursor_sync(window)==ERR)
		return ERR;

	TCHAR *_tmp_data = (TCHAR*)malloc(sizeof(TCHAR)*window->_size._x*window->_size._y);
	if(_tmp_data==NULL)
		return ERR;

	SMALL_RECT _reg = { window->_beg._x,window->_beg._y,(window->_beg._x) + (window->_size._x),(window->_beg._y) + (window->_size._y) };
	ReadConsoleOutput(
		window->_swapbuffer[SWAPBUFFER_FRONT], 
		_tmp_data, 
		_coord_create(window->_size._y,window->_size._x),
		_coord_create(0,0),
		&_reg
	);
	WriteConsoleOutput(
		window->_swapbuffer[SWAPBUFFER_BACK], 
		_tmp_data, 
		_coord_create(window->_size._y,window->_size._x),
		_coord_create(0,0),
		&_reg
	);

	free(_tmp_data);

	return OK;
}

int
addch				(chtype input)
{
	return waddch(stdscr,input);
}

/*
int
waddch				(WINDOW* window,chtype input)
{
	CHAR_INFO _input_ch;
	_input_ch.Char.AsciiChar=input;
	_input_ch.Char.UnicodeChar=input;
	_input_ch.Attributes = window->_cur_color;

	COORD _size= _coord_create(1,1);
	COORD _begin=_coord_create(window->_cur._y,window->_cur._x);
	SMALL_RECT _region = { _begin.X,_begin.Y,_begin.X + _size.X,_begin.Y + _size.Y };

	//actually the '\r' and '\n'can be print to the screen but seems like a square
	if(input=='\r')
		wmove(window,window->_cur._y,0);
	else if(input =='\n')
		wmove(window,(window->_cur._y)+1,0);
	else{
		if (!WriteConsoleOutput(window->_swapbuffer[SWAPBUFFER_BACK], &_input_ch, _size, _begin, &_region))
			return ERR;
		window->_cur._x = (window->_cur._x + 1) % (window->_size._x);
		window->_cur._y += (window->_cur._x == 0);
		if(_cursor_sync(window)==ERR)
			return ERR;
	}
	return OK;
}
*/
int
waddch				(WINDOW *window,chtype input)
{
	DWORD _written_length;
	if(!WriteConsole(window->_swapbuffer[SWAPBUFFER_BACK],&input,1,&_written_length,NULL))
		return ERR;
	return OK;
}

//finally I will make it MACRO
int
mvaddch				(int y,int x,chtype input)
{
	return mvwaddch(stdscr,y,x,input);
}

int
mvwaddch			(WINDOW *window,int y,int x,chtype input)
{
	wmove(window,y,x);
	return waddch(window,input);
}

int
addstr				(const char *input)
{
	return waddstr(stdscr,input);
}

//unfinished
int
waddstr				(WINDOW *window, const char *input)
{
	DWORD _written_length;
	if(!WriteConsole(window->_swapbuffer[SWAPBUFFER_BACK],input,1,&_written_length,NULL))
		return ERR;
	return OK;
}

int
mvaddstr			(int y,int x,const char *input)
{
	return mvwaddstr(stdscr, y, x, input);
}

int
mvwaddstr			(WINDOW *window,int y,int x,const char *input)
{
	if(move(y,x)==ERR)
		return ERR;
	return waddstr(window,input);
}

int
move				(int y, int x)
{
	return wmove(stdscr,y,x);
}

int 
wmove				(WINDOW *window, int y, int x)
{
	window->_cur._y = y;
	window->_cur._x = x;
	if(!SetConsoleCursorPosition(window->_swapbuffer[SWAPBUFFER_BACK], _coord_create((short)y, (short)x)))
		return ERR;
	return OK;
}




//-------------------private
inline COORD	
_coord_create		(short y, short x)
{
	COORD _tmp;
	_tmp.Y = y;
	_tmp.X = x;
	return _tmp;
}

inline COORD_S
_coord_s_create		(short y, short x)
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
_clear_buffer		(HANDLE buffer)
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

BOOL
_cursor_sync		(WINDOW *window)
{
	return SetConsoleCursorPosition(window->_swapbuffer[SWAPBUFFER_BACK], _coord_create(window->_cur._y, window->_cur._x));
}