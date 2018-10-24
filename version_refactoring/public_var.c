#include "wncurses.h"
#include "public_var.h"

WINDOW *stdscr = NULL;

void _public_var_reset(void)
{
	stdscr = NULL;
}