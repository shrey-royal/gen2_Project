#include "headers.h"
#include "declarations.cpp"

class DRAW {
    public:
        void LINE_HOR(int, int, int, char); // parameters: x, y, length, character
        void LINE_VER(int, int, int, char); // parameters: x, y, length, character
        void BOX(int, int, int, int, char); // parameters: x1, y1, x2, y2, character
};

//Below classes will control all the functions related to fees
/*
class FEE {
    private:
        int Class;
        float tuition, ac, science, computer, activity;
        void DISPLAY(int);
        void MODIFY_RECORD(int, float, float, float, float, float); // parameters: Class, tuition, ac, science, computer, activity

    public:
        void ADDITION(void);
        void MODIFICATION(void);
        void FEE_SLIP(void);
        void LIST(void);
        void HELP(void);

        //the reason behind using void in parameter is that we are not taking any value from the user
} fee;

//Main Menu functions

void mainmenu() {
    system("cls");

    for(li = 30; li<=50; li++) {
        gotoxy(li, 14);
        Sleep(30);  //30 milliseconds
        printf("*");
    }

    for(li=50; li>=30; li--) {
        gotoxy(li, 30);
        Sleep(30);
        printf("*");
    }

    for(lp=15; li<30; lp++) {
        gotoxy(30, lp);
        Sleep(100);
        printf("|");
    }

    for(lp=29; lp>=15; lp--) {
        gotoxy(50, lp);
        Sleep(100);
        printf("|");
    }

    gotoxy(15, 10);

    printf("Press the corresponding keys for the desired action...");
    gotoxy(35, 16);

    printf("F: FEE SLIP");
    gotoxy(35, 19);

    printf("M: MODIFY RECORD");
    gotoxy(35, 22);

    printf("L: LIST");
    gotoxy(35, 25);

    printf("H: HELP");
    gotoxy(35, 28);

    printf("Q: QUIT");
    choice=getch();
    ch=toupper(choice);

    switch(ch) {
        case 'F':
            fee.FEE_SLIP();
            break;

        case 'M':
            fee.MODIFICATION();
            break;

        case 'L':
            fee.LIST();
            break;
        
        case 'H':
            fee.HELP();
            break;

        case 'Q':
            exit(0);
            break;

        default: 
            gotoxy(33, 40);
            std::cout << "Illegal Choice Press any key to return to the Main Menu";
            getch();
            mainmenu();
    }//end of switch
}//end of mainmenu
*/
//function to draw a horizontal line
void DRAW :: LINE_HOR(int col1, int col2, int row, char c) {
    for(col1; col1<=col2; col1++) {
        gotoxy(col1, row);
        std::cout << c;
    }
}

//function to draw a vertical line
void DRAW :: LINE_VER(int row1, int row2, int col, char c) {
    for(row1; row1<=row2; row1++) {
        gotoxy(col, row1);
        std::cout << c;
    }
}

//function to draw a box

void DRAW :: BOX(int col1, int row1, int col2, int row2, char c) {
    char ch=218;    //top left corner character
    char c1, c2, c3, c4;    //other characters
    char l1=196, l2=179;    //line characters
    
    if(c == ch) {
        c1 = 218;
        c2 = 191;
        c3 = 192;
        c4 = 217;
        l1 = 196;
        l2 = 179;
    } else {
        c1 = c;
        c2 = c;
        c3 = c;
        c4 = c;
        l1 = c;
        l2 = c;
    }

    gotoxy(col1, row1);
    std::cout << c1;
    gotoxy(col2, row1);
    std::cout << c2;
    gotoxy(col1, row2);
    std::cout << c3;
    gotoxy(col2, row2);
    std::cout << c4;
    col1++;
    col2--;

    LINE_HOR(col1, col2, row1, l1);
    LINE_HOR(col1, col2, row2, l1);

    col1--;
    col2++;

    row1++;
    row2--;

    LINE_VER(row1, row2, col1, l2);
    LINE_VER(row1, row2, col2, l2);
}