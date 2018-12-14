#include"wncurses.h"
#include"error.h"
#include"window.h"
#include"public_var.h"
#include"private_var.h"

WINDOW *
initscr				(void)
{
	_public_var_reset();
	_private_var_reset();

	CONSOLE_SCREEN_BUFFER_INFO  console_info;

	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_info))
		ERROR_LOG(cannot get console info!);

	stdscr = newwin(
		console_info.srWindow.Bottom - console_info.srWindow.Top + 1,
		console_info.srWindow.Right - console_info.srWindow.Left + 1,
		console_info.srWindow.Top,
		console_info.srWindow.Left
	);

	if (!stdscr)
		ERROR_LOG(cannot create the stdscr);

	if (!SetConsoleActiveScreenBuffer(stdscr->_swapbuffer[SWAPBUFFER_FRONT]))
		ERROR_LOG(cannot set the active screen buffer);

	return stdscr;
}

int
endwin				(void)
{
	delwin(stdscr);
	return OK;
}

BOOL
isendwin			(void)
{
	return stdscr == NULL;
}