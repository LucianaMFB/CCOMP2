#include <iostream>

void mostrar(int* arr, int size) 
{
    for (int *i = arr; i < arr + size; ++i) 
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void cambiar(int*& ptr) 
{
    *ptr = 42;
}


int main()
{
    int v[] = {1, 2, 3, 4, 5};
    mostrar(v, 5);
    
    int x = 10;
    int* p = &x;
    std::cout << *p << std::endl;
    
    cambiar(p);
    std::cout << *p << std::endl; // Debe imprimir 42

    return 0;
}
