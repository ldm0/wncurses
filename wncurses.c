#include <Windows.h>
//#include <stdio.h>
#include "wncurses.h"

//----------------public functions
WINDOW*				initscr				(void);
int					endwin				(void);
int					refresh				(void);
int					wrefresh			(WINDOW *window);
int					addch				(chtype input);
int					waddch				(WINDOW *window, chtype input);
int					mvaddch				(int y,int x,chtype input);
int					mvwaddch			(WINDOW *window, int y,int x,chtype input);
int					addstr				(const char*);
int					addnstr				(const char*, int n);
int					waddstr				(WINDOW *window,const char*);
int					waddnstr			(WINDOW *window,const char*,int n);
int					mvaddstr			(int y, int x, const char*);
int					mvaddnstr			(int y, int x, const char*,int n);
int					mvwaddstr			(WINDOW *window, int y, int x, const char*);
int					mvwaddnstr			(WINDOW *window, int y, int x, const char*,int n);
int					move				(int y, int x);
int					wmove				(WINDOW *window, int y, int x);
int					addchstr			(const chtype *chstr);
int					addchnstr			(const chtype *chstr, int n);
int					waddchstr			(WINDOW *window, const chtype *chstr);
int					waddchnstr			(WINDOW *window, const chtype *chstr, int n);
int					mvaddchstr			(int y, int x, const chtype *chstr);
int					mvaddchnstr			(int y, int x, const chtype *chstr, int n);
int					mvwaddchstr			(WINDOW *window, int y, int x, const chtype *chstr);
int					mvwaddchnstr		(WINDOW *window, int y, int x, const chtype *chstr, int n);
//the printw cannot convert directly due to the va_list
int					printw				(const char *input,...);
int					mvprintw			(int y,int x,const char *input,...);
int					wprintw				(WINDOW *window, const char*,...);
int					mvwprintw			(WINDOW *window, int y,int x,const char *input,...);
int					baudrate			(void);
int					beep				(void);
int					bkgd				(chtype input);
int					border				(chtype ls,chtype rs,chtype ts,chtype bs,chtype tl,chtype tr,chtype bl,chtype br);
int					wborder				(WINDOW *window, chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br);
int					box					(WINDOW *window, chtype verch, chtype horch);
int					flash				(void);
int					can_change_color	(void);
int					hline				(chtype ch, int n);
int					vline				(chtype ch, int n);
int					whline				(WINDOW*,chtype ch, int n);
int					wvline				(WINDOW*,chtype ch, int n);
int					mvhline				(int y, int x, chtype ch, int n);
int					mvvline				(int y, int x, chtype ch, int n);
int					mvwhline			(WINDOW*, int y, int x, chtype ch, int n);
int					mvwvline			(WINDOW*, int y, int x, chtype ch, int n);
int					curs_set			(int n);
int					clear				(void);
int					wclear				(WINDOW *window);
int					erase				(void);
int					werase				(WINDOW *window);
int					clrtobot			(void);
int					clrtoeol			(void);
int					wclrtobot			(WINDOW *);
int					wclrtoeol			(WINDOW *);
int					instr				(char *output);
int					mvcur				(int oldrow, int oldcol, int newrow, int newcol);


//-------------------private functions
inline COORD		_coord_create		(short y, short x);
inline void			_coord_s_init		(COORD_S *coord_s, short y, short x);
inline void			_swapbuffer_swap	(HANDLE *a, HANDLE *b);
inline BOOL			_clear_buffer		(HANDLE buffer,chtype input);
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

	stdscr->_bkgd_ch = ' ';

	stdscr->_cur_color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

	stdscr->_swapbuffer[SWAPBUFFER_FRONT] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		//I dont what the console share mode means, so set it to 0 to see if something wrong happens
		//0,
		//yes something wrong happens
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	stdscr->_swapbuffer[SWAPBUFFER_BACK] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
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
	_clear_buffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT], ' ');
	_clear_buffer(stdscr->_swapbuffer[SWAPBUFFER_BACK], ' ');

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

int
wrefresh			(WINDOW *window)
{
	_swapbuffer_swap(&(window->_swapbuffer[SWAPBUFFER_FRONT]),&(window->_swapbuffer[SWAPBUFFER_BACK]));

	//This function call is essential
	SetConsoleActiveScreenBuffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT]);

	if(_cursor_sync(window)==ERR)
		return ERR;

	CHAR_INFO *_tmp_data = (CHAR_INFO*)malloc(sizeof(CHAR_INFO)*window->_size._x*window->_size._y);
	if(_tmp_data==NULL)
		return ERR;

	SMALL_RECT _reg = { window->_beg._x,window->_beg._y,(window->_beg._x) + (window->_size._x) - 1,(window->_beg._y) + (window->_size._y) - 1 };
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

int
addnstr				(const char *input,int n)
{
	return waddnstr(stdscr,input,n);
}

int
waddstr				(WINDOW *window, const char *input)
{
	return waddnstr(window, input, -1);
}

int
waddnstr			(WINDOW *window,const char *input,int n)
{
	size_t _strlen_chstr = strlen(input);
	DWORD _written_length;
	if (!WriteConsole(window->_swapbuffer[SWAPBUFFER_BACK],input, ((n == -1) || (n > _strlen_chstr)) ? _strlen_chstr : n, &_written_length, NULL))
		return ERR;
	return OK;
}

int
mvaddstr			(int y,int x,const char *input)
{
	return mvwaddstr(stdscr, y, x, input);
}

int
mvaddnstr			(int y,int x,const char *input,int n)
{
	return mvwaddnstr(stdscr, y, x, input, n);
}

int
mvwaddstr			(WINDOW *window,int y,int x,const char *input)
{
	return mvwaddnstr(window, y, x, input, -1);
}

int
mvwaddnstr			(WINDOW *window, int y, int x, const char *input, int n)
{
	if(wmove(window,y,x)==ERR)
		return ERR;
	return waddnstr(window, input, n);
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
	return OK;
}

int					
addchstr			(const chtype *chstr)
{
	return waddchstr(stdscr, chstr);
}

int
addchnstr			(const chtype *chstr, int n)
{
	return waddchnstr(stdscr, chstr, n);
}

int					
waddchstr			(WINDOW *window, const chtype *chstr)
{
	return waddchnstr(window, chstr,-1);
}

//-------------------------ATTENTION!----------if the chtype is unicode the strlen should change toe the wstrlen
int					
waddchnstr			(WINDOW *window, const chtype *chstr, int n)
{
	size_t _strlen_chstr = strlen(chstr);
	DWORD _length_written;
	//The reason why I don't use the WriteConsoleInput() function is 
	//it's behavior when the string exceeds the row is different from the what we want.
	//It will cast a lot more time to fix it.
	if (!WriteConsole(window->_swapbuffer[SWAPBUFFER_BACK], chstr, ((n == -1) || (n > _strlen_chstr)) ? _strlen_chstr : n, &_length_written, NULL))
		return ERR;
	return OK;
}

int
mvaddchstr			(int y, int x, const chtype *chstr)
{
	return mvwaddchstr(stdscr, y, x, chstr);
}

int
mvaddchnstr			(int y, int x, const chtype *chstr, int n)
{
	return mvwaddchnstr(stdscr, y, x, chstr, n);
}

int
mvwaddchstr			(WINDOW *window, int y, int x, const chtype *chstr)
{
	return mvwaddchnstr(window, y, x, chstr, -1);
}

int
mvwaddchnstr		(WINDOW *window, int y, int x, const chtype *chstr, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return waddchnstr(window,chstr,n);
}

int
baudrate			(void)
{
	//It seems that there is no baud rate in windows terminal? I am uncertain.
	return -1;
}

int 
beep				(void)
{
	/*In Windows 7, 
	Beep was rewritten to pass the beep to the default sound device for the session. 
	This is normally the sound card, except when run under Terminal Services, 
	in which case the beep is rendered on the client.*/
	if(!Beep(750, 300))
		return ERR;
	return OK;
}

int
bkgd				(chtype input)
{
	return wbkgd(stdscr,input);
}

int
wbkgd				(WINDOW *window, chtype input)
{
	//from the test in my raspberry pi 
	//found serveral interesting things
	//Firstly,the bkgd function instantly, which means that the function modifies the front buffer, 
	//and more interestingly this function have the effet of refresh , if we print something before the bkgd function but don't refresh, 
	//the things printed will be presented, which can be tested in the test_bkgd file
	//Secondly, this function was implemented interestingly. There is a background char in the WINDOW struct.
	//This function scan the whole screen and change the every char same as the _bkgd_ch to the input.

	int _tmp_data_length = window->_size._x*window->_size._y;
	TCHAR *_tmp_data = (TCHAR*)malloc(sizeof(TCHAR)*_tmp_data_length);
	if(_tmp_data==NULL)
		return ERR;

	//get chars
	SMALL_RECT _reg = { window->_beg._x,window->_beg._y,(window->_beg._x) + (window->_size._x),(window->_beg._y) + (window->_size._y) };
	ReadConsoleOutput(
		window->_swapbuffer[SWAPBUFFER_BACK], 
		_tmp_data, 
		_coord_create(window->_size._y,window->_size._x),
		_coord_create(0,0),
		&_reg
	);

	//change chars
	for(int i=0;i<_tmp_data_length;++i)
		if(_tmp_data[i]==window->_bkgd_ch)
			_tmp_data[i]=input;

	//write chars
	WriteConsoleOutput(
		window->_swapbuffer[SWAPBUFFER_BACK], 
		_tmp_data, 
		_coord_create(window->_size._y,window->_size._x),
		_coord_create(0,0),
		&_reg
	);

	window->_bkgd_ch = input;

	wrefresh(window);

	return OK;
}
extern	
int
border				(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br)
{
	return wborder(stdscr, ls, rs, ts, bs, tl, tr, bl, br);
}

//the init val havent been set
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
wborder				(WINDOW *window, chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br)
{
	COORD_S _tmp_cur_pos = window->_cur;
	//top line
	wmove(window, 0, 0);
	waddch(window, tl);
	for (int x = 1; x < window->_size._x - 1; ++x)
		waddch(window, ts);
	waddch(window, tr);

	//bottom line
	wmove(window, window->_size._y - 1, 0);
	waddch(window, bl);
	for (int x = 1; x < window->_size._x - 1; ++x)
		waddch(window, bs);
	waddch(window, br);

	//both sides
	for (int y = 1; y < window->_size._y - 1; ++y){
		mvwaddch(window, y, 0, ls);
		mvwaddch(window, y, window->_size._x - 1, rs);
	}

	wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x);
	return OK;
}

int 
box					(WINDOW *window,chtype verch,chtype horch)
{
	return wborder(window, verch, verch, horch, horch, 0, 0, 0, 0);
}

int
flash				(void)
{
	HANDLE _white_console_buffer = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	if(!SetConsoleScreenBufferSize(_white_console_buffer,_coord_create(stdscr->_size._y,stdscr->_size._x)))
		return ERR;
	_clear_buffer(_white_console_buffer,'B');
	SetConsoleActiveScreenBuffer(_white_console_buffer);
	Sleep(100);
	SetConsoleActiveScreenBuffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT]);
	CloseHandle(_white_console_buffer);
	return OK;
}

int
can_change_color	(void)
{
	//can definitely change color definition
	return OK;
}

int
hline				(chtype ch, int n)
{
	return whline(stdscr,ch,n);
}

int
mvhline				(int y, int x, chtype ch, int n)
{
	if (move(y, x) == ERR)
		return ERR;
	return hline(ch, n);
}

int
whline				(WINDOW *window, chtype ch, int n)
{
	COORD_S _tmp_cur_pos = window->_cur;
	int _length = MIN(n, (window->_size._x) - (window->_cur._x) + 1);
	for (int i = 0; i < _length; ++i)
	 	if(waddch(window,ch) == ERR)
			return ERR;
	return wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x);
}

int
mvwhline			(WINDOW *window, int y, int x, chtype ch, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return whline(window,ch,n);
}

int
vline				(chtype ch, int n)
{
	return wvline(stdscr, ch, n);
}

int
mvvline				(int y, int x, chtype ch, int n)
{
	if (move(y, x) == ERR)
		return ERR;
	return vline(ch, n);
}

int
wvline				(WINDOW *window, chtype ch, int n)
{
	COORD_S _tmp_cur_pos = window->_cur;
	for (int i = _tmp_cur_pos._y; i < MIN(_tmp_cur_pos._y + n - 1, window->_size._y); ++i)
		mvwaddch(window, i, _tmp_cur_pos._x, ch);
	wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x);
	return OK;
}

int 
mvwvline			(WINDOW *window, int y, int x, chtype ch, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return wvline(window, ch, n);
}

int
curs_set			(int input)
{
	//not every window has a state, so I dont place the state in the WINDOW struct
	//I let the windows to store the cursor state
	CONSOLE_CURSOR_INFO _tmp_cur_info;
	if(!GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &_tmp_cur_info))
		return ERR;
	if (input == 0)
		_tmp_cur_info.bVisible = FALSE;
	if (input == 1){
		_tmp_cur_info.bVisible = TRUE;
		_tmp_cur_info.dwSize = 1;
	}
	if (input == 2){
		_tmp_cur_info.bVisible = TRUE;
		_tmp_cur_info.dwSize = 100;
	}
	if(!SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &_tmp_cur_info))
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
	_clear_buffer(window->_swapbuffer[SWAPBUFFER_BACK], ' ');
	return wrefresh(window);
}

int
erase				(void)
{
	return werase(stdscr);
}

int
werase				(WINDOW *window)
{
	return wclear(window);
}

int
clrtobot			(void)
{
	return wclrtobot(stdscr);
}

int
clrtoeol			(void)
{
	return wclrtoeol(stdscr);
}

//these two functions take effect instantly
int
wclrtobot			(WINDOW *window)
{
	COORD_S _tmp_cur_pos = window->_cur;

	DWORD _written_length;

	FillConsoleOutputCharacter(
		GetStdHandle(STD_OUTPUT_HANDLE),
		//whether should I change to the window->_bkgd_ch
		' ',
		(window->_size._y) - (_tmp_cur_pos._y),
		_coord_create(_tmp_cur_pos._y, _tmp_cur_pos._x),
		&_written_length
	);

	if(wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x) == ERR)
		return ERR;
	return OK;
}

int
wclrtoeol			(WINDOW *window)
{
	COORD_S _tmp_cur_pos = window->_cur;

	if(wmove(window,_tmp_cur_pos._y, 0) == ERR)
		return ERR;
	
	for(int i=0;i<window->_size._x;++i)
		if (addch(' ') == ERR)
			return ERR;

	if (wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x) == ERR)
		return ERR;
	return OK;
}

int
getch				(void)
{
	char _input = 0;
	refresh();
	return _input; 
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
	_tmp = *a;
	*a = *b;
	*b = _tmp;
}

inline BOOL
_clear_buffer		(HANDLE buffer, chtype input)
{
	CONSOLE_SCREEN_BUFFER_INFO _buffer_info;
	if (!GetConsoleScreenBufferInfo(buffer, &_buffer_info))
		return FALSE;
	DWORD _length = (DWORD)(
		(_buffer_info.srWindow.Bottom - _buffer_info.srWindow.Top + 1)
		*
		(_buffer_info.srWindow.Right - _buffer_info.srWindow.Left + 1)
		);
	//unused
	DWORD _length_written;
	if (!FillConsoleOutputCharacter(buffer, input, _length, _coord_create(0, 0), &_length_written))
		return FALSE;
	return TRUE;
}

BOOL
_cursor_sync		(WINDOW *window)
{
	return SetConsoleCursorPosition(window->_swapbuffer[SWAPBUFFER_BACK], _coord_create(window->_cur._y, window->_cur._x));
}