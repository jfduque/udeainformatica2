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
    
    int mag = std::atoi(numero.c_str());
    
    int mul = calcular_multiplos(mag);
    cout << mul;
	
	return 0;
}
