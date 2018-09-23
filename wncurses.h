#ifndef __WNCURSES_H
#define __WNCURSES_H

#include<Windows.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERR 0

#define SWAPBUFFER_FRONT	0
#define SWAPBUFFER_BACK		1

#define ACS_VLINE			'|'
#define ACS_HLINE			'-'
#define ACS_ULCORNER		'┌'
#define ACS_URCORNER		'┐'
#define ACS_BLCORNER		'└'
#define ACS_BRCORNER		'┘'


//The Windows console only provides 3 bits for colors
#define _COLOR_RED			FOREGROUND_RED
#define _COLOR_GREEN		FOREGROUND_GREEN
#define _COLOR_BLUE			FOREGROUND_BLUE
#define _COLOR_YELLOW		(FOREGROUND_RED | FOREGROUND_GREEN)
#define _COLOR_MAGENTA		(FOREGROUND_BLUE | FOREGROUND_RED)
#define _COLOR_CYAN			(FOREGROUND_GREEN | FOREGROUND_BLUE)
#define _COLOR_BLACK		0
#define _COLOR_WHITE		(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define	LINES	(stdscr->_size._y)
#define COLS	(stdscr->_size._x)

typedef int						bool;
typedef	unsigned				chtype;
//coord short
typedef struct	_coord_s_st		COORD_S;
typedef struct	_window_st		WINDOW;

struct _coord_s_st{
	//the underscore means the val is private(cannot be accessed by outside world)
	short _x;
	short _y;
};

struct _window_st{
    //beg coord means the upper left corner 
	COORD_S		_cur, _beg, _par, _size;

	WINDOW		*_parent;

	WORD		_cur_color;

	chtype		_bkgd;

	//short		_bkgd_attr;

	//Input delay
	bool		_delay;

	//Output delay
	bool		_immed;

	bool		_use_keypad;

	//bool		_clear;			/* consider all data in the window invalid? */

    //the former is the front buffer
	HANDLE		_swapbuffer[2];

    /* option values set by user */
	//bool		_notimeout;		/* no time out on function-key entry? */
	bool		_leaveok;		/* OK to not reset cursor on exit? */
	//bool		_scroll;		/* OK to scroll this window? */
	//bool		_idlok;			/* OK to use insert/delete line? */
	//bool		_idcok;			/* OK to use insert/delete char? */
	//bool		_sync;			/* window in sync mode? */
	//bool		_use_keypad;	/* process function keys into KEY_ symbols? */
	//bool		_immed;			/* window in immed mode? (not yet used) */
	//int		_delay;		/* 0 = nodelay, <0 = blocking, >0 = delay */
};

/*
extern	int		COLS;
extern	int		LINES;
*/
extern  WINDOW  *stdscr;
extern	int		COLORS;
extern	int		COLOR_PAIRS;

extern  WINDOW*	initscr			(void);
extern	WINDOW* newwin			(int, int, int, int);
extern	int		delwin			(WINDOW *);
extern	int		mvwin			(WINDOW *, int, int);
extern	int		endwin			(void);
extern	bool	isendwin		(void);
extern	int		refresh			(void);
extern	int		wrefresh(WINDOW *);
extern	int		wnoutrefresh	(WINDOW *);
extern	int		doupdate		(void);
extern	int		redrawwin		(WINDOW *);
extern	int		wredrawwin		(WINDOW *, int, int);
extern	int		addch			(chtype);
extern	int		waddch			(WINDOW *, chtype);
extern	int		mvaddch			(int, int, chtype);
extern	int		mvwaddch		(WINDOW *, int, int, chtype);
extern	int		addstr			(const char *);
extern	int		addnstr			(const char *, int);
extern	int		waddstr			(WINDOW *, const char*);
extern	int		waddnstr		(WINDOW *, const char*,int);
extern	int		mvaddstr		(int, int, const char*);
extern	int		mvaddnstr		(int, int, const char*, int);
extern	int		mvwaddstr		(WINDOW *, int, int, const char*);
extern	int		mvwaddnstr		(WINDOW *, int, int, const char*, int);
extern	int		move			(int, int);
extern	int		wmove			(WINDOW*, int, int);
extern	int		addchstr		(const chtype *);
extern	int		addchnstr		(const chtype *, int);
extern	int		waddchstr		(WINDOW *, const chtype *);
extern	int		waddchnstr		(WINDOW *, const chtype *, int);
extern	int		mvaddchstr		(int, int, const chtype *);
extern	int		mvaddchnstr		(int, int, const chtype *, int);
extern	int		mvwaddchstr		(WINDOW *, int, int, const chtype *);
extern	int		mvwaddchnstr	(WINDOW *, int, int, const chtype *, int);
extern	int		printw			(const char*,...);
extern	int		mvprintw		(int, int, const char *,...);
extern	int		wprintw			(WINDOW *, const char *,...);
extern	int		mvwprintw		(WINDOW *, int, int, const char *,...);
extern	int		baudrate		(void);
extern	int		beep			(void);
extern	int		bkgd			(chtype);
extern	int		wbkgd			(WINDOW *, chtype);
extern	void	bkgdset			(const chtype ch);
extern	void	wbkgdset		(WINDOW *, const chtype);
extern	int		border			(chtype, chtype, chtype, chtype, chtype, chtype, chtype, chtype);
extern	int		wborder			(WINDOW *, chtype, chtype, chtype, chtype, chtype, chtype, chtype, chtype);
extern	int		box				(WINDOW *, chtype, chtype);
extern	int		flash			(void);
extern	int		hline			(chtype, int);
extern	int		vline			(chtype, int);
extern	int		whline			(WINDOW *, chtype, int);
extern	int		wvline			(WINDOW *, chtype, int);
extern	int		mvhline			(int, int, chtype, int);
extern	int		mvvline			(int, int, chtype, int);
extern	int		mvwhline		(WINDOW *,int, int, chtype, int);
extern	int		mvwvline		(WINDOW *,int, int, chtype, int);
extern	int		curs_set		(int);
extern	int		clear			(void);
extern	int		wclear			(WINDOW *);
extern	int		clearok			(WINDOW *, bool);
extern	int		erase			(void);
extern	int		werase			(WINDOW *);
extern	int		clrtobot		(void);
extern	int		clrtoeol		(void);
extern	int		wclrtobot		(WINDOW *);
extern	int		wclrtoeol		(WINDOW *);
//getch has the effect of refresh
extern	int		getch			(void);
extern	int		wgetch			(WINDOW *window);
extern	int		instr			(char *);
extern	int		innstr			(char *, int n);
extern	int		winstr			(WINDOW *, char *);
extern	int		winnstr			(WINDOW *, char *, int n);
extern	int		mvinstr			(int y, int x, char *);
extern	int		mvinnstr		(int y, int x, char *, int n);
extern	int		mvwinstr		(WINDOW *, int y, int x, char *);
extern	int		mvwinnstr		(WINDOW *, int y, int x, char *, int n);
extern	int		mvcur			(int, int, int, int);
//The 8 functions below are defined in the ncurses.h but can't be found in Linux man page
extern	int		getcurx			(const WINDOW *);
extern	int		getcury			(const WINDOW *);
extern	int		getbegx			(const WINDOW *);
extern	int		getbegy			(const WINDOW *);
extern	int		getmaxx			(const WINDOW *);
extern	int		getmaxy			(const WINDOW *);
extern	int		getparx			(const WINDOW *);
extern	int		getpary			(const WINDOW *);
extern	chtype	getbkgd			(WINDOW *);
extern	int		delch			(void);
extern	int		wdelch			(WINDOW *);
extern	int		mvdelch			(int, int);
extern	int		mvwdelch		(WINDOW *, int, int);
extern	int		start_color		(void);
extern	bool	has_colors		(void);
extern	bool	can_change_color(void);
extern	int		init_pair		(short, short, short);
extern	int		init_color		(short, short, short, short);
extern	int		color_content	(short, short *, short *, short *);
extern	int		pair_content	(short, short *, short *);
extern	int		echo			(void);
extern	int		noecho			(void);
extern	int		deleteln		(void);
extern	int		wdeleteln		(WINDOW *);
extern	int		insertln		(void);
extern	int		winsertln		(WINDOW *);
extern	int		insdelln		(int);
extern	int		winsdelln		(WINDOW *, int);
extern	bool	has_ic			(void);
extern	bool	has_il			(void);
extern	char	erasechar		(void);
extern	int		erasewchar		(wchar_t *);
extern	int		putwin			(WINDOW *, FILE *);
extern	WINDOW*	getwin			(FILE *);
extern	int		idlok			(WINDOW *, bool);
extern	void	idcok			(WINDOW *, bool);
extern	void	immedok			(WINDOW *, bool);
extern	chtype	inch			(void);
extern	chtype	winch			(WINDOW *);
extern	chtype	mvinch			(int, int);
extern	chtype	mvwinch			(WINDOW *, int, int);
extern	int		insch			(chtype);
extern	int		winsch			(WINDOW *, chtype);
extern	int		mvinsch			(int, int, chtype);
extern	int		mvwinsch		(WINDOW *, int, int, chtype);
extern	int		insstr			(const char *);
extern	int		insnstr			(const char *, int);
extern	int		winsstr			(WINDOW *, const char *);
extern	int		winsnstr		(WINDOW *, const char *, int);
extern	int		mvinsstr		(int, int, const char *);
extern	int		mvinsnstr		(int, int, const char *, int);
extern	int		mvwinsstr		(WINDOW *, int, int, const char *);
extern	int		mvwinsnstr		(WINDOW *, int, int, const char *, int);
extern	int		intrflush		(WINDOW *, bool);
extern	int		keypad			(WINDOW *, bool);
extern	int		leaveok			(WINDOW *, bool);
extern	int		scanw			(const char *, ...);
extern	int		wscanw			(WINDOW *, const char *, ...)





#endif