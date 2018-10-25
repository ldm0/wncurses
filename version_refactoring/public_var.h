#pragma once

extern WINDOW *stdscr;

void _public_var_reset(void);
int getcurx (const WINDOW *window);
int getcury (const WINDOW *window);
int getbegx (const WINDOW *window);
int getbegy (const WINDOW *window);
int getmaxx (const WINDOW *window);
int getmaxy (const WINDOW *window);
int getparx (const WINDOW *window);
int getpary (const WINDOW *window);
chtype getbkgd (const WINDOW *window);
int echo (void);
int noecho (void);