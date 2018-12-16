#pragma once

#include"wncurses.h"

int instr (char *output);
int innstr (char *output, int n);
int winstr (WINDOW *window, char *output);
int winnstr (WINDOW *window, char *output, int n);
int mvinstr (int y, int x, char *input);
int mvinnstr (int y, int x, char *input, int n);
int mvwinstr (WINDOW *, int y, int x, char *input);
int mvwinnstr (WINDOW *, int y, int x, char *input, int n);
