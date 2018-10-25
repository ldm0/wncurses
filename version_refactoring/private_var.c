#include "private_var.h"

BOOL _echo;

void _private_var_reset(void)
{
	_echo = TRUE;
}

int
echo				(void)
{
	_echo = TRUE;
	return OK;
}

int
noecho				(void)
{
	_echo = FALSE;
	return OK;
}