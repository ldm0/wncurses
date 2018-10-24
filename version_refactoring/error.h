#ifndef _ERROR_H
#define _ERROR_H
#pragma once

#include"wncurses.h"
#include<stdio.h>

#ifdef _DEBUG

#define ERROR(x) {\
	fputs(#x, stdin);\
	exit(1);\
}

#define ASSERT(x) {\
	if (!(x))\
		__debugbreak();\
}

#endif
#endif