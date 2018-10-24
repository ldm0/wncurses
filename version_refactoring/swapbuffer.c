#include"swapbuffer.h"
#include"coord.h"
#include"window.h"

void
_swapbuffer_swap	(HANDLE *a, HANDLE *b)
{
	//How to xor the HANDLE type..... Temporarily use the _tmp.
	HANDLE _tmp = *a;
	*a = *b;
	*b = _tmp;
}

BOOL
_swapbuffer_clear	(HANDLE buffer, chtype input)
{
	CONSOLE_SCREEN_BUFFER_INFO _buffer_info;
	if (!GetConsoleScreenBufferInfo(buffer, &_buffer_info))
		return ERR;
	DWORD _length = (DWORD)(
		(_buffer_info.srWindow.Bottom - _buffer_info.srWindow.Top + 1)
		*
		(_buffer_info.srWindow.Right - _buffer_info.srWindow.Left + 1)
		);
	DWORD _length_written; //unused
	if (!FillConsoleOutputCharacter(buffer, input, _length, _coord_create(0, 0), &_length_written))
		return ERR;
	return OK;
}

int
bkgd				(chtype input)
{
	return wbkgd(stdscr, input);
}

int
wbkgd				(WINDOW *window, chtype input)
{
	//from the test in my raspberry pi 
	//found several interesting things
	//Firstly,the bkgd function instantly, which means that the function modifies the front buffer, 
	//and more interestingly this function have the effect of refresh , if we print something before the bkgd function but don't refresh, 
	//the things printed will be presented, which can be tested in the test_bkgd file
	//Secondly, this function was implemented interestingly. There is a background char in the WINDOW struct.
	//This function scan the whole screen and change the every char same as the _bkgd to the input.

	int _tmp_data_length = window->_size.X * window->_size.Y;
	CHAR_INFO *_tmp_data = (CHAR_INFO*)malloc(sizeof(CHAR_INFO)*_tmp_data_length);
	if (_tmp_data == NULL)
		return ERR;

	//get chars
	SMALL_RECT _reg = {0, 0, window->_size.X - 1, window->_size.Y - 1};
	ReadConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_tmp_data,
		_coord_create(window->_size.Y, window->_size.X),
		_coord_create(0, 0),
		&_reg
	);

	//change chars
	for (int i = 0; i < _tmp_data_length; ++i)
		if (_tmp_data[i].Char.UnicodeChar == window->_bkgd_ch) {
			_tmp_data[i].Char.UnicodeChar = input;
		}


	//write chars
	WriteConsoleOutputW(
		window->_swapbuffer[SWAPBUFFER_BACK],
		_tmp_data,
		_coord_create(window->_size.Y, window->_size.X),
		_coord_create(0, 0),
		&_reg
	);

	free(_tmp_data);

	_tmp_data = NULL;

	window->_bkgd_ch = input;

	if (window->_immed)
		if (!_wrefresh_pure(window))
			return ERR;

	return OK;
}

void
bkgdset				(const chtype input)
{
	wbkgdset(stdscr, input);
}

void
wbkgdset			(WINDOW *window, const chtype input)
{
	window->_bkgd_ch = input;
}
