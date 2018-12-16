#include<wncurses.h>

extern void test_framerate();
extern void test_sl();
extern void test_addstr();
extern void test_addnstr();
extern void test_ACS_VLINE();

int main()
{
	test_framerate();
	test_sl();
	test_addstr();
	test_addnstr();
	test_ACS_VLINE();
}