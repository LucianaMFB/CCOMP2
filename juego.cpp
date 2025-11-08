#include <iostream>
#include <cstdlib>
#include <ctime>

#include <windows.h>
#include <conio.h>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
using namespace std;

bool verificarTam (int dimension) {
    if ((dimension > 5) || (dimension < 3)) {
        return false;
    }
    return true;
}

void printTablero(int** tablero, int tam){
	cout << endl;
	for (int** p = tablero; p < tablero + tam; p++) {
        for (int* q = *p; q < *p + tam; q++) {
            cout << "  " << *q << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void liberarElementos(int* &elementos) {
    delete[] elementos;
    elementos = nullptr;
}

void rellenarTablero(int **tablero, int*elementos, int tam) {
	int *r = elementos;
	for (int** p = tablero; p < tablero + tam; p++) {
        for (int* q = *p; q < *p + tam; q++, r++) {
        	*q = *r;	
        }
    }
    
    liberarElementos(elementos);
}

int* generarElementos(int tam) {
	int u = tam*tam;
	int *elementos = new int [u];
	int l = 1;
	for(int *i = elementos; i<elementos+(u); i++) {
        *i = l;
        l++;
    }
    
    for(int i = 0; i<u-1; i++) {
        int a = 0 + rand() % (l-2);
        int b = 0 + rand() % (l-2);
        int temp = *(elementos+a);
        *(elementos+a) = *(elementos+b);
        *(elementos+b) = temp;
    }
    return elementos;
}

void liberarTablero(int** &tablero, int tam) {
    for (int i = 0; i < tam; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
    tablero = nullptr;
}

int** crearTablero(int tam){
	int** tablero = new int*[tam];
    for (int i = 0; i < tam; i++) {

        tablero[i] = new int[tam];
    }
    return tablero;
}

void intercambiar(int *p, int*q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

bool verificarLimites(int **a, int *posicion, int *espacio, int **tablero, int tam) {
	if (a == tablero && posicion < *a) {
        return false;
    }

    if (a == tablero + (tam - 1) && posicion > *a + (tam - 1)) {
        return false;
    }
	
	for (int **fila = tablero; fila < tablero + tam; fila++) {
        int *inicio = *fila;
        int *fin = *fila + (tam - 1);

        if (espacio == inicio && posicion == espacio - 1) {
            return false;
        }

        if (espacio == fin && posicion == espacio + 1) {
            return false;
        }
    }

	
	return true;
}

bool verificarVictoria(int **tablero, int tam)
{
    bool flag = true;
    int l = 1;

    for (int **p = tablero; p < tablero + tam; p++)
    {
        for (int* q = *p; q < *p + tam; q++)
        {
            if (*q == l) {
                flag = flag * true;
            }

            else {
                flag = flag * false;
            }
            l++;
        }
    }

    return flag;
}

int main()
{
    int tam = 0;
    cout << " Ingrese la dimension del tablero: ";
    cin >> tam;
    while (!(verificarTam(tam))) {
        cout << " Ingrese la dimension del tablero: ";
        cin >> tam;
    }
    
    
    
    int** tablero = crearTablero(tam);
    int* elementos = generarElementos(tam);
    bool estado = false;
    rellenarTablero(tablero, elementos, tam);    
	printTablero(tablero, tam);
    cout << endl;
    
    int **a = tablero + (tam-1);
    int *espacio = *a + (tam-1);
    int *posicion = *a + (tam-1);
    
    
    while(!estado) {
    	if (_kbhit()) {
    		int tecla = _getch();
    		
			if (tecla == ARRIBA && a > tablero) { 
	            a--;
	            posicion = *a + (espacio - *(a + 1)); 
	        }
	
	        if (tecla == ABAJO && a < tablero + (tam - 1)) { 
	            a++;
	            posicion = *a + (espacio - *(a - 1)); 
	        }
        
    		if(tecla == DERECHA) { posicion = espacio+1; }
    		if(tecla == IZQUIERDA) { posicion = espacio-1; }
    		
    		if (verificarLimites(a, posicion, espacio, tablero, tam))
            {
            	cout << "ok" <<endl;
                intercambiar(posicion, espacio);
                espacio = posicion;
            }

            system("cls");
            printTablero(tablero, tam);
            
            if (verificarVictoria(tablero, tam) == true)
            {
                cout << " GANASTE" << endl;
                break;
            }
		}
        
	}
    
    liberarTablero(tablero, tam);
    
}
