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
extern void test_move_boundary_check();

int tmp_test(void)
{
	int ch;

	initscr();			/* Start curses mode 		*/
	//raw();				/* Line buffering disabled	*/
	//keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

    	printw("Type any character to see it in bold\n");
	ch = getch();			/* If raw() hadn't been called
					 * we have to press enter before it
					 * gets to the program 		*/
	//if(ch == KEY_F(1))		/* Without keypad enabled this will */
		//printw("F1 Key pressed");/*  not get to us either	*/
					/* Without noecho() some ugly escape
					 * characters might have been printed
					 * on screen			*/
	//else
	{	printw("The pressed key is ");
		//attron(A_BOLD);
		printw("%c", ch);
		//attroff(A_BOLD);
	}
	refresh();			/* Print it on to the real screen */
    	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}

int main()
{
	//tmp_test();

	//test_timeout();
	//test_border();
	//test_bkgd();
	//test_delch();
	//test_instr();
	//test_baudrate();
	//test_ball();
	//test_framerate();
	test_move_boundary_check();
	test_sl();
	//test_addstr();
	//test_addnstr();
	//test_ACS_VLINE();
}