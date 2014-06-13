#include <ncurses.h>
#include "draw.h"
#include "common.h"

/*
int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    initDraw();
    for(int i = 0; i < 5 ; i++){
        doDraw(arr, 5);
        sleep(1000000);
    }
    endDraw();
}
*/

void initDraw()
{

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    printw("Type any character to see it in bold\n");
}

void doDraw(int *arr, int size, int current)
{
    int i;
   init_pair(1, COLOR_RED, COLOR_YELLOW);
    for(i = 0; i< 40*size; i++) {
        mvvline(0, i, ' ', 1000);
    }
    for(i = 0; i< size; i++) {
        attron(COLOR_PAIR(1));
        mvvline(30 - arr[i], 10 + 4*i, '|', arr[i]);
        attroff(COLOR_PAIR(1));
    }
    refresh();/* Print it on to the real screen */
}

void endDraw()
{
    getch();/* Wait for user input */
    endwin();/* End curses mode  */
}

