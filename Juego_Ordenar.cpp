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
    std::cout << "    -------|-------|-------" << std::endl;
    for (int (*p)[3] = A; p < A + 3; p++)
    {
        std::cout << "   |";
        for (int* q = *p; q < *(p + 1); q++)
        {

            std::cout << "   " << *q << "   |";
        }

        std::cout << std::endl;
        std::cout << "    -------|-------|-------" << std::endl;
    }
}

bool Restrincciones(int* posicion, int* espacio, int Tablero[3][3])
{
    if (posicion < *Tablero || posicion > *(Tablero + 2) + 2)
    {
        return false;
        //std::cout << "NOOOOO" << std::endl;
    }
    else if ((posicion == espacio - 1) && (espacio == *Tablero + 3 || espacio == *Tablero + 6))
    {
        return false;
        //std::cout << "NOOOOO 1" << std::endl; 
    }

    else if ((posicion == espacio + 1) && (espacio == *Tablero + 2 || espacio == *Tablero + 5))
    {
        return false;
        //std::cout << "NOOOOO 2" << std::endl;
    }
    return true;
}

bool Victoria(int Tablero[3][3])
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
                flag = flag*true;
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

int main()
{
    int Tablero[3][3] = {{4, 7, 2}, {6, 1, 3}, {5, 8, 9} };
    print(Tablero);
    bool Estado = false;
    int* espacio = &(Tablero[2][2]);
    int* posicion = &(Tablero[2][2]);
    
    while (Estado == false)
    {
        if (_kbhit())
        {
            int tecla = _getch();

            if (tecla == IZQUIERDA) posicion = espacio - 1;
            if (tecla == DERECHA) posicion = espacio + 1;
            if (tecla == ARRIBA) posicion = espacio - 3;
            if (tecla == ABAJO)  posicion = espacio + 3;
                
            if (Restrincciones(posicion, espacio, Tablero))
            {
                int temp = *posicion;
                *posicion = *espacio;
                *espacio = temp;
                espacio = posicion;
            }

            system("cls");
            print(Tablero);
            if (Victoria(Tablero) == true)
            {
                std::cout << "GANASTE :)" << std::endl;
                break;
            }
            
                
        }
    }
    return 0;
}

