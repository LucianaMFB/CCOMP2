#include <iostream>
#include <string>
using namespace std;

void split(char* A, char (*condicion)(char)) {
    char*ini = A;
    char*fin = A + 10;
    while(ini < fin) {
        *ini = condicion(*ini);
        ini++;
    }

}

int main()
{
    char A[10] = {"Abb CFee"};

    auto mayuscula = [](char x) {
        if ((x >= 97) && (x <= 122) ) {
            x = x - 32;
        }
        return x;
    };

    auto minuscula = [](char x) {
        if ((x >= 65) && (x <= 90)) {
            x = x + 32;
        }
        return x;
    };
    
    split(A, minuscula);

    for (char* p = A; p < A + 7; p++) {
        cout << *p;
    }

}
