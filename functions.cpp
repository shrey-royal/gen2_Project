#include "headers.h"
#include "declarations.cpp"

class DRAW {
    public:
        void LINE_HOR(int, int, int, char); // parameters: x, y, length, character
        void LINE_VER(int, int, int, char); // parameters: x, y, length, character
        void BOX(int, int, int, int, char); // parameters: x1, y1, x2, y2, character
};

//Below classes will control all the functions related to fees

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

//function to add Fee Structure in fee file

void FEE :: ADDITION() {
    fstream file;
    file.open("FEE.DAT", ios::in);  //open file in read mode
    if(!file.fail())
        return ;
    file.close();
    file.open("FEE.DAT", ios::app);
    for(int i=0; i<=12; i++) {
        Class  = i;
        tuition = 0.0;
        ac = 0.0;
        science = 0.0;
        computer = 0.0;
        activity = 0.0;
        file.write((char *) this, sizeof(FEE));
    }
    file.close();

    MODIFY_RECORD(12, 450, 50, 60, 60, 50);
    MODIFY_RECORD(11,450,50,60,60,50);  
    MODIFY_RECORD(10,350,50,30,60,50);  
    MODIFY_RECORD(9,350,50,20,60,50);  
    MODIFY_RECORD(8,300,50,20,40,50);  
    MODIFY_RECORD(7,300,50,20,40,50);  
    MODIFY_RECORD(6,300,50,20,40,50);  
    MODIFY_RECORD(5,250,50,0,40,40);  
    MODIFY_RECORD(4,250,50,0,40,40);  
    MODIFY_RECORD(3,250,50,0,40,40);  
    MODIFY_RECORD(2,250,50,0,40,40);  
    MODIFY_RECORD(1,250,50,0,40,40);
}

//FUnction to display total fee as list
void FEE :: LIST() {
    system("cls");
    DRAW d;
    d.BOX(1, 2, 80, 24, 218);
    gotoxy(27, 3);
    std::cout << "TOTAL FEES FOR THE CLASSES";
    d.LINE_HOR(2, 79, 4, 196);
    gotoxy(5, 5);
    std::cout << "CLASS          TOTAL FEES";
    d.LINE_HOR(2, 79, 6, 196);
    d.LINE_HOR(2, 79, 6, 196);
    float total;
    int row = 8;
    fstream file;
    file.open("FEE.DAT", ios::in);
    while(file.read((char *) this, sizeof(FEE))) {
        total = tuition + ac + science + computer + activity;
        gotoxy(6, row);
        std::cout << Class;
        gotoxy(25, row);
        std::cout << total;
        row++;
    }

    file.close();
    gotoxy(5, 23);
    std::cout << "Press any key to continue..............."; 
    getch();
    mainmenu();
}

//Function to display the record for the given class

void FEE :: DISPLAY(int tclass) {
    fstream file;
    file.open("FEE.DAT", ios::in);
    while(file.read((char *) this, sizeof(FEE))) {
        if(Class == tclass) {
            gotoxy(5, 5);
            std::cout << "Class : " << Class;
            gotoxy(5, 7);
            std::cout << "~~~~~~~~~~~~~";
            gotoxy(5, 8);
            std::cout << "Tuition Fee : " << tuition;
            gotoxy(5, 9);
            std::cout << "Annual Charges Fee: " << ac;
            gotoxy(5, 10);
            std::cout << "Science Fee : " << science;
            gotoxy(5, 11);
            std::cout << "Computer Fee : " << computer;
            gotoxy(5, 12);
            std::cout << "Activity Fee : " << activity;
            break;
        }
    }
    file.close();
}

void FEE :: MODIFY_RECORD(int tclass, float ttuition, float tac, float tscience, float tcomputer, float tactivity) {
    fstream file;
    file.open("FEE.DAT", ios::in);
    fstream temp;
    temp.open("TEMP.DAT", ios::out);
    file.seekg(0, ios::beg);
    while(!file.eof()) {
        file.read((char *) this, sizeof(FEE));
        if(file.eof())
            break;
        if(tclass == Class) {
            Class = tclass;
            tuition = ttuition;
            ac = tac;
            science = tscience;
            computer = tcomputer;
            activity = tactivity;
            temp.write((char *) this, sizeof(FEE));
        } else {
            temp.write((char *) this, sizeof(FEE));
        }
    }
    file.close();
    temp.close();
    file.open("FEE.DAT", ios::out);
    temp.open("TEMP.DAT", ios::in);
    temp.seekg(0, ios::beg);
    while(!temp.eof()) {
        temp.read((char *) this, sizeof(FEE));
        if(temp.eof())
            break;
        file.write((char *) this, sizeof(FEE));
    }
    file.close();
    temp.close();
}