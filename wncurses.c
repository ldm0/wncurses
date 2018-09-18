#include <Windows.h>
//#include <stdio.h>
#include "wncurses.h"

typedef struct _screen _SCREEN;

struct _screen{
	/*actually the handles of swapbuffer in the window is unused*/
	CHAR_INFO		_chars[0];
};

//----------------public functions
WINDOW*				initscr				(void);
WINDOW*				newwin				(int nlines, int ncols, int begin_y, int begin_x);
int					delwin				(WINDOW *window);
int					mvwin				(WINDOW *window, int y, int x);
int					endwin				(void);
bool				isendwin			(void);
int					refresh				(void);
int					wrefresh			(WINDOW *window);
int					wnoutrefresh		(WINDOW *window);
int					doupdate			(void);
int					redrawwin			(WINDOW *window);
int					wredrawwin			(WINDOW *window, int beg_line, int num_lines);
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
int					printw				(const char *input,...);
int					mvprintw			(int y,int x,const char *input,...);
int					wprintw				(WINDOW *window, const char *input,...);
int					mvwprintw			(WINDOW *window, int y,int x,const char *input,...);
int					baudrate			(void);
int					beep				(void);
int					bkgd				(chtype input);
int					wbkgd				(WINDOW *window, chtype input);
void				bkgdset				(const chtype input);
void				wbkgdset			(WINDOW *window, const chtype input);
int					border				(chtype ls,chtype rs,chtype ts,chtype bs,chtype tl,chtype tr,chtype bl,chtype br);
int					wborder				(WINDOW *window, chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br);
int					box					(WINDOW *window, chtype verch, chtype horch);
int					flash				(void);
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
int					clearok				(WINDOW *window, bool n);
int					erase				(void);
int					werase				(WINDOW *window);
int					clrtobot			(void);
int					clrtoeol			(void);
int					wclrtobot			(WINDOW *window);
int					wclrtoeol			(WINDOW *window);
int					getch				(void);
int					wgetch				(WINDOW *window);
int					instr				(char *output);
int					innstr				(char *output, int n);
int					winstr				(WINDOW *window, char *output);
int					winnstr				(WINDOW *window, char *output, int n);
int					mvinstr				(int y, int x, char *);
int					mvinnstr			(int y, int x, char *, int n);
int					mvwinstr			(WINDOW *, int y, int x, char *);
int					mvwinnstr			(WINDOW *, int y, int x, char *, int n);
int					mvcur				(int oldrow, int oldcol, int newrow, int newcol);
int					getcurx				(const WINDOW *window);
int					getcury				(const WINDOW *window);
int					getbegx				(const WINDOW *window);
int					getbegy				(const WINDOW *window);
int					getmaxx				(const WINDOW *window);
int					getmaxy				(const WINDOW *window);
int					getparx				(const WINDOW *window);
int					getpary				(const WINDOW *window);
chtype				getbkgd				(WINDOW *window);
int					delch				(void);
int					wdelch				(WINDOW *window);
int					mvdelch				(int y, int x);
int					mvwdelch			(WINDOW *window, int y, int x);
int					start_color			(void);
bool				has_colors			(void);
bool				can_change_color	(void);
int					init_pair			(short pair, short f, short b);
int					init_color			(short color, short r, short g, short b);
int					color_content		(short color, short *r, short *g, short *b);
int					pair_content		(short pair, short *f, short *b);
int					echo				(void);
int					noecho				(void);
int					deleteln			(void);
int					wdeleteln			(WINDOW *window);
int					insertln			(void);
int					winsertln			(WINDOW *window);
int					insdelln			(int n);
int					winsdelln			(WINDOW *window, int n);
bool				has_ic				(void);
bool				has_il				(void);
char				erasechar			(void);
int					erasewchar			(wchar_t *ch);
int					putwin				(WINDOW *window, FILE *filep);
WINDOW *			getwin				(FILE *filep);
int					idlok				(WINDOW *window, bool n);
void				idcok				(WINDOW *window, bool n);
void				immedok				(WINDOW *window, bool n);



//-------------------private functions
inline	void		_public_var_reset	(void);
inline	void		_private_var_reset	(void);
inline	COORD		_coord_create		(short y, short x);
inline	void		_coord_s_init		(COORD_S *coord_s, short y, short x);
inline	void		_swapbuffer_swap	(HANDLE *a, HANDLE *b);
inline	BOOL		_clear_buffer		(HANDLE buffer,chtype input);
//set the real cursor position to the position stored in the window
inline	BOOL		_cursor_sync		(WINDOW *window);			
inline	short		_find_color			(int color);
int					_vwprintw			(WINDOW *window, const char *input, va_list args);
int					_waddch_noimmed		(WINDOW *window, chtype input, bool refresh);

//public vars
WINDOW		*stdscr;
int			COLORS;
int			COLOR_PAIRS;

//private vars
bool		_can_change_color;
bool		_echo;
int			*_colors;
long long	*_color_pairs;

WINDOW *
initscr				(void)
{
	_public_var_reset();
	_private_var_reset();

	SetConsoleCP(936);

	CONSOLE_SCREEN_BUFFER_INFO  console_info;

	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_info))
		exit(1);

	stdscr = newwin(
		console_info.srWindow.Bottom - console_info.srWindow.Top + 1,
		console_info.srWindow.Right - console_info.srWindow.Left + 1,
		console_info.srWindow.Top,
		console_info.srWindow.Left
	);
	if(!stdscr)
		exit(1);
	/*
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
		&(stdscr->_par),
		0,
		0
	);
	_coord_s_init(
		&(stdscr->_buffer_size),
		console_info.srWindow.Bottom - (stdscr->_beg._y) + 1,
		console_info.srWindow.Right - (stdscr->_beg._x) + 1
	);
	
	stdscr->_bkgd = ' ';

	stdscr->_cur_color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

	stdscr->_swapbuffer[SWAPBUFFER_FRONT] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
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
				_coord_create(stdscr->_buffer_size._y,stdscr->_buffer_size._x)
			)
			||
			!SetConsoleScreenBufferSize (
				stdscr->_swapbuffer[SWAPBUFFER_BACK],
				_coord_create(stdscr->_buffer_size._y,stdscr->_buffer_size._x)
			)
		)
		exit(1);
	_clear_buffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT], ' ');
	_clear_buffer(stdscr->_swapbuffer[SWAPBUFFER_BACK], ' ');
	*/

	if(!SetConsoleActiveScreenBuffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT]))
		exit(1);

	return stdscr;
}

WINDOW*
newwin				(int nlines, int ncols, int begin_y, int begin_x)
{
	WINDOW *_tmp_window = (WINDOW *)malloc(sizeof(WINDOW));
	if (_tmp_window == NULL)
		return NULL;

	_coord_s_init(
		&_tmp_window->_beg,
		begin_y,
		begin_x
	);
	_coord_s_init(
		&_tmp_window->_cur,
		0,
		0
	);
	_coord_s_init(
		&_tmp_window->_size,
		nlines,
		ncols
	);
	_coord_s_init(
		&_tmp_window->_par,
		0,
		0
	);

	_tmp_window->_bkgd = ' ';
	_tmp_window->_parent = NULL;
	_tmp_window->_cur_color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	_tmp_window->_delay = TRUE;
	_tmp_window->_immed = FALSE;
	//_tmp_window->_clear = FALSE;		//not needed

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
		return NULL;

	//The COORD is XY and the COORD_S IS yx so cannot be converted directly
	if (
			!SetConsoleScreenBufferSize (
				_tmp_window->_swapbuffer[SWAPBUFFER_FRONT],
				_coord_create(_tmp_window->_size._y, _tmp_window->_size._x)
			)
			||
			!SetConsoleScreenBufferSize (
				_tmp_window->_swapbuffer[SWAPBUFFER_BACK],
				_coord_create(_tmp_window->_size._y, _tmp_window->_size._x)
			)
		)
		return NULL;

	_clear_buffer(_tmp_window->_swapbuffer[SWAPBUFFER_FRONT], ' ');
	_clear_buffer(_tmp_window->_swapbuffer[SWAPBUFFER_BACK], ' ');

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
mvwin				(WINDOW *window, int y, int x)
{
	window->_beg._y = y;
	window->_beg._x = x;
	return OK;
}

int 
endwin				(void)
{
	delwin(stdscr);

	_public_var_reset();
	_private_var_reset();

	return OK;
}

bool
isendwin			(void)
{
	return stdscr == NULL;
}

int 
refresh				(void)
{
	return wrefresh(stdscr);
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
	if(_cursor_sync(window)==ERR)
		return ERR;

	_swapbuffer_swap(
		&(window->_swapbuffer[SWAPBUFFER_FRONT]),
		&(window->_swapbuffer[SWAPBUFFER_BACK]));

	//This function call is essential
	SetConsoleActiveScreenBuffer(
		stdscr->_swapbuffer[SWAPBUFFER_FRONT]);

	CHAR_INFO *_tmp_data = (CHAR_INFO *)malloc(
		window->_size._x*window->_size._y
		* sizeof(CHAR_INFO));
	if(!_tmp_data)
		return ERR;

	SMALL_RECT _reg = { 
		0, 0,
		window->_size._x - 1,
		window->_size._y - 1 };

	if (!ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_FRONT], 
		_tmp_data, 
		_coord_create(window->_size._y,window->_size._x),
		_coord_create(0,0),
		&_reg ))
		return ERR;
	if (!WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK], 
		_tmp_data, 
		_coord_create(window->_size._y,window->_size._x),
		_coord_create(0,0),
		&_reg))
		return ERR;

	free(_tmp_data);

	_tmp_data = NULL;

	return OK;
}

int
wnoutrefresh		(WINDOW *window)
{
	//The implementation is different;
	return OK;
}

int
doupdate			(void)
{
	return refresh();
}

int
redrawwin			(WINDOW *window)
{
	return wredrawwin(window, 0, window->_size._y);
}

int
wredrawwin			(WINDOW *window, int beg_line, int num_lines)
{
	return wrefresh(window);
}

int
addch				(chtype input)
{
	return waddch(stdscr,input);
}

int
waddch				(WINDOW* window, chtype input)
{
	if(!_waddch_noimmed(window, input))
		return ERR;
	if(window->_immed)
		if(!wrefresh(window))
			return ERR;
	return OK;
}

/*
The main fucking problem why I can't use this covinient function is
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

//finally I will make it MACRO
int
mvaddch				(int y, int x, chtype input)
{
	return mvwaddch(stdscr,y,x,input);
}

int
mvwaddch			(WINDOW *window, int y, int x, chtype input)
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
addnstr				(const char *input, int n)
{
	return waddnstr(stdscr,input,n);
}

int
waddstr				(WINDOW *window, const char *input)
{
	return waddnstr(window, input, -1);
}

/*
int
waddnstr			(WINDOW *window,const char *input,int n)
{
	size_t _strlen_chstr = strlen(input);
	DWORD _written_length;
	if (!WriteConsole(window->_swapbuffer[SWAPBUFFER_BACK],input, ((n == -1) || (n > _strlen_chstr)) ? _strlen_chstr : n, &_written_length, NULL))
		return ERR;
	return OK;
}
*/

int
waddnstr			(WINDOW *window, const char *input, int n)
{
	if (n == -1){
		for (int i = 0; input[i]; ++i)
			if (_waddch_noimmed(window, input[i]) == ERR)
				return ERR;
	}
	else
		for (int i = 0; i < n && input[i]; ++i)
			if (_waddch_noimmed(window, input[i]) == ERR)
				return ERR;
	if (window->_immed)
		if (!wrefresh(window))
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
	if(wmove(window,y,x)==ERR)
		return ERR;
	return waddnstr(window, input, n);
}

int
move				(int y, int x)
{
	return wmove(stdscr, y, x);
}

int 
wmove				(WINDOW *window, int y, int x)
{
	window->_cur._y = y;
	window->_cur._x = x;
	if (window->_immed)
		if (!wrefresh(window))
			return ERR;
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

int					
waddchnstr			(WINDOW *window, const chtype *chstr, int n)
{
	if (n == -1) {
		for (int i = 0; chstr[i]; ++i)
			if (_waddch_noimmed(window, chstr[i]) == ERR)
				return ERR;
	}
	else
		for (int i = 0; i < n && chstr[i]; ++i)
			if (_waddch_noimmed(window, chstr[i]) == ERR)
				return ERR;
	if (window->_immed)
		if (!wrefresh(window))
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
printw				(const char *input, ...)
{
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(stdscr, input, _args);
	va_end(_args);
	if (stdscr->_immed)
		if (!wrefresh(stdscr))
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
		if (!wrefresh(stdscr))
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
		if (!wrefresh(window))
			return ERR;
	return _result;
}

int
mvwprintw			(WINDOW *window, int y, int x, const char *input, ...)
{
	wmove(window , y, x);
	va_list _args;
	va_start(_args, input);
	int _result = _vwprintw(window, input, _args);
	va_end(_args);
	if (window->_immed)
		if (!wrefresh(window))
			return ERR;
	return _result;
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
	//This function scan the whole screen and change the every char same as the _bkgd to the input.

	int _tmp_data_length = window->_size._x*window->_size._y;
	CHAR_INFO *_tmp_data = (CHAR_INFO*)malloc(sizeof(CHAR_INFO)*_tmp_data_length);
	if(_tmp_data==NULL)
		return ERR;

	//get chars
	SMALL_RECT _reg = { 
		0, 0,
		window->_size._x - 1,
		window->_size._y - 1};
	ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK], 
		_tmp_data, 
		_coord_create(window->_size._y,window->_size._x),
		_coord_create(0,0),
		&_reg
	);

	//change chars
	for(int i=0;i<_tmp_data_length;++i)
		if (_tmp_data[i].Char.UnicodeChar == window->_bkgd){
			_tmp_data[i].Char.UnicodeChar = input;
		}


	//write chars
	WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK], 
		_tmp_data, 
		_coord_create(window->_size._y,window->_size._x),
		_coord_create(0,0),
		&_reg
	);

	free(_tmp_data);

	_tmp_data = NULL;

	window->_bkgd = input;

	if (window->_immed)
		if (!wrefresh(window))
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
	window->_bkgd = input;
}

int
border				(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br)
{
	return wborder(stdscr, ls, rs, ts, bs, tl, tr, bl, br);
}

//the default value havent been set
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
	if(!ls)
		ls = ACS_VLINE;
	if(!rs)
		rs = ACS_VLINE;
	if(!ts)
		ts = ACS_HLINE;
	if(!bs)
		bs = ACS_HLINE;
	if(!tl)
		tl = ACS_ULCORNER;
	if(!tr)
		tr = ACS_URCORNER;
	if(!bl)
		bl = ACS_BLCORNER;
	if(!br)
		br = ACS_BRCORNER;

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

	if (!wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x))
		return ERR;
	if (window->_immed)
		if (!wrefresh(window))
			return ERR;
	return OK;
}

int 
box					(WINDOW *window, chtype verch, chtype horch)
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
	if (window->_immed)
		if (!wrefresh(window))
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
		if (!mvwaddch(window, i, _tmp_cur_pos._x, ch))
			return ERR;
	if (!wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x))
		return ERR;
	if (window->_immed)
		if (!wrefresh(window))
			return ERR;
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
	if (!werase(window))
		return ERR;
	return clearok(window, TRUE);
}

int
clearok				(WINDOW *window, bool n)
{
	//not needed, this is windows, and the implementation is different
	//window->_clear = n;		
	return OK;
}

int
erase				(void)
{
	return werase(stdscr);
}

int
werase				(WINDOW *window)
{
	if (_clear_buffer(
		window->_swapbuffer[SWAPBUFFER_BACK],
		window->_bkgd) == FALSE)
		return ERR;
	if (window->_immed)
		if (!wrefresh(window))
			return ERR;
	return OK;
}

int
clrtobot			(void)
{
	return wclrtobot(stdscr);
}

int
wclrtobot			(WINDOW *window)
{
	COORD_S _tmp_cur_pos = window->_cur;

	DWORD _written_length;

	FillConsoleOutputCharacter(
		GetStdHandle(STD_OUTPUT_HANDLE),
		window->_bkgd,
		(window->_size._y) - (_tmp_cur_pos._y),
		_coord_create(_tmp_cur_pos._y, _tmp_cur_pos._x),
		&_written_length
	);

	if(wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x) == ERR)
		return ERR;
	if (window->_immed)
		if (!wrefresh(window))
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
	COORD_S _tmp_cur_pos = window->_cur;

	if (wmove(window, _tmp_cur_pos._y, 0) == ERR)
		return ERR;
	
	for(int i=0;i<window->_size._x;++i)
		if (waddch(window, window->_bkgd) == ERR)
			return ERR;

	if (wmove(window, _tmp_cur_pos._y, _tmp_cur_pos._x) == ERR)
		return ERR;
	if (window->_immed)
		if (!wrefresh(window))
			return ERR;
	return OK;
}

int
getch				(void)
{
	return wgetch(stdscr);
}

int
wgetch				(WINDOW *window)
{
	if(wrefresh(window) == ERR)
		return ERR;

	INPUT_RECORD _tmp_input_record;
	DWORD _read_events, _unread_events;
	do{
		if (window->_delay == FALSE){
			if (!GetNumberOfConsoleInputEvents(
				GetStdHandle(STD_INPUT_HANDLE),
				&_unread_events))
				return ERR;
			if (!_unread_events)
				return ERR;
		}

		if ( !ReadConsoleInput(
			GetStdHandle(STD_INPUT_HANDLE),
			&_tmp_input_record,
			1, 
			&_read_events))
			return ERR;
	} while ( _tmp_input_record.EventType != KEY_EVENT 
		||
		_tmp_input_record.Event.KeyEvent.bKeyDown == FALSE );

	if (_echo)	
		waddch(window, _tmp_input_record.Event.KeyEvent.uChar.UnicodeChar);

	if(wrefresh(window) == ERR)
		return ERR;

	return _tmp_input_record.Event.KeyEvent.uChar.UnicodeChar;
}

int
instr				(char *output)
{
	return winstr(stdscr, output);
}

int
innstr				(char *output, int n)
{
	return winnstr(stdscr, output, n);
}

int
winstr				(WINDOW *window, char *output)
{
	return winnstr(window, output, -1);
}

int
winnstr				(WINDOW *window, char *output, int n)
{
	DWORD _read_length;
	DWORD _tmp_length = (n == -1) ?
		window->_size._x - window->_cur._x
		:
		MIN(n, window->_size._x - window->_cur._x)
		;
	if (
		!ReadConsoleOutputCharacter(
			window->_swapbuffer[SWAPBUFFER_BACK],
			output,
			_tmp_length,
			_coord_create(window->_cur._y, window->_cur._x),
			&_read_length
		)
	)
		return ERR;
	return OK;
}

int
mvinstr				(int y, int x, char *output)
{
	return mvwinstr(stdscr, y, x, output);
}

int
mvinnstr			(int y, int x, char *output, int n)
{
	return mvwinnstr(stdscr, y, x, output, n);
}

int
mvwinstr			(WINDOW *window, int y, int x, char *output)
{
	return mvwinnstr(window, y, x, output, -1);
}

int
mvwinnstr			(WINDOW *window, int y, int x, char *output, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return winnstr(window, output, n);
}

int
mvcur				(int oldrow, int oldcol, int newrow, int newcol)
{
	stdscr->_cur._x += newcol - oldcol;
	stdscr->_cur._y += newrow - oldrow;
	if (stdscr->_immed)
		if (!wrefresh(stdscr))
			return ERR;
	return OK;
}

int
getcurx				(const WINDOW *window)
{
	return window->_cur._x;
}

int
getcury				(const WINDOW *window)
{
	return window->_cur._y;
}

int
getbegx				(const WINDOW *window)
{
	return window->_beg._x;
}

int
getbegy				(const WINDOW *window)
{
	return window->_beg._y;
}

int
getmaxx				(const WINDOW *window)
{
	return window->_beg._x+window->_size._x;
}

int
getmaxy				(const WINDOW *window)
{
	return window->_beg._y+window->_size._y;
}

int
getparx				(const WINDOW *window)
{
	return window->_par._x;
}

int
getpary				(const WINDOW *window)
{
	return window->_par._y;
}

chtype
getbkgd				(WINDOW *window)
{
	return window->_bkgd;
}

int
delch				(void)
{
	return wdelch(stdscr);
}

int
wdelch				(WINDOW *window)
{
	COORD _buffer_size = _coord_create(1, window->_size._x - window->_cur._x);
	SMALL_RECT _region = {
		window->_cur._x + 1,
		window->_cur._y,
		window->_size._x - 1,
		window->_cur._y};
	CHAR_INFO *_buffer = (CHAR_INFO *)malloc(_buffer_size.X * sizeof(CHAR_INFO));
	if (_buffer == NULL)
		return ERR;

	if (
		!ReadConsoleOutputW(
			window->_swapbuffer[SWAPBUFFER_BACK],
			_buffer,_buffer_size,
			_coord_create(0,0),
			&_region))
		return ERR;

	//the last cell of buffer is empty
	_buffer[_buffer_size.X - 1].Char.UnicodeChar = window->_bkgd;
	_buffer[_buffer_size.X - 1].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;

	_region.Left -= 1;
	if (!WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_buffer,_buffer_size,
		_coord_create(0, 0),
		&_region))
		return ERR;

	free(_buffer);

	_buffer = NULL;

	if (window->_immed)
		if (!wrefresh(window))
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
	if (!wmove(window, y, x))
		return ERR;
	return wdelch(window);
} 

int
start_color			(void)
{
	_can_change_color	= TRUE;

	//The Windows console only provide 3 bits for colors
	//So there are 8 colors and 8x8 color pairs
	COLORS				= 8;
	COLOR_PAIRS			= 64;

	_colors				= (int *)calloc(COLORS, sizeof(int));
	_color_pairs		= (long long *)calloc(COLOR_PAIRS, sizeof(long long));

	//The 3 bits is the rgb
	for (int i = 0; i < COLORS; ++i)
		_colors[i] = ((i & 0x1 << 3) >> 3 ? _COLOR_RED : 0)
			| ((i & 0x1 << 2) >> 2 ? _COLOR_GREEN : 0)
			| ((i & 0x1 << 1) >> 1 ? _COLOR_BLUE : 0);

	if (!_colors || !_color_pairs)
		return ERR;

	return OK;
}

bool
has_colors			(void)
{
	//The windows terminal definetely has the color
	return TRUE; 
}

bool
can_change_color	(void)
{
	return _can_change_color;
}

int
init_pair			(short pair, short f, short b)
{
	if (pair < 0 || pair >= COLOR_PAIRS)
		return ERR;
	if(
		f < 0 || b < 0
		||
		f >= COLORS || b >= COLORS
		)
		return ERR;

	//The lower 32 bits if background and the higher is foreground
	_color_pairs[pair] = _colors[b] | ((long long)_colors[f] << 32);

	return OK;
}

/*
The value of [rgb] is strictly between 0 to 1000.
But due to the poor color support of the console in MS Windows,
when the value of [rgb] exceeds the 100, 
the actual [rgb] of the color is set to 1,
or it will set to 0.
*/
int
init_color			(short color, short r, short g, short b)
{
	//clip
	if (
		r < 0 || g < 0 || b < 0 
		||
		r > 1000 || g > 1000 || b > 1000
		)
		return ERR;

	//Leaving two bit unused
	_colors[color] = r;
	_colors[color] <<= 4;
	_colors[color] |= g;
	_colors[color] <<= 4;
	_colors[color] |= b;
	_colors[color] <<= 4;

	/*
	the range of r,g,b is 0~1000 so Ichoose 100 as the boundary 
	_colors[color] = 
		(r < 100 ? 0 : FOREGROUND_RED)
		| 
		(g < 100 ? 0 : FOREGROUND_GREEN)
		|
		(b < 100 ? 0 : FOREGROUND_BLUE);
	*/

	return OK;
}

int
color_content		(short color, short *r, short *g, short *b)
{
	*r = (_colors[color] & (0x000003ff << 20)) >> 20;
	*g = (_colors[color] & (0x000003ff << 10)) >> 10;
	*b = _colors[color] & 0x000003ff;
	return OK;
}

int
pair_content		(short pair, short *f, short *b)
{
	short _tmp;
	_tmp = _find_color((_color_pairs[pair] & 0xffffffff00000000) >> 32);
	if (_tmp == -1) return ERR;
	*f = _tmp;
	_tmp = _find_color(_color_pairs[pair] & 0x00000000ffffffff);
	if (_tmp == -1) return ERR;
	*b = _tmp;
	return OK;
}

int
echo				(void)
{
	_echo = TRUE;
	return OK;
}

int
noecho				(void)
{
	_echo = FALSE;
	return OK;
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
		window->_size._y - window->_cur._y,
		window->_size._x);

	SMALL_RECT _region = { 
		0,
		window->_cur._y + 1,
		window->_size._x - 1,
		window->_size._y - 1 
	};

	CHAR_INFO *_buffer = (CHAR_INFO *)malloc(
		_buffer_size.Y * _buffer_size.X 
		* sizeof(CHAR_INFO));
	if(!_buffer)
		return ERR;

	if (!ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_buffer,_buffer_size,
		_coord_create(0,0),
		&_region))
		return ERR;

	for (int i = 0; i < window->_size._x; ++i) {
		//The attr will be replaced with window->_bkgd_attr in the future
		_buffer[_buffer_size.X*(_buffer_size.Y - 1) + i].Attributes = 
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		_buffer[_buffer_size.X*(_buffer_size.Y - 1) + i].Char.UnicodeChar = 
			window->_bkgd;
	}

	_region.Top -= 1;
	if (!WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_buffer,_buffer_size,
		_coord_create(0, 0),
		&_region))
		return ERR;
	free(_buffer);
	if (window->_immed)
		if (!wrefresh(window))
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
		window->_size._y - window->_cur._y,
		window->_size._x);

	SMALL_RECT _region = {
		0,
		window->_cur._y,
		window->_size._x - 1,
		window->_size._y - 2 };

	CHAR_INFO *_blank = (CHAR_INFO *)malloc(
		_buffer_size.X * _buffer_size.Y 
		* sizeof(CHAR_INFO));
	if (!_blank)
		return ERR;

	for (int i = 0; i < _buffer_size.X; ++i){
		_blank[i].Attributes=
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		_blank[i].Char.UnicodeChar=
			window->_bkgd;
	}

	if (!ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_blank,_buffer_size,
		_coord_create(1,0),
		&_region))
		return ERR;

	_region.Bottom += 1;
	if (!WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_blank,_buffer_size,
		_coord_create(0, 0),
		&_region))
		return ERR;

	free(_blank);

	if (window->_immed)
		if (!wrefresh(window))
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
	if(!n)
		return OK;
		
	//Basic clip.
	n = MIN(window->_size._y, n);
	n = MAX(-window->_size._y, n);

	//KISS
	//When I have time, I will optimize it.
	if(n>0){
		for(;n>0;--n)
			if (!winsertln(window))
				return ERR;
	}
	else
		for(;n<0;++n)
			if (!wdeleteln(window))
				return ERR;

	return OK;
}

bool
has_ic				(void)
{
	return TRUE;
}

bool
has_il				(void)
{
	return TRUE;
}

char
erasechar			(void)
{
	//backspace
	return 0x8;
}

int
erasewchar			(wchar_t *ch)
{
	*ch = 0x8;
	return OK;
}

//The raw api of file io in Windows is a little complex
//So temporily use posix function
//First store the window, then store the backbuffer
int
putwin				(WINDOW *window, FILE *filep)
{
	//Store window utils
	if (fwrite(window, sizeof(WINDOW), 1, filep) != 1)
		return ERR;

	//Store backbuffer
	size_t _screen_size = 
		window->_size._x * window->_size._y * sizeof(CHAR_INFO);
	_SCREEN *_tmp_screen = (_SCREEN *)malloc(_screen_size);
	if (!_tmp_screen)
		return ERR;
	SMALL_RECT _reg = {
		0, 0,
		window->_size._x - 1,
		window->_size._y - 1 };
	if(!ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_FRONT], 
		_tmp_screen,
		_coord_create(window->_size._y, window->_size._x),
		_coord_create(0,0),
		&_reg))
		return ERR;
	if (fwrite(_tmp_screen, _screen_size, 1, filep) != 1)
		return ERR;
	free(_tmp_screen);
	return OK;
}

WINDOW*
getwin				(FILE *filep)
{
	//Get window utils. (The two swapbuffer handles are invalid)
	WINDOW *_window = (WINDOW *)malloc(sizeof(WINDOW));
	if (fread(_window, sizeof(WINDOW), 1, filep) != 1)
		return NULL;
	//Get backbuffer
	size_t _screen_size = 
		_window->_size._y * _window->_size._x * sizeof(CHAR_INFO);
	_SCREEN *_tmp_screen = (_SCREEN *)malloc(_screen_size);
	if (!_tmp_screen)
		return NULL;
	if (fread(_tmp_screen, _screen_size, 1, filep) != 1)
		return NULL;

	//Reallocate the swapbuffer handle and copy the backbuffer in.
	HANDLE _tmp_handle = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	if(_tmp_handle == INVALID_HANDLE_VALUE)
		return NULL;
	_window->_swapbuffer[SWAPBUFFER_FRONT] = _tmp_handle;

	_tmp_handle = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	if(_tmp_handle == INVALID_HANDLE_VALUE)
		return NULL;
	_window->_swapbuffer[SWAPBUFFER_BACK] = _tmp_handle;

	//The COORD is XY and the COORD_S IS yx so cannot be converted directly
	if (
			!SetConsoleScreenBufferSize (
				_window->_swapbuffer[SWAPBUFFER_FRONT],
				_coord_create(_window->_size._y, _window->_size._x)
			)
			||
			!SetConsoleScreenBufferSize (
				_window->_swapbuffer[SWAPBUFFER_BACK],
				_coord_create(_window->_size._y, _window->_size._x)
			)
		)
		return NULL;

	SMALL_RECT _region={ 
		0, 0,
		_window->_size._x - 1,
		_window->_size._y - 1, };
	if (!WriteConsoleOutput(_window->_swapbuffer[SWAPBUFFER_FRONT],
		_tmp_screen->_chars,
		_coord_create(_window->_size._y,_window->_size._x),
		_coord_create(0, 0),
		&_region))
		return NULL;
	if (!WriteConsoleOutput(_window->_swapbuffer[SWAPBUFFER_BACK],
		_tmp_screen->_chars,
		_coord_create(_window->_size._y,_window->_size._x),
		_coord_create(0, 0),
		&_region))
		return NULL;

	return _window;
}

/*
MS Windows console doesn't have the hardware insert/delete function
So do nothing
*/
int
idlok				(WINDOW *window, bool n)
{
	return OK;
}

void
idcok				(WINDOW *window, bool n)
{
	return OK;
}

void
immedok				(WINDOW *window, bool n)
{
	window->_immed = n;
}





//-------------------private functions
inline	void
_public_var_reset	(void)
{
	stdscr				= NULL;
	COLORS				= 0;
	COLOR_PAIRS			= 0;
}

inline	void
_private_var_reset	(void)
{
	_can_change_color	= FALSE;
	_echo				= TRUE;
	_colors				= NULL;
	_color_pairs		= NULL;
}

inline	COORD
_coord_create		(short y, short x)
{
	COORD _tmp;
	_tmp.Y = y;
	_tmp.X = x;
	return _tmp;
}

inline	COORD_S
_coord_s_create		(short y, short x)
{
	COORD_S _tmp;
	_tmp._y = y;
	_tmp._x = x;
	return _tmp;
}

inline	void
_coord_s_init		(COORD_S *coord_s, short y, short x)
{
	coord_s->_y = y;
	coord_s->_x = x;
}

inline	void
_swapbuffer_swap	(HANDLE *a, HANDLE *b)
{
	//How to xor the void* type..... Temporily use the _tmp.
	HANDLE _tmp;
	_tmp = *a;
	*a = *b;
	*b = _tmp;
}

inline	BOOL
_clear_buffer		(HANDLE buffer, chtype input)
{
	CONSOLE_SCREEN_BUFFER_INFO _buffer_info;
	if (!GetConsoleScreenBufferInfo(buffer, &_buffer_info))
		return ERR;
	DWORD _length = (DWORD)(
		(_buffer_info.srWindow.Bottom - _buffer_info.srWindow.Top + 1)
		*
		(_buffer_info.srWindow.Right - _buffer_info.srWindow.Left + 1)
		);
	//unused
	DWORD _length_written;
	if (!FillConsoleOutputCharacter(buffer, input, _length, _coord_create(0, 0), &_length_written))
		return ERR;
	return OK;
}

inline	BOOL
_cursor_sync		(WINDOW *window) 
{
	if(!SetConsoleCursorPosition(window->_swapbuffer[SWAPBUFFER_BACK], _coord_create(window->_cur._y, window->_cur._x)))
		return ERR;
	return OK;
}

inline short
_find_color			(int color)
{
	if(!_can_change_color)
		return -1;
	for (int i = 0; i < COLORS; ++i)
		if(_colors[i] == color)
			return i;
	return -1;
}

int
_vwprintw			(WINDOW *window, const char *input, va_list args)
{
	char *_buffer = (char *)malloc(window->_size._x * window->_size._y * sizeof(char));
	if (!_buffer)
		return ERR;
	if (vsprintf_s(_buffer, window->_size._x * window->_size._y, input, args) < 0)
		return ERR;
	if (!waddstr(window, _buffer))
		return ERR;
	free(_buffer);
	return OK;
}

//The reason why use private function is the immed mode
//Functions like waddnstr may call waddch a lot of times.
//But is the window is in immed mode, we will do wreafresh repeatedly.
int
_waddch_noimmed				(WINDOW *window, chtype input)
{
	CHAR_INFO _input_ch;
	_input_ch.Char.UnicodeChar = input;
	_input_ch.Attributes = window->_cur_color;

	COORD _size = _coord_create(1, 1);
	COORD _begin = _coord_create(0, 0);
	SMALL_RECT _region = { 
		window->_cur._x,
		window->_cur._y,
		window->_cur._x + window->_size._x - 1,
		window->_cur._y + window->_size._y - 1
	};

	//Without the judgemet, actually the '\r' and '\n'can be print to the screen but seems like a square
	if (input == '\r')
		window->_cur._x = 0;
	else if (input == '\n'){
		window->_cur._y++;
		window->_cur._x = 0;
	}
	else {
		if (
			!WriteConsoleOutputW(
				window->_swapbuffer[SWAPBUFFER_BACK], 
				&_input_ch,
				_size, 
				_begin, 
				&_region
			)
		) {
			DWORD err_code = GetLastError();
			return ERR;
		}
		window->_cur._x = (window->_cur._x + 1) % (window->_size._x);
		window->_cur._y += (window->_cur._x == 0);
	}
}

