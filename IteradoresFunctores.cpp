#include <iostream>
using namespace std;

class Ascendente {
public:
   template <typename T>
   bool operator()(const T& a, const T& b) const {
      return a > b;
   }
};

class Descendente {
public:
   template <typename T>
   bool operator()(const T& a, const T& b) const {
      return a < b;
   }
};

template <class T>
class Iterador {
   T* x;

public:
   Iterador(T* p = nullptr) : x(p) {}

   T& operator*() { return *x; }

   Iterador& operator++() { ++x; return *this; }

   bool operator!=(const Iterador& other) const {
      return x != other.x;
   }

   bool operator<(const Iterador& other) const {
      return x < other.x;
   }

   friend std::ostream& operator<<(std::ostream& output, Iterador a) {
      output << *(a.x);
      return output;
   }
};

template <class T, class O>
class Ordene 
{
   typedef Iterador<T> MiIt;
   public:
   void ordenar(T* ini, T* fin) 
   {
      MiIt inicio(ini);
      MiIt final(fin);

      O orden;

      for (MiIt i = inicio; i < final; ++i) {
         for (MiIt j = inicio; j < final; ++j) {
            MiIt siguiente = j;
            ++siguiente;
            if (siguiente != final && orden(*j, *siguiente)) {
               swap(*j, *siguiente);
            }
         }
      }
   }
};

int main()
{
   int arr[] = {4, 19, 1, 7, 3, 15, 8, 2, 9};
   int n = sizeof(arr) / sizeof(arr[0]);
   Iterador<int> it;
   
   cout << "Original: ";

   for (it = arr; it < arr + n ; ++it) {
      cout << *it << " ";
   }
   cout << "\n";

   Ordene<int, Ascendente> ordenAsc;
   ordenAsc.ordenar(arr, arr + n);

   cout << "Ascendente: ";
   for (it = arr; it < arr + n ; ++it) {
      cout << *it << " ";
   }
   cout << "\n";

   return 0;
}
