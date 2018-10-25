#include"get.h"
#include"utils.h"
#include"coord.h"

int
instr				(char *output)
{
	return winstr(stdscr, output);
}

int
innstr				(char *output, int n)
{
	return winnstr(stdscr, output, n);
}

int
winstr				(WINDOW *window, char *output)
{
	return winnstr(window, output, -1);
}

int
winnstr				(WINDOW *window, char *output, int n)
{
	DWORD _read_length;
	DWORD _tmp_length = (n == -1) ?
		window->_size.X - window->_cur.X
		: MIN(n, window->_size.X - window->_cur.X);
	if (!ReadConsoleOutputCharacter(
		window->_swapbuffer[SWAPBUFFER_BACK],
		output, _tmp_length,
		_coord_create(window->_cur.Y, window->_cur.X),
		&_read_length))
		return ERR;
	return OK;
}

int
mvinstr				(int y, int x, char *output)
{
	return mvwinstr(stdscr, y, x, output);
}

int
mvinnstr			(int y, int x, char *output, int n)
{
	return mvwinnstr(stdscr, y, x, output, n);
}

int
mvwinstr			(WINDOW *window, int y, int x, char *output)
{
	return mvwinnstr(window, y, x, output, -1);
}

int
mvwinnstr			(WINDOW *window, int y, int x, char *output, int n)
{
	if (wmove(window, y, x) == ERR)
		return ERR;
	return winnstr(window, output, n);
}

