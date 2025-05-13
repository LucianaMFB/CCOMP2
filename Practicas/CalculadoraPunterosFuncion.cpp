#include <iostream>
using namespace std;

int sum(int a, int b) {
	cout << "  SUMA: ";
	return a + b;
}

int sub(int a, int b) {
	cout << "  RESTA: ";
	return a - b;
}

int mult(int a, int b) {
	cout << "  MULTIPLICACION: ";
	return a * b;
}

int divi(int a, int b) {
	cout << "  DIVISION: ";
	return a / b;
}

void calculadora(int m, int n, int (*pfx)(int, int)) {
	cout << endl;
   	cout << (*pfx)(m, n) << endl;
	return;
}

void signo(int *a) {
	cout << endl;
   	cout << "  sum(0) - sub(1) - mult(2) - div(3) " << endl;
   	cout << "  Ingrese el comando: ";
   	cin >> *a;
   	return;
}

int main() {
	int (*pf[])(int, int) = {sum, sub, mult, divi};
	int m = 14;
	int n = 17;
	int sig = -1;
	signo(&sig);
   
	if ( sig < 4 && sig > -1) { calculadora(m, n, pf[sig]); }
	else { cout << "  Invalido" << endl; }
   
   	return 0;
}
