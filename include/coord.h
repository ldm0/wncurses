#pragma once

#include <windows.h>

COORD _coord_create (int y, int x);
int _coord_init (COORD *coord, int y, int x);