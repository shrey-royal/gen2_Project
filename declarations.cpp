#include "headers.h"

int i, j, li, lp, rec, valid;

COORD coord = {0, 0};   // sets coordinates to 0, 0

void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void help();
char ch, choice;