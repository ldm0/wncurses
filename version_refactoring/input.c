#include"input.h"
#include"output.h"
#include"window.h"

int
_wgetch_pure(WINDOW *window)
{
	return wgetch(window);
}

int
getch				(void)
{
	return wgetch(stdscr);
}

int
wgetch				(WINDOW *window)
{
	if (_wrefresh_pure(window) == ERR)
		return ERR;

	INPUT_RECORD _tmp_input_record;
	DWORD _read_events, _unread_events;
	do {
		if (window->_delay == FALSE) {
			if (!GetNumberOfConsoleInputEvents(
				GetStdHandle(STD_INPUT_HANDLE),
				&_unread_events)
				)
				return ERR;
			if (!_unread_events)
				return ERR;
		}

		if (!ReadConsoleInput(
			GetStdHandle(STD_INPUT_HANDLE),
			&_tmp_input_record,
			1,
			&_read_events)
			)
			return ERR;
	} while (_tmp_input_record.EventType != KEY_EVENT
			 ||
			 _tmp_input_record.Event.KeyEvent.bKeyDown == FALSE);

	_waddch_pure(window, _tmp_input_record.Event.KeyEvent.uChar.UnicodeChar);

	if (_wrefresh_pure(window) == ERR)
		return ERR;

	return _tmp_input_record.Event.KeyEvent.uChar.UnicodeChar;
}