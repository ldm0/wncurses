#pragma once
#include"wncurses.h"



int _waddch_pure (WINDOW *window, chtype input);

int addch (chtype input);
int waddch (WINDOW* window, chtype input);
int mvaddch (int y, int x, chtype input);
int mvwaddch (WINDOW *window, int y, int x, chtype input);

int addstr (const char *input);
int addnstr (const char *input, int n);
int waddstr (WINDOW *window, const char *input);
int waddnstr (WINDOW *window, const char *input, int n);
int mvaddnstr (int y, int x, const char *input, int n);
int mvwaddstr (WINDOW *window, int y, int x, const char *input);
int mvwaddnstr (WINDOW *window, int y, int x, const char *input, int n);

int printw (const char *input, ...);
int mvprintw (int y, int x, const char *input, ...);
int wprintw (WINDOW *window, const char *input, ...);
int mvwprintw (WINDOW *window, int y, int x, const char *input, ...);

int border (chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br);
int wborder (WINDOW *window, chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br);
int box (WINDOW *window, chtype verch, chtype horch);
int flash (void);

int hline (chtype ch, int n);
int mvhline (int y, int x, chtype ch, int n);
int whline (WINDOW *window, chtype ch, int n);
int mvwhline (WINDOW *window, int y, int x, chtype ch, int n);
int vline (chtype ch, int n);
int mvvline (int y, int x, chtype ch, int n);
int wvline (WINDOW *window, chtype ch, int n);
int mvwvline (WINDOW *window, int y, int x, chtype ch, int n);

