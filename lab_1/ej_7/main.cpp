#include <iostream>

using namespace std;

int maximo_factor_primo(int numero)
{
    int count;
    int maximo;

    for (int factor = 1; factor <= numero; factor++)
    {
        if (numero % factor == 0)
        {
            count = 0;
            for (int i = 2; count == 0 && factor > i ; i++)
            {
                if (factor % i == 0)
                {
                    count ++;
                }
            }
            if (count == 0) {
                maximo = factor;
            }
        }
    }

    return maximo;
}

int main()
{
    int numero;
    int maximo;
    cout << "EJERCICIO 7: Calcular el maximo factor primo" << endl;
    cout << "Ingrese un numero entero: ";
    cin >> numero;

    maximo = maximo_factor_primo(numero);
    cout << "El mayor factor primo de " << numero << " es " << maximo << endl;

    return 0;
}

