#pragma once

#include "wncurses.h" //for WINDOW

extern WINDOW* newwin (int nlines, int ncols, int begin_y, int begin_x);
extern int delwin (WINDOW *window);
extern int mvwin (WINDOW *window, int y, int x);
extern int refresh (void);
extern int wrefresh (WINDOW *window);
extern int _wrefresh_raw (WINDOW *window);
extern WINDOW* initscr(void);
extern int endwin(void);
extern BOOL isendwin(void);