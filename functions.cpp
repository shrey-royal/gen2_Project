#include "headers.h"
#include "declarations.cpp"
using namespace std;

class DRAW
{
public:
    void LINE_HOR(int, int, int, char); // parameters: x, y, length, character
    void LINE_VER(int, int, int, char); // parameters: x, y, length, character
    void BOX(int, int, int, int, char); // parameters: x1, y1, x2, y2, character
};

// Below classes will control all the functions related to fees

class FEE
{
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

    // the reason behind using void in parameter is that we are not taking any value from the user
} fee;

// Main Menu functions

void mainmenu()
{
    system("cls");

    for (li = 30; li <= 50; li++)
    {
        gotoxy(li, 14);
        Sleep(30); // 30 milliseconds
        printf("*");
    }

    for (li = 50; li >= 30; li--)
    {
        gotoxy(li, 30);
        Sleep(30);
        printf("*");
    }

    for (lp = 15; lp < 30; lp++)
    {
        gotoxy(30, lp);
        Sleep(100);
        printf("|");
    }

    for (lp = 29; lp >= 15; lp--)
    {
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
    choice = getch();
    ch = toupper(choice);

    switch (ch)
    {
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
        cout << "Illegal Choice Press any key to return to the Main Menu";
        getch();
        mainmenu();
    } // end of switch
} // end of mainmenu

// function to draw a horizontal line
void DRAW ::LINE_HOR(int col1, int col2, int row, char c)
{
    for (col1; col1 <= col2; col1++)
    {
        gotoxy(col1, row);
        cout << c;
    }
}

// function to draw a vertical line
void DRAW ::LINE_VER(int row1, int row2, int col, char c)
{
    for (row1; row1 <= row2; row1++)
    {
        gotoxy(col, row1);
        cout << c;
    }
}

// function to draw a box

void DRAW ::BOX(int col1, int row1, int col2, int row2, char c)
{
    char ch = 218;         // top left corner character
    char c1, c2, c3, c4;   // other characters
    char l1 = 196, l2 = 179; // line characters

    if (c == ch)
    {
        c1 = 218;
        c2 = 191;
        c3 = 192;
        c4 = 217;
        l1 = 196;
        l2 = 179;
    }
    else
    {
        c1 = c;
        c2 = c;
        c3 = c;
        c4 = c;
        l1 = c;
        l2 = c;
    }

    gotoxy(col1, row1);
    cout << c1;
    gotoxy(col2, row1);
    cout << c2;
    gotoxy(col1, row2);
    cout << c3;
    gotoxy(col2, row2);
    cout << c4;
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

// function to add Fee Structure in fee file

void FEE ::ADDITION()
{
    fstream file;
    file.open("FEE.TXT", ios::in); // open file in read mode
    if (!file.fail())
        return;
    file.close();
    file.open("FEE.TXT", ios::app);
    for (int i = 0; i <= 12; i++)
    {
        Class = i;
        tuition = 0.0;
        ac = 0.0;
        science = 0.0;
        computer = 0.0;
        activity = 0.0;
        file.write((char *)this, sizeof(FEE));
    }
    file.close();

    MODIFY_RECORD(12, 450, 50, 60, 60, 50);
    MODIFY_RECORD(11, 450, 50, 60, 60, 50);
    MODIFY_RECORD(10, 350, 50, 30, 60, 50);
    MODIFY_RECORD(9, 350, 50, 20, 60, 50);
    MODIFY_RECORD(8, 300, 50, 20, 40, 50);
    MODIFY_RECORD(7, 300, 50, 20, 40, 50);
    MODIFY_RECORD(6, 300, 50, 20, 40, 50);
    MODIFY_RECORD(5, 250, 50, 0, 40, 40);
    MODIFY_RECORD(4, 250, 50, 0, 40, 40);
    MODIFY_RECORD(3, 250, 50, 0, 40, 40);
    MODIFY_RECORD(2, 250, 50, 0, 40, 40);
    MODIFY_RECORD(1, 250, 50, 0, 40, 40);
}

// FUnction to display total fee as list
void FEE ::LIST()
{
    system("cls");
    DRAW d;
    d.BOX(1, 2, 80, 24, 218);
    gotoxy(27, 3);
    cout << "TOTAL FEES FOR THE CLASSES";
    d.LINE_HOR(2, 79, 4, 196);
    gotoxy(5, 5);
    cout << "CLASS          TOTAL FEES";
    d.LINE_HOR(2, 79, 6, 196);
    d.LINE_HOR(2, 79, 6, 196);
    float total;
    int row = 8;
    fstream file;
    file.open("FEE.TXT", ios::in);
    while (file.read((char *)this, sizeof(FEE)))
    {
        total = tuition + ac + science + computer + activity;
        gotoxy(6, row);
        cout << Class;
        gotoxy(25, row);
        cout << total;
        row++;
    }

    file.close();
    gotoxy(5, 23);
    cout << "Press any key to continue...............";
    getch();
    mainmenu();
}

// Function to display the record for the given class

void FEE ::DISPLAY(int tclass)
{
    fstream file;
    file.open("FEE.TXT", ios::in);
    while (file.read((char *)this, sizeof(FEE)))
    {
        if (Class == tclass)
        {
            gotoxy(5, 5);
            cout << "Class : " << Class;
            gotoxy(5, 7);
            cout << "~~~~~~~~~~~~~";
            gotoxy(5, 8);
            cout << "Tuition Fee : " << tuition;
            gotoxy(5, 9);
            cout << "Annual Charges Fee: " << ac;
            gotoxy(5, 10);
            cout << "Science Fee : " << science;
            gotoxy(5, 11);
            cout << "Computer Fee : " << computer;
            gotoxy(5, 12);
            cout << "Activity Fee : " << activity;
            break;
        }
    }
    file.close();
}

void FEE ::MODIFY_RECORD(int tclass, float ttuition, float tac, float tscience, float tcomputer, float tactivity)
{
    fstream file;
    file.open("FEE.TXT", ios::in);
    fstream temp;
    temp.open("TEMP.TXT", ios::out);
    file.seekg(0, ios::beg);
    while (!file.eof())
    {
        file.read((char *)this, sizeof(FEE));
        if (file.eof())
            break;
        if (tclass == Class)
        {
            Class = tclass;
            tuition = ttuition;
            ac = tac;
            science = tscience;
            computer = tcomputer;
            activity = tactivity;
            temp.write((char *)this, sizeof(FEE));
        }
        else
        {
            temp.write((char *)this, sizeof(FEE));
        }
    }
    file.close();
    temp.close();
    file.open("FEE.TXT", ios::out);
    temp.open("TEMP.TXT", ios::in);
    temp.seekg(0, ios::beg);
    while (!temp.eof())
    {
        temp.read((char *)this, sizeof(FEE));
        if (temp.eof())
            break;
        file.write((char *)this, sizeof(FEE));
    }
    file.close();
    temp.close();
}

// Function to give data to modify the fee record
void FEE ::MODIFICATION(void)
{
    system("cls");
    char ch, t1[10];
    int valid = 0, t = 0, tclass = 0;
    float t2 = 0;

    do
    {
        valid = 1;
        gotoxy(5, 25);
        cout << "Press <ENTER> for Exit";
        gotoxy(5, 5);
        cout << "Enter class for the modification of the fee structure: ";
        gets(t1);
        t = atoi(t1); // converts string to integer
        tclass = t;

        if (strlen(t1) == 0)
        {
            return;
        }
        if (tclass < 1 || tclass > 12)
        {
            valid = 0;
            gotoxy(5, 25);
            cout << "Enter corretly";
            getch();
        }
    } while (!valid);
    system("cls");
    gotoxy(71, 1);
    cout << "<0>=Exit";
    DISPLAY(tclass);
    gotoxy(5, 25);

    do
    {
        gotoxy(5, 15);
        cout << "Do you want to modify the fee structure (y/n): ";
        ch = getche();
        if (ch == '0')
            return;
        ch = toupper(ch);
    } while (ch != 'N' && ch != 'Y');
    if (ch == 'N')
        mainmenu();
    float ttuition = 0.0, tac = 0.0, tscience = 0.0, tcomputer = 0.0, tactivity = 0.0;
    gotoxy(5, 13);
    gotoxy(5, 17);
    cout << "Enter new Tuition Fee : ";
    gotoxy(5, 18);
    cout << "Enter new Annual Charges Fee : ";
    gotoxy(5, 19);
    cout << "Enter new Science Fee : ";
    gotoxy(5, 20);
    cout << "Enter new Computer Fee : ";
    gotoxy(5, 21);
    cout << "Enter new Activity Fee : ";

    int modified = 5;
    fstream file;
    file.open("FEE.TXT", ios::in);

    while (file.read((char *)this, sizeof(FEE)))
        if (Class == tclass)
            break;
    file.close();
    do
    {
        valid = 1;
        gotoxy(19, 17);
        gets(t1);
        t2 = atof(t1);
        ttuition = t2;
        if (t1[0] == '0')
            return;
        if (strlen(t1) == '0')
        {
            break;
        }
        if (ttuition > 1000)
        {
            valid = 0;
            gotoxy(5, 27);
            cout << "Enter correctly";
            getch();
        }
        modified--;
        ttuition = tuition;
        gotoxy(20, 17);
        cout << ttuition;
    } while (!valid);

    if (strlen(t1) == 0)
    {
        modified--;
        ttuition = tuition;
        gotoxy(20, 17);
        cout << ttuition;
    }

    do
    {
        valid = 1;
        gotoxy(5, 27);
        cout << "Enter ANNUAL CHARGES fee or Press <ENTER> for no change";
        gotoxy(26, 18);
        gets(t1);
        t2 = atof(t1);
        tac = t2;
        if (t1[0] == '0')
            return;
        if (strlen(t1) == 0)
            break;
        if (tac > 1000)
        {
            valid = 0;
            gotoxy(5, 27);
            cout << "Enter correctly";
            getch();
        }
    } while (!valid);
    if (strlen(t1) == 0)
    {
        modified--;
        tac = ac;
        gotoxy(26, 18);
        cout << tac;
    }
    do
    {
        valid = 1;
        gotoxy(5, 27);
        cout << "Enter SCIENCE FEES or Press <ENTER> for no change";
        gotoxy(19, 19);
        gets(t1);
        t2 = atof(t1);
        tscience = t2;
        if (t1[0] == '0')
            return;
        if (strlen(t1) == 0)
            break;
        if (tscience > 1000)
        {
            valid = 0;
            gotoxy(5, 27);
            cout << "Enter correctly";
            getch();
        }
    } while (!valid);
    if (strlen(t1) == 0)
    {
        modified--;
        tscience = science;
        gotoxy(19, 19);
        cout << tscience;
    }
    do
    {
        valid = 1;
        gotoxy(5, 27);
        cout << "Enter COMPUTER FEES or Press <ENTER> for no change";
        gotoxy(19, 20);
        gets(t1);
        t2 = atof(t1);
        tcomputer = t2;
        if (t1[0] == '0')
            return;
        if (strlen(t1) == 0)
            break;
        if (tcomputer > 1000)
        {
            valid = 0;
            gotoxy(5, 27);
            cout << "Enter correctly";
            getch();
        }
    } while (!valid);
    if (strlen(t1) == 0)
    {
        modified--;
        tcomputer = computer;
        gotoxy(19, 20);
        cout << tcomputer;
    }
    do
    {
        valid = 1;
        gotoxy(5, 27);
        cout << "Enter ACTIVITY FEES or Press <ENTER> for no change";
        gotoxy(19, 21);
        gets(t1);
        t2 = atof(t1);
        tactivity = t2;
        if (t1[0] == '0')
            return;
        if (strlen(t1) == 0)
            break;
        if (tactivity > 1000)
        {
            valid = 0;
            gotoxy(5, 27);
            cout << "Enter correctly";
            getch();
        }
    } while (!valid);
    if (strlen(t1) == 0)
    {
        modified--;
        tactivity = activity;
        gotoxy(19, 21);
        cout << tactivity;
    }
    if (!modified)
        mainmenu();
    gotoxy(5, 27);
    do
    {
        gotoxy(5, 25);
        cout << "Do you want to save (y/n) : ";
        ch = getche();
        if (ch == '0')
            return;
        ch = toupper(ch);
    } while (ch != 'N' && ch != 'Y');
    if (ch == 'N')
        return;
    MODIFY_RECORD(tclass, ttuition, tac, tscience, tcomputer, tactivity);
    gotoxy(5, 27);
    cout << "Record Modified";
    gotoxy(5, 29);
    cout << "Press any key to continue...........";
    getch();
    mainmenu();
}

//function to display the fee slip for the class
void FEE :: FEE_SLIP(void) {
    system("cls");

    char ch, t1[10];
    int valid=0, t=0, tclass=0;

    do {
        valid=1;
        gotoxy(5, 25);
        cout << "Press <ENTER> for Exit";
        gotoxy(5, 5);
        cout << "Enter Class to see the FEE Structure: ";
        gets(t1);
        t = atoi(t1);
        tclass = t;
        if (strlen(t1) == 0)
            return;
        if(tclass < 1 || tclass > 12) {
            valid=0;
            gotoxy(5, 27);
            cout << "Enter correctly";
            getch();
        }
    } while (!valid);
    char name[26];

    do {
        gotoxy(5, 25);
        cout << "Enter Name of the Student";
        valid = 1;//next time the loop will not be executed (!valid)
        gotoxy(5, 7);
        cout << "Name: ";
        gets(name);
        if(strlen(name) < 1 || strlen(name) > 25) {
            valid = 0;
            gotoxy(5, 25);
            cout << "Name Should not be greater than 25";
            getch();
        }
    } while(!valid);
    system("cls");
    DRAW d;
    d.BOX(20, 2, 61, 24, 987);
    gotoxy(24, 3);
    cout << "         YOUR SCHOOL      ";
    int d1, m1, y1;
    time_t td = time(0);
    struct tm * now = localtime( & td );
    d1 = now->tm_mday;
    m1 = (now->tm_mon +1);
    y1 = (now->tm_year +1900);//year since 1900
    gotoxy(45, 4);
    cout << "Date: " << d1 << "/" << m1 << "/" << y1;
    d.LINE_HOR(21, 60, 5, 196);
    gotoxy(22, 6);
    cout << "Name: " << name;
    gotoxy(22, 7);
    cout << "Class: " << tclass;
    d.LINE_HOR(21, 60, 8, 196);
    gotoxy(21, 9);
    cout << "    PARTICULARS               AMOUNT";
    d.LINE_HOR(21, 60, 10, 196);
    d.LINE_HOR(21, 60, 10, 196);
    d.LINE_HOR(21, 60, 10, 196);
    gotoxy(25, 21);
    cout << "TOTAL";
    gotoxy(54, 23);
    cout << "CASHIER";
    fstream file;
    file.open("FEE.TXT", ios::in);
    while(!file.eof()) {
        file.read((char *) this, sizeof(FEE));
        if(Class == tclass) {
            cout << "Found" << endl;
            break;
        }
        file.close();
    }
    float total=0.0;
    gotoxy(23, 12);
    cout << "Tuition fees               " << setprecision(2) << tuition;
    total = total+tuition;
    gotoxy(23, 13);
    cout <<"Annual charges fees       " << setprecision(2) <<ac;
    total = total+ac;
    gotoxy(23,14);
    cout <<"Science fees              " << setprecision(2) <<science;
    total = total+science;
    gotoxy(23,15);
    cout <<"Computer fees             " << setprecision(2) <<computer;
    total = total+computer;
    gotoxy(23,16);
    cout <<"Activity fees             " << setprecision(2) <<activity;
    total = total+activity;
    d.LINE_VER(9,21,46,179);
    char tt[15];
    sprintf(tt,"%f",total);
    gotoxy(49,21);
    cout <<tt;
    gotoxy(33,40);
    cout<<"Press any key to return to the main menu........";
    getch();
    mainmenu();
}

void FEE :: HELP() {
    system("cls");

    cout<<"This is a fee structure program"<<endl;
    cout<<"It can be used to :  "<<endl;
    cout<<"1. View the fee slip of a student of a class"<<endl;
    cout<<"2. Modify the fee structure of the school"<<endl;
    cout<<"3. View the fee structure of the school in the form of a list"<<endl;
    cout<<"The menu functions are described as follows"<<endl;
    cout<<"1. FEE SLIP:  This function displays the fee slip for a givenstudent"<<endl;
    cout<<" from the class entered by the user. "<<endl;
    cout<<"2. MODIFY:    This function modifies the fee structure for a give class."<<endl;
    cout<<" The user can change the fees for various fields"<<endl;
    cout<<"3. LIST:      This function displays the list of total fees for all the"<<endl;
    cout<<"Press any key to continue..........."<<endl;
    getch();
    mainmenu();
}