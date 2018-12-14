#include "wncurses.h"
#include "public_var.h"

WINDOW *stdscr;

void 
_public_var_reset(void)
{
	stdscr = NULL;
}

int
getcurx				(const WINDOW *window)
{
	if (!window)
		return ERR;
	return window->_cur.X;
}

int
getcury				(const WINDOW *window)
{
	if (!window)
		return ERR;
	return window->_cur.Y;
}

int
getbegx				(const WINDOW *window)
{
	if (!window)
		return ERR;
	return 0;
}

int
getbegy				(const WINDOW *window)
{
	if (!window)
		return ERR;
	return 0;
}

int
getmaxx				(const WINDOW *window)
{
	if (!window)
		return ERR;
	return window->_size.X;
}

int
getmaxy				(const WINDOW *window)
{
	if (!window)
		return ERR;
	return window->_size.Y;
}

int
getparx				(const WINDOW *window)
{
	//In windows command, 
	//we regard the parent window is the same as the child window.
	if (!window)
		return ERR;
	return 0;
}

int
getpary				(const WINDOW *window)
{
	if (!window)
		return ERR;
	return 0;
}

chtype
getbkgd				(const WINDOW *window)
{
	if (!window)
		return ERR;
	return window->_bkgd_ch;
}
