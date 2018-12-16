#include"cursor.h"
#include"window.h"
#include"vars.h"

int
move				(int y, int x)
{
	return wmove(stdscr, y, x);
}

int
wmove				(WINDOW *window, int y, int x)
{
	window->_cur.Y = y;
	window->_cur.X = x;

	if (window->_immed)
		if (_wrefresh_raw(window) == ERR)
			return ERR;

	return OK;
}

int
curs_set			(int state_new)
{
	//not every window has a state, so I don't place the state in the WINDOW struct
	//I let the windows to store the cursor state
	CONSOLE_CURSOR_INFO _tmp_cur_info;
	if (!GetConsoleCursorInfo(console_buffer, &_tmp_cur_info))
		return ERR;
    int state_prev = _tmp_cur_info.bVisible ? (_tmp_cur_info.dwSize > 50 ? 2 : 1) : 0;
    switch(state_new) {
    case 0:
		_tmp_cur_info.bVisible = FALSE;
        break;
    case 1:
		_tmp_cur_info.bVisible = TRUE;
		_tmp_cur_info.dwSize = 1;
        break;
    case 2:
		_tmp_cur_info.bVisible = TRUE;
		_tmp_cur_info.dwSize = 100;
        break;
    default:
        return ERR;
    }
	if (!SetConsoleCursorInfo(console_buffer, &_tmp_cur_info))
		return ERR;
	return state_prev;
}

int
mvcur				(int oldrow, int oldcol, int newrow, int newcol)
{
	stdscr->_cur.X += newcol - oldcol;
	stdscr->_cur.Y += newrow - oldrow;
	if (stdscr->_immed)
		if (_wrefresh_raw(stdscr) == ERR)
			return ERR;
	return OK;
}