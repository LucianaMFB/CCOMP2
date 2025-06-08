#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int* generarArrayAleatorio(int n) {
    srand(12345);
    int* array = new int[n];

    for (int i = 0; i < n; ++i) {
        array[i] = rand() % 100 + 1;
    }

    return array;
}

//--------------------------- PUNT FUNC ----------------------------------------

static bool less(int a, int b) {
    return a < b;
}

bool greater(int a, int b) {
    return a > b;
}

void quickSort_PF(int* arr, int low, int high, bool (*pf)(int, int)) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            // Aqui se compara
            if ((*pf)(arr[j], pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort_PF(arr, low, pi - 1, pf);
        quickSort_PF(arr, pi + 1, high, pf);
    }
}

//------------------------------ POLIMORFISMO ----------------------------------

class CP {
public:
    virtual bool comparation(int a, int b) = 0;
};

class CLess : public CP {
public:
    bool comparation(int a, int b)
    {
        return a < b;
    }
};

class CGreater : public CP {
public:
    bool comparation(int a, int b)
    {
        return a > b;
    }
};

void quickSort_Poli(int* arr, int low, int high, CP* p) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            // Aqui se compara
            if (p->comparation(arr[j], pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort_Poli(arr, low, pi - 1, p);
        quickSort_Poli(arr, pi + 1, high, p);
    }
}

//---------------------------- FUNCTION OBJECTS --------------------------------

struct CLess_fo {
    bool comparation_fo(int a, int b)
    {
        return a < b;
    }
};

struct CGreater_fo {
    bool comparation_fo(int a, int b)
    {
        return a > b;
    }
};

template <class Comp>
void quickSort_Fo(int* arr, int low, int high, Comp c) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            // Aqui se compara
            if (c.comparation_fo(arr[j], pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort_Fo(arr, low, pi - 1, c);
        quickSort_Fo(arr, pi + 1, high, c);
    }
}

//------------------------ FUNCTION OBJECTS inline -----------------------------

struct CLess_foi {
    inline bool comparation_foi(int a, int b)
    {
        return a < b;
    }
};

struct CGreater_foi {
    inline bool comparation_foi(int a, int b)
    {
        return a > b;
    }
};

template <class Comp>
void quickSort_Foi(int* arr, int low, int high, Comp ci) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            // Aqui se compara
            if (ci.comparation_fo(arr[j], pivot)) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort_Foi(arr, low, pi - 1, ci);
        quickSort_Foi(arr, pi + 1, high, ci);
    }
}

//------------------------------------------------------------------------------

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int n = 1000000;
    int* arr = generarArrayAleatorio(n);
    int v = 5;

    //---------------------------------------------------------------------------

    bool (*pf)(int, int);
    pf = &less;

    std::cout << "PUNTERO A FUNCION" << std::endl;
    std::cout << "Arreglo original: ";
    printArray(arr, v);

auto start = std::chrono::high_resolution_clock::now();
    quickSort_PF(arr, 0, n - 1, pf);
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tiempo: " << duration.count() << " microsegundos" << std::endl;

    std::cout << "Arreglo ordenado: ";
    printArray(arr, v);

    //---------------------------------------------------------------------------

    CLess l;
    CGreater g;
    CP* p = &l;

    std::cout << "POLIMORFISMO" << std::endl;
    std::cout << "Arreglo original: ";
    printArray(arr, v);
auto start2 = std::chrono::high_resolution_clock::now();
    quickSort_Poli(arr, 0, n - 1, p);
auto end2 = std::chrono::high_resolution_clock::now();
auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    std::cout << "Tiempo: " << duration2.count() << " microsegundos" << std::endl;

    std::cout << "Arreglo ordenado: ";
    printArray(arr, v);

    //---------------------------------------------------------------------------

    CLess_fo l_fo;

    std::cout << "FUNCTION OBJECTS" << std::endl;
    std::cout << "Arreglo original: ";
    printArray(arr, v);
auto start3 = std::chrono::high_resolution_clock::now();
    quickSort_Fo(arr, 0, n - 1, l_fo);
auto end3 = std::chrono::high_resolution_clock::now();
auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);
std::cout << "Tiempo: " << duration3.count() << " microsegundos" << std::endl;
    std::cout << "Arreglo ordenado: ";
    printArray(arr, v);

    //---------------------------------------------------------------------------

    CLess_fo l_foi;

    std::cout << "FUNCTION OBJECTS inline" << std::endl;
    std::cout << "Arreglo original: ";
    printArray(arr, v);
auto start4 = std::chrono::high_resolution_clock::now();
    quickSort_Fo(arr, 0, n - 1, l_foi);
auto end4 = std::chrono::high_resolution_clock::now();
auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4);
std::cout << "Tiempo: " << duration4.count() << " microsegundos" << std::endl;
    std::cout << "Arreglo ordenado: ";
    printArray(arr, v);

    delete[] arr;
    return 0;
}
