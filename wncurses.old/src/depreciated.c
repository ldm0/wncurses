#include "depreciated.h"

int
clearok				(WINDOW *window, BOOL n)
{
	//not needed, this is windows, and the implementation is different
	//window->_clear = n;		
	return OK;
}


int
baudrate			(void)
{
	//It seems that there is no baudrate in windows command line? I am uncertain.
	return -1;
}

int
mvwin				(void)
{
	return OK;
}

int
wnoutrefresh		(WINDOW *window)
{
	return OK;
}

int
doupdate			(void)
{
	return OK;
}

int
redrawwin			(WINDOW *window)
{
	if (!window)
		return ERR;
	return OK;
}

int
wredrawln			(WINDOW *window, int beg_line, int num_lines)
{
	if (!window)
		return ERR;
	if (
		num_lines <= 0
		||
		beg_line + num_lines >= window->_size.Y)
		return ERR;
	return OK;
}

int
start_color			(void)
{
	return OK;
}

BOOL
has_colors			(void)
{
	//The windows terminal definitely has the color
	return TRUE;
}

BOOL
can_change_color	(void)
{
	return TRUE;
}

int
init_pair			(short pair, short f, short b)
{
	return OK;
}

int
init_color			(short color, short r, short g, short b)
{
	return OK;
}

int
color_content		(short color, short *r, short *g, short *b)
{
	if (!r || !g || !b)
		return ERR;
	return OK;
}

int
pair_content		(short pair, short *f, short *b)
{
	if (!f || !b)
		return ERR;
	return OK;
}