#include"swapbuffer.h"
#include"coord.h"


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