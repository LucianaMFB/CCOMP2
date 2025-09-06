#include <iostream>

class Pila {
  int A[10];
  int *top = nullptr;
  
  public:
  bool push(int val);
  bool pop(int &val);
  bool vacio();
  bool lleno();
  void print();
};

bool Pila::lleno() {
   return (top == A + 9);   
}

bool Pila::vacio() {
   return !top;
}

bool Pila::push(int val) {
   if(lleno()) {
      return false;
   }
   else {
      if (top) {
         top++;
      }
      else {
         top = A;
      }
      
      *top = val;
      return true;
   }
}

bool Pila::pop(int &val) {
   if (vacio()) {
      return false;
   }
   
   else {
      val = *top;
      top--;
      if (top < A) {
         top = nullptr;
      }
      return true;
   }
}

void Pila::print() {
   for(; top > A-1; top--)
   {
      std::cout << *top << " ";
   }
}

int main()
{
   Pila pila1;
   pila1.push(5);
   pila1.push(10);
   pila1.push(2);
   pila1.push(3);
   pila1.print();
   int a;
   pila1.pop(a);
   
   pila1.print();
   return 0;
}
