#include "coord.h"
#include "vars.h"
#include <windows.h>

WINDOW*     stdscr;
HANDLE      console_buffer;
COORD       console_buffer_size;
BOOL        _echo;

void _vars_reset(void)
{
    console_buffer = NULL;
    _coord_init(&console_buffer_size, 0, 0);
    if (stdscr != NULL) {
        delwin(stdscr);
        stdscr = NULL;
    }
    _echo = TRUE;
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

int
echo				(void)
{
	_echo = TRUE;
	return OK;
}

int
noecho				(void)
{
	_echo = FALSE;
	return OK;
}

void timeout(int delay)
{
	stdscr->_delay = delay;
}

void wtimeout(WINDOW *window, int delay)
{
	window->_delay = delay;
}
