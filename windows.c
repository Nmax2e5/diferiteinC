#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

INPUT_RECORD InputRecord;
DWORD Events;

void setcolor(WORD color);
void gotoxy(int x, int y);
void resizeConsole(int width, int height);
void initWin(int width, int height);
void clc();
int keyp();
int mouseDraw();
int mouseClick();
COORD mouseCoord();
void dpxy( int x, int y);
void dpx( int x, int y);
void dpy( int x, int y);

/***********************************************************/

//functiile per project



// end

void delay(double number_of_seconds)
{
    double milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
    {
        //cazul cu exceptii
    }
}

int main()
{
    initWin(800,600);

    while(1)
    {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &InputRecord, 1, &Events);
        clc();
        COORD cur=mouseCoord();

        if(mouseClick())
            dpxy(cur.X, cur.Y);

        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    }

    return 0;
}

void setcolor (WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);

    //     0 = Black
    //     1 = Blue
    //     2 = Green
    //     3 = Cyan
    //     4 = Red
    //     5 = Magenta
    //     6 = Yellow
    //     7 = LightGray
    //     8 = DarkGray
    //     9 = LightBlue
    //     10 = LightGreen
    //     11 = LightCyan
    //     12 = LightRed
    //     13 = LightMagenta
    //     14 = LightYellow
    //     15 = White
}

void gotoxy(int x, int y)
{
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    MoveWindow(console, 0, 0, width, height, TRUE);
}

void initWin(int width, int height)
{
    resizeConsole(width, height);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void clc(){
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
}

int keyp()
{
    if(InputRecord.EventType == KEY_EVENT)
        return 1;
    return 0;
}

int mouseDraw()
{
    if(InputRecord.EventType == MOUSE_EVENT)
        return 1;
    return 0;
}

int mouseClick()
{
    if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        return 1;
    return 0;
}

COORD mouseCoord()
{
    COORD aux = {InputRecord.Event.MouseEvent.dwMousePosition.X, InputRecord.Event.MouseEvent.dwMousePosition.Y};
    return aux;
}

void dpxy(int x, int y){
        gotoxy(x,y);
        printf("%c", 219);
}

void dpx( int x, int y){
        gotoxy(x,y);
        printf("%c",254);
}

void dpy( int x, int y){
        gotoxy(x,y);
        printf("%c",220);
}
