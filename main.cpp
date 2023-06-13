//we will use basic function created in the function.cpp file
#include "functions.cpp"

DRAW draw;  // object of DRAW class


int main() {
    system("cls");
    system("color 02"); // background color black and text color green
    system("title Student Fees Management System");

    draw.LINE_HOR(1, 20, 10, '*');
    draw.LINE_VER(1, 30, 10, '#');
    // draw.BOX(5, 5, 40, 50, '#');


    // mainmenu();

    return 0;
}