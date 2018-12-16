#include"instr.h"
#include"coord.h"

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

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
	int _tmp_length = (n == -1) ?
		window->_size.X - window->_cur.X
		: MIN(n, window->_size.X - window->_cur.X);
    for (int i = 0; i < _tmp_length; ++i) 
        output[i] = window->_buffer[i].Char.AsciiChar;
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