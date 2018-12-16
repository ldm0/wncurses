#pragma once
#ifndef _ERROR_H
#define _ERROR_H

#include"wncurses.h"
#include<stdio.h>

#ifdef _DEBUG

#define ERROR_LOG(x) {\
	fputs(#x, stdin);\
	exit(1);\
}

#define ASSERT(x) {\
	if (!(x))\
		__debugbreak();\
}
#else
#define ERROR_LOG(x) { }
#define ASSERT(x) { }

#endif
#endif