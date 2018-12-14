#include"wncurses.h"
#include"coord.h"

COORD
_coord_create	(int y, int x)
{
	COORD _tmp;
	_tmp.Y = y;
	_tmp.X = x;
	return _tmp;
}

BOOL
_coord_init		(COORD *coord, int y, int x)
{
	if (!coord)
		return ERR;
	coord->Y = y;
	coord->X = x;
	return OK;
}