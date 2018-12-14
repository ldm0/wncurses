#pragma once

#include"wncurses.h"

COORD _coord_create (int y, int x);

BOOL _coord_init (COORD *coord, int y, int x);