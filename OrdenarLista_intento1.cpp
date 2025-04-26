#include <iostream>

void swap(int* p, int* q)
{
    int temp = 0;
    temp = *p;
    *p = *q;
    *q = temp;
}

void print(int arr[10])
{
    for (int *a = arr ; a < arr + 10; a++)
    {
        std::cout << *a << " ";
    }
    std::cout << "" << std::endl;
}

int main()
{
    int arr[10] = { 2,4,8,10,42,13,15,17,26,29 };
    print(arr);
    int* p = arr;
    int* q = arr + 5;
    int* fin = p + ((q-p)*2) - 1;
    int i = 4;
    int j = 0;

    while ((i > -1) && (j < 5))
    {
        p = arr + 4;
        q = arr + 5;
        if (*p > *q)
        {
            swap(p, q);
        }
        else 
        {
            break;
        }

        for (int l = 4; l > 0; l--)
        {
            p = arr + 0;
            p = p + l;
            if (*p < *(p - 1))
            {
                swap(p, p - 1);
            }

            else 
            { 
                break; 
            }
        }

        for (int u = 0; u < 4; u++)
        {
            q = arr + 5;
            q = q + u;
            if (*q > *(q + 1))
            {
                swap(q, q + 1);
            }

            else
            {
                break;
            }
        }

        i--;
        j++;
    }
    print(arr);
    return 0;
}
