#include <iostream>

int** crearMatriz(int filas, int columnas)
{
    int **matriz = new int* [filas];
    
    for(int i= 0; i< filas; i++)
    {
        matriz[i] = new int[columnas];
    }
    
    std::cout<<" >> MATRIZ CREADA <<" << std::endl;
    return matriz;
}

void liberarMatriz(int** matriz, int filas)
{
    for(int i = 0; i< filas; i++)
    {
        delete matriz[i];
    }
    
    delete matriz;
    std::cout<<" >> MATRIZ BORRADA <<" << std::endl;
    return;
}

int main()
{
    int filas = 3;
    int columnas = 5;
    
    int **matriz = crearMatriz(3,5);
    liberarMatriz(matriz, 3);

    return 0;
}
