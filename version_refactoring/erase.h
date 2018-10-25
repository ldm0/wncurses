#pragma once

#include"wncurses.h"

int erase (void);
int werase (WINDOW *window);
int clear (void);
int wclear (WINDOW *window);
int clrtobot (void);
int wclrtobot (WINDOW *window);
int clrtoeol (void);
int wclrtoeol (WINDOW *window);
