#include <curses.h>

int main() {
    int ch;
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();
    printw("see it in bold\n");
    ch = getch();
    if (ch == KEY_F(1))
        printw("F1 key pressed");
    else {
        printw("key pressed ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh();
    getch();
    endwin();








    return 0;
}
