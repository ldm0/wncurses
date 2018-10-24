#pragma once

#include"wncurses.h"

int move (int y, int x);
int wmove (WINDOW *window, int y, int x);
int curs_set (int input);