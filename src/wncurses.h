#pragma once

#ifndef __WNCURSES_H
#define __WNCURSES_H

#ifdef __cplusplus
extern "C" {
#endif

#include<windows.h>

#define TRUE 1
#define FALSE 0
#define OK 0
#define ERR -1

#define SWAPBUFFER_FRONT	0
#define SWAPBUFFER_BACK		1

#define ACS_VLINE			L'��'
#define ACS_HLINE			L'��'
#define ACS_ULCORNER		L'��'
#define ACS_URCORNER		L'��'
#define ACS_BLCORNER		L'��'
#define ACS_BRCORNER		L'��'


typedef int BOOL;
typedef unsigned chtype;
typedef struct _window WINDOW;
struct _window {
    COORD _pos;
	COORD _size;
	COORD _cur;
	chtype _bkgd_ch;
	// used in CHAR_INFO.Attribute
	WORD _bkgd_color;    
	// if delay is negative, blocking read is used.
	// if delay is zero, nonblocking read is used.
	// if delay is positive, the read will wait for _delay ms.
	int _delay; 
	BOOL _immed;
	BOOL _keypad;
	BOOL _leaveok;
    CHAR_INFO *_buffer;
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
extern	int mvaddstr (int y, int x, const char *input);
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
extern	int whline (WINDOW *window, chtype ch, int n);
extern	int vline (chtype ch, int n);
extern	int wvline (WINDOW *window, chtype ch, int n);
extern	int mvhline (int y, int x, chtype ch, int n);
extern	int mvvline (int y, int x, chtype ch, int n);
extern	int mvwhline (WINDOW *window, int y, int x, chtype ch, int n);
extern	int mvwvline (WINDOW *window, int y, int x, chtype ch, int n);
//instr() is different from insstr(). XD
extern	int instr (char *output);
extern	int innstr (char *output, int n);
extern	int winstr (WINDOW *window, char *output);
extern	int winnstr (WINDOW *window, char *output, int n);
extern	int mvinstr (int y, int x, char *input);
extern	int mvinnstr (int y, int x, char *input, int n);
extern	int mvwinstr (WINDOW *, int y, int x, char *input);
extern	int mvwinnstr (WINDOW *, int y, int x, char *input, int n);

extern	int delch (void);
extern	int wdelch (WINDOW *window);
extern	int mvdelch (int y, int x);
extern	int mvwdelch (WINDOW *window, int y, int x);
extern	int deleteln (void);
extern	int wdeleteln (WINDOW *window);
extern	int insertln (void);
extern	int winsertln (WINDOW *window);
extern	int insdelln (int n);
extern	int winsdelln (WINDOW *window, int n);

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
extern	int mvcur (int oldrow, int oldcol, int newrow, int newcol);

extern	int getch (void);
extern	int wgetch (WINDOW *window);


extern	int clearok (WINDOW *window, BOOL n);
extern	int baudrate (void);
extern	int mvwin (WINDOW *window, int y, int x);
extern	int wnoutrefresh (WINDOW *window);
extern	int doupdate (void);
extern	int redrawwin (WINDOW *window);
extern	int wredrawln (WINDOW *window, int beg_line, int num_lines);
extern	int start_color(void);
extern	BOOL has_colors(void);
extern	BOOL can_change_color(void);
extern	int init_pair (short pair, short f, short b);
extern	int init_color (short color, short r, short g, short b);
extern	int color_content (short color, short *r, short *g, short *b);
extern	int pair_content (short pair, short *f, short *b);

extern	int getcurx (const WINDOW *window);
extern	int getcury (const WINDOW *window);
extern	int getbegx (const WINDOW *window);
extern	int getbegy (const WINDOW *window);
extern	int getmaxx (const WINDOW *window);
extern	int getmaxy (const WINDOW *window);
extern	int getparx (const WINDOW *window);
extern	int getpary (const WINDOW *window);
extern	chtype getbkgd (const WINDOW *window);
extern	int echo (void);
extern	int noecho (void);
extern	void timeout(int delay);
extern	void wtimeout(WINDOW *window, int delay);

extern	int beep (void);

#ifdef __cplusplus
}
#endif

#endif