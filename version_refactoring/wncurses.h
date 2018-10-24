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

#define ACS_VLINE			'|'
#define ACS_HLINE			'-'
#define ACS_ULCORNER		'©°'
#define ACS_URCORNER		'©´'
#define ACS_BLCORNER		'©¸'
#define ACS_BRCORNER		'©¼'


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

#define LINES stdscr->_size.Y
#define COLS stdscr->_size.X

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
extern	int erase (void);
extern	int werase (WINDOW *window);
extern	int printw (const char *input, ...);
extern	int mvprintw (int y, int x, const char *input, ...);
extern	int wprintw (WINDOW *window, const char *input, ...);
extern	int mvwprintw (WINDOW *window, int y, int x, const char *input, ...);
extern	int move (int y, int x);
extern	int wmove (WINDOW *window, int y, int x);
extern	int getch (void);
extern	int wgetch (WINDOW *window);

#endif