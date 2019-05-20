#include<wncurses.h>
#include<stdio.h>
#include<stdlib.h>

extern void test_timeout();
extern void test_ACS_VLINE();
extern void test_addnstr();
extern void test_addstr();
extern void test_ball();
extern void test_baudrate();
extern void test_beep();
extern void test_bkgd();
extern void test_border();
extern void test_delch();
extern void test_instr();
extern void test_framerate();
extern void test_sl();
extern void test_move_boundary_check();

int main()
{
	tmp_test();

	//test_timeout();
	//test_border();
	//test_bkgd();
	//test_delch();
	//test_instr();
	//test_baudrate();
	//test_ball();
	//test_framerate();
	//test_move_boundary_check();
	//test_sl();
	//test_addstr();
	//test_addnstr();
	//test_ACS_VLINE();
}