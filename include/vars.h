#pragma once

#include "wncurses.h" // for WINDOW
#include <windows.h> // for COORD

extern WINDOW*  stdscr;
extern HANDLE   console_buffer;
extern COORD    console_buffer_size;
extern BOOL     _echo;

extern void _vars_reset(void);
extern int getcurx (const WINDOW *window);
extern int getcury (const WINDOW *window);
extern int getbegx (const WINDOW *window);
extern int getbegy (const WINDOW *window);
extern int getmaxx (const WINDOW *window);
extern int getmaxy (const WINDOW *window);
extern int getparx (const WINDOW *window);
extern int getpary (const WINDOW *window);
extern chtype getbkgd (const WINDOW *window);
extern int echo (void);
extern int noecho (void);