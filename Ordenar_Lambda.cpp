#include <iostream>
#include <string>
using namespace std;

void split(int *A, bool (*condicion)(int)) {
    int x = *A;
    int *ini = A;
    int *fin = A + 7;
    
    while(*(fin-5) != x) {
        if(condicion(*ini)) {
            ini++;
        }
        
        else {
            int temp = *ini;
            for(int *a = ini; a < fin; a++) {
                *a = *(a+1);
            }
            *(fin - 1) = temp;
        }
    }
}



int main()
{
    int A[7] = {1, 2, 3, 4, 5, 6, 7};
    
    auto condicion = [](int x) {
            if(x%3 == 0) { return true; }
            return false;
    };
    
    split(A, condicion);
    
    for(int *p = A; p < A+7; p++) {
        cout << *p << " ";
    }
    
}
