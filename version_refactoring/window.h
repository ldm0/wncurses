#pragma once


WINDOW* newwin (int nlines, int ncols, int begin_y, int begin_x);
int delwin (WINDOW *window);
int refresh (void);
int wrefresh (WINDOW *window);
int _wrefresh_pure (WINDOW *window);