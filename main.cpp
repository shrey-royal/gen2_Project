//we will use basic function created in the function.cpp file
#include "functions.cpp"

DRAW draw;  // object of DRAW class


int main() {
    FEE fee;

    fee.ADDITION();
    system("cls");

    for(i = 10; i < 71; i++) {
        gotoxy(i, 15);
        Sleep(30);
        cout << "/";
    }

    for(i = 70; i >= 10; i--) {
        gotoxy(i, 22);
        Sleep(30);
        cout << "/";
    }

    for(j = 16; j <= 21; j++) {
        gotoxy(10, j);
        Sleep(100);
        cout << "-";
    }

    for(j = 21; j>=16; j--) {
        gotoxy(70, j);
        Sleep(100);
        cout << "-";
    }

    gotoxy(16, 17);
    printf("FEE Structure System");
    gotoxy(12, 20);
    cout << "  ";
    cout << "  Press Any Key To ..............Continue";
    getch();
    mainmenu();

    return 0;
}