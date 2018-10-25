#include "depreciated.h"

int
clearok				(WINDOW *window, BOOL n)
{
	//not needed, this is windows, and the implementation is different
	//window->_clear = n;		
	return OK;
}


int
baudrate			(void)
{
	//It seems that there is no baud rate in windows terminal? I am uncertain.
	return -1;
}