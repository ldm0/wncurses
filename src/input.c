#include"vars.h"
#include"input.h"
#include"output.h"
#include"window.h"
// for time functions
#include<windows.h>

int
_wgetch_raw(WINDOW *window)
{
	return wgetch(window);
}

int
getch(void)
{
	return wgetch(stdscr);
}

int
wgetch(WINDOW *window)
{
	if (_wrefresh_raw(window) == ERR)
		return ERR;

	ULONGLONG time_begin = GetTickCount64();
	int _num_input_record;
	INPUT_RECORD _input_record_buffer;

	// another way to implement the logic
	if (window->_delay < 0) {
		// Blocking read
		do {
			if (!ReadConsoleInput(
				GetStdHandle(STD_INPUT_HANDLE),
				&_input_record_buffer,
				1, &_num_input_record))
				return ERR;
		} while (_input_record_buffer.EventType != KEY_EVENT || _input_record_buffer.Event.KeyEvent.bKeyDown == FALSE);
	} else {
		// None-blocking read
		for (;;) {
			int _tmp_num_input_events = 0;
			if (!GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE), &_tmp_num_input_events))
				return ERR;

			if (_tmp_num_input_events) {

				if (!ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &_input_record_buffer, 1, &_num_input_record))
					return ERR;

				// If it's not a key event, check the time and redo loop
				if (_input_record_buffer.EventType == KEY_EVENT && _input_record_buffer.Event.KeyEvent.bKeyDown == TRUE)
					break;

			}
			if ((GetTickCount64() - time_begin) >= (ULONGLONG)window->_delay)
				return ERR;
		}
	}

	if (_echo)
		if (_input_record_buffer.Event.KeyEvent.uChar.AsciiChar != '\r')
			if (_waddch_raw(window, _input_record_buffer.Event.KeyEvent.uChar.UnicodeChar) == ERR)
				return ERR;

	if (_wrefresh_raw(window) == ERR)
		return ERR;
	return _input_record_buffer.Event.KeyEvent.uChar.UnicodeChar;
}

/*
int
wgetch				(WINDOW *window)
{
	if (_wrefresh_raw(window) == ERR)
		return ERR;

	INPUT_RECORD _tmp_input_record;
	DWORD _read_events, _unread_events;
	do {
		if (window->_delay == FALSE) {
			if (!GetNumberOfConsoleInputEvents(
				GetStdHandle(STD_INPUT_HANDLE),
				&_unread_events))
				return ERR;
			if (!_unread_events)
				return ERR;
		}

		if (!ReadConsoleInput(
			GetStdHandle(STD_INPUT_HANDLE),
			&_tmp_input_record,
			1, &_read_events))
			return ERR;
	} while (_tmp_input_record.EventType != KEY_EVENT
			 ||
			 _tmp_input_record.Event.KeyEvent.bKeyDown == FALSE);

	//The special case will definitely increase in the future.
	//and will be processed in a function.
	if (_echo)
		if (_tmp_input_record.Event.KeyEvent.uChar.AsciiChar != '\r')
			if (_waddch_raw(window, _tmp_input_record.Event.KeyEvent.uChar.UnicodeChar) == ERR)
				return ERR;

	if (_wrefresh_raw(window) == ERR)
		return ERR;

	return _tmp_input_record.Event.KeyEvent.uChar.UnicodeChar;
}
*/