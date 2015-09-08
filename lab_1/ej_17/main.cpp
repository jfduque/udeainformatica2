#include <iostream>
#include <cstdlib>

using namespace std;

int factorial(int n)
{
    int ret = 1;
    for(int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

int calcular_caminos(int magnitud)
{
	// Para matrices cuadradas, el total de caminos esta dado 
	// por la expresion (2x)!/ (x!*x!), donde x es la dimension
	
	int num = factorial(2*magnitud);
	int den = (factorial(magnitud) * factorial(magnitud));
	
	int caminos = num/den;
	
    return caminos;	
}

int main() {
	
	string magnitud = "0";
	
    cout << "EJERCICIO 17: Determinar caminos del extremo superior izquierdo de una matriz cuadrada" << endl;
    cout << "al extremo inferior" << endl;
    cout << "Ingrese la magnitud de la malla: ";
    
    getline(cin, magnitud);
    
    int mag = std::atoi(magnitud.c_str());
    
    int caminos = calcular_caminos(mag);
    
    cout << "Para una malla de " << magnitud << "x" << magnitud << " hay " << caminos << " caminos\n";

    return 0;
}
