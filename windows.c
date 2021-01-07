#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* MOTOR GRAFIC */

#include <windows.h>
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
void dpc( int x, int y, char c);

/***********************************************************/

// functiile per project BEGIN

    

// END

void delay(double number_of_seconds)
{
    double milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
    {
        //iesire din timp
    }
}

int main()
{
    
    menu_principal();

    return 0;
}

/* FUNCTIILE MOTORULUI GRAFIC */

void setcolor (WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);

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
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT);
}

void clc(int x, int y, int x1, int y1)
{
    for(int i=x; i<=x1;i++)
        for(int j=y; j<=y1; j++)
    {
        gotoxy(i, j);
        printf(" ");
    }
}

int keyp()
{
    //InputRecord.Event.KeyEvent.wVirtualKeyCode
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

void dpc( int x, int y, char c){
        gotoxy(x,y);
        printf("%c", c);
}

/***********************************************************************************************/
