#pragma once

#include"wncurses.h"

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
