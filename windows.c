void textcolor (int color)
{
    static int __BACKGROUND;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),color + (__BACKGROUND << 4));
}

void clc()
{
COORD cursorPosition;
cursorPosition.X = 0;
cursorPosition.Y = 0;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void delay(double number_of_seconds)
{
    double milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
    {
        //cazul cu exceptii
    }
}
