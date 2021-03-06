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
void dpc( int x, int y, char c);

/***********************************************************/

//functiile per project


void drawFrame()
{
    setcolor(15);
    gotoxy(4, 2);
    printf("%c", 201);
    for(int i=0;i<70;i++)
        printf("%c", 205);
    printf("%c\n", 187);
    for(int i=0;i<30;i++)
    {
        gotoxy(4, 3+i);
        printf("%c", 186);
        for(int j=0;j<70;j++)
            printf(" ");
        printf("%c\n", 186);
    }
    gotoxy(4, 33);
    printf("%c", 200);
    for(int i=0;i<70;i++)
        printf("%c", 205);
    printf("%c\n", 188);
}

void drawPlayer(int x, int y)
{
    dpxy(x, y);
    dpxy(x, y-1);
    dpxy(x-1, y);
    dpxy(x+1, y);
    dpxy(x-2, y);
    dpxy(x+2, y);
    dpx(x-2, y+1);
    dpx(x+2, y+1);
    dpc(x+2, y+2, 177);
    dpc(x-2, y+2, 177);
}

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
        setcolor(15);
        gotoxy(26, 9);
        setcolor(9);
        printf("Batalia navelor a lui Kim");
        setcolor(14);
        dpxy(31,11);
        setcolor(15);
        printf(" <-- New Game");
        setcolor(10);
        dpxy(31,13);
        setcolor(15);
        printf(" <-- Load Game");
        setcolor(5);
        dpxy(31,15);
        setcolor(15);
        printf(" <-- Instruction");
        setcolor(12);
        dpxy(31,17);
        setcolor(15);
        printf(" <-- Exit");

        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &InputRecord, 1, &Events);
        COORD cur=mouseCoord();

        if(mouseClick())
        {
            if(cur.X==31 && cur.Y==17) //exit
            {
                clc(0, 0, 80, 40);
                break;
            }
            else if(cur.X==31 && cur.Y==15) //instruction
            {
                clc(0, 0, 80, 40);
                gotoxy(26, 9);
                setcolor(9);
                printf("Batalia navelor a lui Kim");
                gotoxy(27,11);
                printf("beta versiune jocului lui Kim");
                getch();
                clc(0, 0, 80, 40);
            }
            else if(cur.X==31 && cur.Y==11) //new game
            {
                clc(0, 0, 80, 40);
                gotoxy(26, 1);
                setcolor(9);
                printf("Batalia navelor a lui Kim");

                COORD player = mouseCoord();

                drawFrame();
                while(1)
                {
                    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &InputRecord, 1, &Events);
                    if(mouseDraw())
                    {
                        //clc(5, 3, 74, 32);
                        COORD cur=mouseCoord();
                        clc(player.X-2, player.Y-1, player.X+2, player.Y+2);
                        drawPlayer(cur.X, cur.Y);
                        player=cur;
                    }
                }

                getch();
                clc();
            }
        }

        gotoxy(0,0);
        if(mouseDraw())
            printf("%d %d", cur.X, cur.Y);
    }

    return 0;
}

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
