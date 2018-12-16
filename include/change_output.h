#pragma once

#include "wncurses.h"

BOOL _buffer_clear (WINDOW *window, chtype input);
int bkgd (chtype input);
int wbkgd (WINDOW *window, chtype input);
void bkgdset (const chtype input);
void wbkgdset (WINDOW *window, const chtype input);

int erase (void);
int werase (WINDOW *window);
int clear (void);
int wclear (WINDOW *window);
int clrtobot (void);
int wclrtobot (WINDOW *window);
int clrtoeol (void);
int wclrtoeol (WINDOW *window);

int delch (void);
int wdelch (WINDOW *window);
int mvdelch (int y, int x);
int mvwdelch (WINDOW *window, int y, int x);
int deleteln (void);
int wdeleteln (WINDOW *window);
int insertln (void);
int winsertln (WINDOW *window);
int insdelln (int n);
int winsdelln (WINDOW *window, int n);

