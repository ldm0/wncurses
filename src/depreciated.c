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
wnoutrefresh		(WINDOW *window)
{
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