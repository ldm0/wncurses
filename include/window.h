#pragma once

#include "wncurses.h" //for WINDOW

extern WINDOW* initscr(void);
extern int endwin(void);
extern BOOL isendwin(void);
extern WINDOW* newwin (int nlines, int ncols, int begin_y, int begin_x);
extern int delwin (WINDOW *window);
extern int mvwin (WINDOW *window, int y, int x);
extern int refresh (void);
extern int wrefresh (WINDOW *window);
extern int redrawwin (WINDOW *window);
extern int doupdate (void);
extern int wredrawln (WINDOW *window, int beg_line, int num_lines);
extern int _wrefresh_raw (WINDOW *window);

