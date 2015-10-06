#include <iostream>

using namespace std;

int busca(int vector[], int size, int buscado, int *&posicion)
{
    for (int i = 0; i < size; i++)
    {
        // cout << "pos: " << i << endl;
        // cout << "val: " << vector[i] << endl;

        if (vector[i] == buscado) {
            // cout << "found at " << i << endl;
            *posicion = i;
            return 1;
        }
    }
    // cout << "not found";
    *posicion = 0;
    return 0;
}

void capturar_vector(int array[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << "Ingrese el elemento #" << i << ": ";
        cin >> array[i];
    }
}

int main()
{
    int tam;
    int buscado;

    cout << "EJERCICIO 7: Buscar la posicion de un elemento en un vector" << endl;
    cout << "Ingrese la magnitud del vector: ";
    cin >> tam;

    int *vector = new int[tam];
    int *posicion;

    capturar_vector(vector, tam);

    cout << "Ingrese el entero a buscar: ";
    cin >> buscado;

    int encontrado = busca(vector, tam, buscado, posicion);

    if (encontrado == 1) {
        cout << "El numero " << buscado << " esta en la posicion " << *posicion << endl;
    } else {
        cout << "El numero " << buscado << " no fue encontrado" << endl;
    }

    return 0;
}

