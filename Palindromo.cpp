#include <iostream>
int len(char *x) {
	int cont = 0;
	while(*x != '\0') {
		++cont;
		x++;
	}
	return (cont - 1);
}

void palindromo(char *p, char *q) {
	while(p < q) {
		if (*p == *q) {
			p++;
			q--;
		}
		else {
			std::cout << " No es palindromo" << std::endl;
			return ;
		}
	}
	std::cout << " Es palindromo" << std::endl;
	return ;
}

int main()
{
	char A[30];
	std::cout << " Ingrese la palabra: ";
	std::cin >> A ;
	char *x = A;
	char *p = A;
	char *q = A + (len(x));
	palindromo(p, q);
	
	return 0;
 } 
