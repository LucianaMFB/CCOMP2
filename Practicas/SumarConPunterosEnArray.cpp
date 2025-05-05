#include <iostream>

int suma1P(int* arr, int size) 
{
    int cont = 0;
    
    for (int *p = arr; p < arr + size; p++)
    {
        cont += *p;
    }
    
    return cont;
}

int suma2P(int* arr, int size) 
{
    int *temp = arr;
    int cont = 0;
    
    for (int **p = &temp; *p < arr + size; ++(*p))
    {
        cont += **p;
    }
    
    return cont;
}

int suma3P(int* arr, int size) 
{
    int *temp = arr;
    int **temp2 = &temp;
    int cont = 0;
    
    for (int ***p = &temp2; **p < arr + size; ++(**p))
    {
        cont += ***p;
    }
    
    return cont;
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    int resultado = suma1P(v, 5);
    std::cout << " Suma con puntero de 1 dimension: "<< resultado << std::endl;
    
    resultado = suma2P(v, 5);
    std::cout << " Suma con puntero de 2 dimensiones: "<< resultado << std::endl;
    
    resultado = suma3P(v, 5);
    std::cout << " Suma con puntero de 3 dimensiones: "<< resultado << std::endl;
    
    return 0;
}
