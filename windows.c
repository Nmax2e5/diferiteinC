#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

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

void setPos(int x, int y)
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
        setPos(0,0);
        setcolor(4);
        HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD InputRecord;
        DWORD Events;
        ReadConsoleInput(hin, &InputRecord, 1, &Events);

        if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            printf("%d %d", InputRecord.Event.MouseEvent.dwMousePosition.X, InputRecord.Event.MouseEvent.dwMousePosition.Y);
        }

    }

    return 0;
}