#include <iostream>
#include <thread>
using namespace std;

int len(char*pal) 
{
    int cont = 0;
    while (*pal) {
        cont++;
        pal++;
    }
    return cont;
}

void horizontal_A(char (*ini)[10], char (*fin)[10], char* palabra, int &cont) 
{
    char* a = palabra;

    for (; ini < fin; ini++) {
        a = palabra;
        for (char* p = *ini; p < *ini + 10; p++) {
            while ( (p < *ini + 10) && (*p == *a)) {
                a++;
                p++;

                if (!(*a)) {
                    cont++;
                    break;
                }
            }
            a = palabra;
        }
    }
}

void horizontal_R(char (*ini)[10], char (*fin)[10], char* palabra, int &cont)
{
    int l = 0;
    l = len(palabra);
    char* a = palabra + (l-1);

    for (; ini < fin; ini++) {
        a = palabra + (l - 1);
        for (char* p = *ini; p < *ini + 10; p++) {
            while ((p < *ini + 10) && (*p == *a)) {
                a--;
                p++;

                if (a == palabra - 1) {
                    cont++;
                }
            }
            a = palabra + (l - 1);
        }
    }
}

void vertical_A(char (*ini)[10], char* palabra, int& cont) 
{
    char* a = palabra;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            while ( (j < 10) && (*(*(ini + j) + i) == *a)) {
                a++;
                j++;

                if (!(*a)) {
                    cont++;
                }
            }
            a = palabra;
        }
    }
}

void vertical_R(char (*ini)[10], char* palabra, int& cont)
{
    int l = 0;
    l = len(palabra);
    char* a = palabra + (l - 1);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            while ((j < 10) && (*(*(ini + j) + i) == *a)) {
                a--;
                j++;

                if (a == palabra - 1) {
                    cont++;
                }
            }
            a = palabra + (l - 1);
        }
    }
}

int main()
{
    char A[10][10] = { {'T','A','M','O','A','U','A','M','O','R'},
                       {'O','M','E','A','M','O','R','l','R','O'},
                       {'M','O','Z','E','X','I','F','l','O','M'},
                       {'O','R','U','C','G','S','P','D','M','A'},
                       {'R','M','O','R','I','L','F','B','A','J'},
                       {'M','A','T','E','F','P','O','E','G','D'},
                       {'A','R','N','A','M','O','R','O','M','A'},
                       {'M','A','V','R','Z','L','O','K','D','U'},
                       {'O','M','F','O','T','B','L','S','F','I'},
                       {'R','I','A','M','O','R','O','M','A','E'} };

    char palabra[10] = { "ROMA" };

    int respuestas[4] = { 0,0,0,0 };


    thread t1 (horizontal_A, A, A + 10, palabra, ref(respuestas[0]));
    thread t2(horizontal_R, A, A + 10, palabra, ref(respuestas[1]));
    thread t3 (vertical_A, A, palabra, ref(respuestas[2]));
    thread t4 (vertical_R, A, palabra, ref(respuestas[3]));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    

    cout << respuestas[0] << endl;
    cout << respuestas[1] << endl;
    cout << respuestas[2] << endl;
    cout << respuestas[3] << endl;


    return 0;
}
