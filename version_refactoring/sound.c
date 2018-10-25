#include"sound.h"

int 
beep				(void)
{
	/*
	In Windows 7, 
	Beep was rewritten to pass the beep to the default sound device for the session. 
	This is normally the sound card, except when run under Terminal Services, 
	in which case the beep is rendered on the client.
	*/
	if(!Beep(750, 300))
		return ERR;
	return OK;
}