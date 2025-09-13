#include <iostream>

void buscar(char *p, char *q) {
	char *inicio = q;
	int cont = 0;
	while (*p)
	{
		if (*p == *q) {
			if (!(*(q+1))){
				cont++;
				q = inicio;	
			}
			p++;
			q++;
		}
			
		else {
			p++;
			q = inicio;
			continue;
		}
		
	}
	std::cout << " La palabra buscada aparece: " << cont << " veces" << std::endl;
}


int main()
{
	char A[100] = {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrs"};
	char a[5];
	std::cout << " " << A << std::endl;
	std::cout << " Ingrese la palabra: ";
	std::cin >> a;
	
	char *p = A;
	char *q = a;
	buscar(p, q);

	return 0;
}
