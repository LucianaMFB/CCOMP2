#include <iostream>
#include <windows.h>
#include <conio.h>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

void print(int A[3][3])
{
    std::cout << std::endl;
    std::cout << "\x1B[38;2;173;146;47m    -------|-------|-------\x1B[m" << std::endl;
    for (int (*p)[3] = A; p < A + 3; p++)
    {
        std::cout << "\x1B[38;2;173;146;47m   |\x1B[m";
        for (int* q = *p; q < *(p + 1); q++)
        {

            std::cout << "   " << *q << "\x1B[38;2;173;146;47m   |\x1B[m";
        }

        std::cout << std::endl;
        std::cout << "\x1B[38;2;173;146;47m    -------|-------|-------\x1B[m" << std::endl;
    }
}

bool verificarVictoria(int Tablero[3][3])
{
    bool flag = true;
    int l = 1;

    for (int (*p)[3] = Tablero; p < Tablero + 3; p++)
    {
        for (int* q = *p; q < *(p + 1); q++)
        {
            if (*q == l)
            {
                //std::cout << "SI" << std::endl;
                flag = flag * true;
            }

            else
            {
                //std::cout << "NO" << std::endl;
                flag = flag * false;
            }
            l++;
        }
    }

    return flag;
}

void mensajeVictoria()
{
    std::cout << std::endl;
    std::cout << "\x1B[38;2;154;206;215m   ************************* \x1B[m" << std::endl;
    std::cout << "\x1B[38;2;154;206;215m   |        GANASTE        | \x1B[m" << std::endl;
    std::cout << "\x1B[38;2;154;206;215m   ************************* \x1B[m" << std::endl;
    std::cout << std::endl;

    return;
}

bool limites(int* posicion, int* espacio, int (*t)[3])
{
    int(*pt) = *(t);

    if (posicion < *t || posicion > pt + 8)
    {
        return false;
        //std::cout << "NOOOOO" << std::endl;
    }
    else if ((posicion == espacio - 1) && (espacio == pt + 3 || espacio == pt + 6))
    {
        return false;
        //std::cout << "NOOOOO 1" << std::endl; 
    }

    else if ((posicion == espacio + 1) && (espacio == pt + 2 || espacio == pt + 5))
    {
        return false;
        //std::cout << "NOOOOO 2" << std::endl;
    }
    return true;
}

void intercambiar(int* posicion, int* espacio)
{
    int temp = *posicion;
    *posicion = *espacio;
    *espacio = temp;

    return;
}

int main()
{
    int Tablero[3][3] = {{4, 7, 2}, {6, 1, 3}, {5, 8, 9} };
    int (*t)[3] = Tablero;
    bool Estado = false;
    int* espacio = &(Tablero[2][2]);
    int* posicion = &(Tablero[2][2]);

    print(Tablero);
    while (Estado == false)
    {
        if (_kbhit())
        {
            int tecla = _getch();
            if (tecla == IZQUIERDA) posicion = espacio - 1;
            if (tecla == DERECHA) posicion = espacio + 1;
            if (tecla == ARRIBA) posicion = espacio - 3;
            if (tecla == ABAJO)  posicion = espacio + 3;
                
            if (limites(posicion, espacio, t))
            {
                intercambiar(posicion, espacio);
                espacio = posicion;
            }

            system("cls");
            print(Tablero);

            if (verificarVictoria(Tablero) == true)
            {
                mensajeVictoria();
                break;
            }
        }
    }
    return 0;
}

