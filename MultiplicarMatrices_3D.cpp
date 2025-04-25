#include <iostream>
#include <iomanip>

void Mult(int (*p)[3][3])
{
    int (*q)[3] = *p;
    int (*A) = *(q);
    int (*B) = *(q + 3);
    int n = -1;
    
    for(int (*C) = *(q + 6); C < *(q + 9) ; C++)
    {
        int cont = 0;
        n++;
        
        if(n == 3 || n==6)
        {
            A += 3;
            B -= 3;
        }
        
        while( A < *(q + 3 + 3*n) && B < *(q + 6))
        {
            cont = cont + (*A) * (*B);
            A++;
            B += 3;
        }
        
        *C = cont;
        B -= 9;
        A -= 3;
        B++;
    }
    return;
}

void print(int (&matriz3d)[3][3][3])
{
   std::cout << std::endl;
    for(int (*p)[3][3] = matriz3d ; p < matriz3d + 3 ; p++)
    {
        for(int (*q)[3] = *p ; q < *(p + 1) ; q++)
        {
            for(int *l = *q ; l < *(q + 1) ; l++)
            {
                std::cout << std::setw(10) << *l << std::setw(10);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    } 
    return;
}

int main()
{
    int matriz3d [3][3][3] = { {{20,15,-9},
                                {3,74,5},
                                {0,7,0}},
                                        {{0,21,2},
                                         {10,4,-35},
                                         {6,7,20}},
                                                 {{0,0,0},
                                                  {0,0,0},
                                                  {0,0,0}} };
                                                  
    int (*p)[3][3] = matriz3d;
    Mult(p);
    print(matriz3d);

    return 0;
}
