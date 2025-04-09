#include <iostream>
#include <windows.h>
#include <conio.h>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

void Goto_XY(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void Ocultar_Cursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 2;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(hCon,&cursor);
}

int main()
{
    Ocultar_Cursor();

    int x = 6, y = 9;
    Goto_XY(3, 3);
    std::cout << "1";

    Goto_XY(6, 3);
    std::cout << "2";

    Goto_XY(9, 3);
    std::cout << "3";

    Goto_XY(3, 5);
    std::cout << "4";

    Goto_XY(6, 5);
    std::cout << "5";

    Goto_XY(9, 5);
    std::cout << "6";

    Goto_XY(3, 7);
    std::cout << "7";

    Goto_XY(6, 7);
    std::cout << "8";




    bool Estado = false;
    Goto_XY(x, y);

    while (Estado == false)
    {
        if (_kbhit())
        {
            char tecla = _getch();
            Goto_XY(x, y);
            std::cout << " ";

            if (tecla == IZQUIERDA) x = x - 3;
            if (tecla == DERECHA) x = x + 3;
            if (tecla == ARRIBA) y = y - 2;
            if (tecla == ABAJO) y = y + 2;

            Goto_XY(x, y);
            std::cout << "0";

        }

        Sleep(100);
    }

    return 0;
}
