#pragma once

#include"wncurses.h"

int clearok (WINDOW *window, BOOL n);
int baudrate (void);
int mvwin (void);
int wnoutrefresh (WINDOW *window);
int doupdate (void);
int redrawwin (WINDOW *window);
int wredrawln (WINDOW *window, int beg_line, int num_lines);
int start_color(void);
BOOL has_colors(void);
BOOL can_change_color(void);
int init_pair (short pair, short f, short b);
int init_color (short color, short r, short g, short b);
int color_content (short color, short *r, short *g, short *b);
int pair_content (short pair, short *f, short *b);