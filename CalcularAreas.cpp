#include <iostream>
#define PI 3.14159

float aCirculo (int radio, int b)
{ return PI * (radio * radio); }

float aCuadrado (int lado, int b)
{ return lado * lado; }

float aRectangulo (int base, int altura)
{ return base * altura; }

float aTriangulo (int base, int altura)
{ return (base * altura) / 2; }

void ejecuta (float (*pf[])(int, int), int parametros[2], char nombre[4][11]) {
   for (int i = 0; i < 4; i++) {
      std::cout << "Area del " << nombre[i] << " = ";
      std::cout << pf[i](parametros[0], parametros[1]) << std::endl;
   }
}

int main()
{
   float (*pf[])(int, int) = {aCirculo, aCuadrado, aRectangulo, aTriangulo};
   char nombre[4][11] = {"Circulo", "Cuadrado" , "Rectangulo", "Triangulo"};
   int parametros[2] = {2, 10};
   
   ejecuta(pf, parametros, nombre);

   return 0;
}
