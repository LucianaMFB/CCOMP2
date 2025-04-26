#include <iostream>

void merge(int*p, int*q)
{
    int *fin = p + (q-p) * 2;
    while(p < q && q < fin)
    {
        if (*p < *q) 
        {
            p++;
        }
        
        else
        {
            int temp = *q;
            int* posicion_temp = q;
            
            while (posicion_temp > p)
            {
                *posicion_temp = *(posicion_temp - 1);
                posicion_temp--;
            }
            
            *p = temp;
            p++;
            q++;
        }   
    }
}

void print(int arr[10])
{
    std::cout << std::endl;
    std::cout << "  " ;
    for (int a = 0; a < 10; a++)
    {
        std::cout << arr[a] << " ";
    }
    std::cout << "" << std::endl;
}

int main()
{
    int arr[10] = { 2,44,58,60,72,1,45,57,75,89 };
    int* p = arr;
    int* q = &arr[5];
    print(arr);
    merge(p,q);
    print(arr);

    return 0;
}
