#pragma once

#include"wncurses.h"

extern int clearok (WINDOW *window, BOOL n);
extern int baudrate (void);
extern int wnoutrefresh (WINDOW *window);
extern int start_color(void);
extern BOOL has_colors(void);
extern BOOL can_change_color(void);
extern int init_pair (short pair, short f, short b);
extern int init_color (short color, short r, short g, short b);
extern int color_content (short color, short *r, short *g, short *b);
extern int pair_content (short pair, short *f, short *b);