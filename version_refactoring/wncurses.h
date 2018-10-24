#pragma once

#ifndef __WNCURSES_H
#define __WNCURSES_H
#include<windows.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERR 0

#define SWAPBUFFER_FRONT	0
#define SWAPBUFFER_BACK		1

#define ACS_VLINE			L'©¦'
#define ACS_HLINE			L'©¤'
#define ACS_ULCORNER		L'©°'
#define ACS_URCORNER		L'©´'
#define ACS_BLCORNER		L'©¸'
#define ACS_BRCORNER		L'©¼'


typedef int BOOL;
typedef unsigned chtype;

typedef struct _window WINDOW;

struct _window {
	COORD _size;
	COORD _cur;
	WORD _cur_color;
	chtype _bkgd_ch;
	BOOL _delay;
	BOOL _immed;
	BOOL _keypad;
	BOOL _leaveok;
	HANDLE _swapbuffer[2];
};

extern WINDOW *stdscr;

#define LINES (stdscr->_size.Y)
#define COLS (stdscr->_size.X)


extern  WINDOW*	initscr (void);
extern	WINDOW* newwin (int nlines, int ncols, int begin_y, int begin_x);
extern	int endwin (void);
extern	int delwin (WINDOW *window);
extern	int refresh (void);
extern	int wrefresh (WINDOW *window);

extern	int addch (chtype input);
extern	int waddch (WINDOW* window, chtype input);
extern	int mvaddch (int y, int x, chtype input);
extern	int mvwaddch (WINDOW *window, int y, int x, chtype input);
extern	int addstr (const char *input);
extern	int addnstr (const char *input, int n);
extern	int waddstr (WINDOW *window, const char *input);
extern	int waddnstr (WINDOW *window, const char *input, int n);
extern	int mvaddnstr (int y, int x, const char *input, int n);
extern	int mvwaddstr (WINDOW *window, int y, int x, const char *input);
extern	int mvwaddnstr (WINDOW *window, int y, int x, const char *input, int n);
extern	int printw (const char *input, ...);
extern	int mvprintw (int y, int x, const char *input, ...);
extern	int wprintw (WINDOW *window, const char *input, ...);
extern	int mvwprintw (WINDOW *window, int y, int x, const char *input, ...);

extern	int border (chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br);
extern	int wborder (WINDOW *window, chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br);
extern	int box (WINDOW *window, chtype verch, chtype horch);

extern	int flash (void);
extern	int hline (chtype ch, int n);
extern	int mvhline (int y, int x, chtype ch, int n);
extern	int whline (WINDOW *window, chtype ch, int n);
extern	int mvwhline (WINDOW *window, int y, int x, chtype ch, int n);
extern	int vline (chtype ch, int n);
extern	int mvvline (int y, int x, chtype ch, int n);
extern	int wvline (WINDOW *window, chtype ch, int n);
extern	int mvwvline (WINDOW *window, int y, int x, chtype ch, int n);

extern	int erase (void);
extern	int werase (WINDOW *window);
extern	int clear (void);
extern	int wclear (WINDOW *window);
extern	int clrtobot (void);
extern	int wclrtobot (WINDOW *window);
extern	int clrtoeol (void);
extern	int wclrtoeol (WINDOW *window);
extern	int bkgd (chtype input);
extern	int wbkgd (WINDOW *window, chtype input);
extern	void bkgdset (const chtype input);
extern	void wbkgdset (WINDOW *window, const chtype input);

extern	int move (int y, int x);
extern	int wmove (WINDOW *window, int y, int x);
extern	int curs_set (int input);

extern	int getch (void);
extern	int wgetch (WINDOW *window);


extern	int clearok (WINDOW *window, BOOL n);
extern	int baudrate (void);

#endif