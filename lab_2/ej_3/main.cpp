#include <iostream>

using namespace std;

void convertir_a_mayusculas(char *cadena, int tam)
{
    for (int i = 0; i <= tam; i++)
    {
        int ascii = int(cadena[i]);

        if ( ascii >= 97 && ascii <= 122 ) {
            char ascii_mayus = ascii - 32;

            //cout << +cadena[i] << endl;
            //cout << cadena[i] << endl;
            //cout << +ascii_mayus<< endl;
            //cout << ascii_mayus<< endl;

            cadena[i] = int(ascii_mayus);
        }
    }
}

int main()
{
    int tam = 80;
    char cadena[80];

    cout << "EJERCICIO 3: Convertir una cadena de minusculas a mayusculas" << endl;
    cout << "Ingrese la cadena: ";
    cin >> cadena;

    convertir_a_mayusculas(cadena,tam);

    cout << "La cadena en mayusculas es: " << cadena << endl;
    return 0;
}

