#include<wncurses.h>

void test_move_boundary_check()
{
        initscr();

        int result = mvaddch(1000, 0, 'a');
        getch();
        mvprintw(0, 0, "1.should be -1 : %d", result);
        getch();

        result = mvaddch(1000, 0, '\n');
        getch();
        mvprintw(0, 0, "2.should be -1 : %d", result);
        getch();

        result = move(1000, 0);
        getch();
        mvprintw(0, 0, "3.should be -1 : %d", result);
        getch();

        endwin();
}
