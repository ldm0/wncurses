#include"erase.h"
#include"swapbuffer.h"
#include"coord.h"
#include"window.h"
#include"output.h"


int
erase				(void)
{
	return werase(stdscr);
}

int
werase				(WINDOW *window)
{
	if (_swapbuffer_clear(
		window->_swapbuffer[SWAPBUFFER_BACK],
		window->_bkgd_ch) == FALSE)
		return ERR;
	if (wmove(window, 0, 0))
		return ERR;
	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;
	return OK;
}

int
clear				(void)
{
	return wclear(stdscr);
}

int
wclear				(WINDOW *window)
{
	if (!werase(window))
		return ERR;
	return clearok(window, TRUE);
}

int
clrtobot			(void)
{
	return wclrtobot(stdscr);
}

int
wclrtobot			(WINDOW *window)
{
	COORD _tmp_cur_pos = window->_cur;

	DWORD _written_length;

	if (!FillConsoleOutputCharacter(
		window->_swapbuffer[SWAPBUFFER_BACK],
		window->_bkgd_ch,
		window->_size.X - (_tmp_cur_pos.X) - 1 + ((window->_size.Y) - (_tmp_cur_pos.Y) - 1) * window->_size.X,
		_coord_create(_tmp_cur_pos.Y, _tmp_cur_pos.X),
		&_written_length
	))
		return ERR;

	if (wmove(window, _tmp_cur_pos.Y, _tmp_cur_pos.X) == ERR)
		return ERR;
	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;
	return OK;
}

int
clrtoeol			(void)
{
	return wclrtoeol(stdscr);
}

int
wclrtoeol			(WINDOW *window)
{
	COORD _tmp_cur_pos = window->_cur;

	for (int i = _tmp_cur_pos.X; i < window->_size.X; ++i)
		if (_waddch_pure(window, window->_bkgd_ch) == ERR)
			return ERR;

	if (wmove(window, _tmp_cur_pos.Y, _tmp_cur_pos.X) == ERR)
		return ERR;

	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;
	return OK;
}