#include <iostream>
#include <cstdlib>

using namespace std;

int calcular_multiplos(int num)
{
    for(int a = 2; a <= num; a++)
    {
       cout << "Multiplos de " << a << ": ";
       for(int b = 1; b <= num; b++)
       {
	       int mul = a*b;
	       if (mul <= num) {
		       cout << mul << ", ";   
		   }   
	   }
	   cout << endl;
    }	
	return 0;
}

int main()
{
    string numero = "0";
	
    cout << "EJERCICIO 2: Calcular multiplos de un numero" << endl;
    cout << "Ingrese el numero: ";	
    
    getline(cin, numero);
    
	// Convertir la cadena "numero" al entero "mag"
    int mag = std::atoi(numero.c_str());
    
	// Llamar la funcion calcular_multiplos() usando "mag" como argumento, y guardar el resultado en mul
    int mul = calcular_multiplos(mag);
	
	// Mostrar mul (debe ser 0 si calcular_multiplos() fue exitosa)
    cout << mul;
	
	return 0;
}
