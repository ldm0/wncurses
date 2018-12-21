#include<wncurses.h>

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

int tmp_test(void)
{
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
	return 0;
}

int main()
{
	//tmp_test();

	test_timeout();

	//test_border();
	//test_bkgd();
	//test_delch();
	//test_instr();
	//test_baudrate();
	//test_ball();
	//test_framerate();
	//test_sl();
	//test_addstr();
	//test_addnstr();
	//test_ACS_VLINE();
}