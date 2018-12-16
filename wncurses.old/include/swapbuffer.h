#pragma once

#include"wncurses.h"


void _swapbuffer_swap (HANDLE *a, HANDLE *b);
BOOL _swapbuffer_clear (HANDLE buffer, chtype input);
int bkgd (chtype input);
int wbkgd (WINDOW *window, chtype input);
void bkgdset (const chtype input);
void wbkgdset (WINDOW *window, const chtype input);