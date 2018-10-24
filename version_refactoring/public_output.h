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
int erase (void);
int werase (WINDOW *window);
int printw (const char *input, ...);
int mvprintw (int y, int x, const char *input, ...);
int wprintw (WINDOW *window, const char *input, ...);
int mvwprintw (WINDOW *window, int y, int x, const char *input, ...);