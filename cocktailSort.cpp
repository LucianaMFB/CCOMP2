#include <iostream>
#include <ctime>

void print(int arr[12])
{
   for (int* a = arr; a < arr + 12; a++)
   {
        std::cout << *a << " ";
   }
}

void swap(int* a, int* b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void cocktailSort(int* p, int* q, int arr[12])
{
   int cont = 1;
   bool flag = false;
   
   while(p < q && flag == 0)
   {
      flag = true;
      if (cont % 2 != 0)
      {
         int* postemp = p;
         for (; p != q; p++)
         {
            if (*p > *(p + 1))
            {
               swap(p, (p + 1));
               flag = false;
            }
         }
         p = postemp;
      }
     
      else
      {
         int* postemp = q;
         for (; q != p; q--)
         {
            if (*(q) < *(q - 1))
            {
               swap(q, (q - 1));
               flag = false;
            }
         }
         q = postemp;
      }
     
      std::cout << std::endl;
      std::cout << std::endl;
      std::cout << "cont: " << cont <<std::endl;
      std::cout << "flag: " << flag <<std::endl;
      print(arr);
      
      if (cont % 2 != 0) { q--; }
      else { p++; }
      cont++;
   }

}

void rellenar(int arr[12])
{
   for (int* a = arr; a < arr + 12; a++)
   {
      *a = rand() % 100;
   }
}

int main()
{
   srand(time(0));
   //int ar[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
   int arr[12];
   rellenar(arr);
 
   int*p = arr;
   int *q = arr+11;

   print(arr);
   cocktailSort(p,q, arr);
   std::cout << std::endl;

   return 0;
}
