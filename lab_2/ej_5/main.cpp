#include <iostream>

using namespace std;

void capturar_vector(int array[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << "Ingrese el elemento #" << i << ": ";
        cin >> array[i];
    }
}

void imprimir_vector(int array[], int tam)
{

    for (int i = 0; i < tam; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void invertir_vector(int array[], int tam)
{
    int *fptr = array;
    int *lptr = array + tam -1;
    int i = 0;
    while(fptr < lptr)
    {
        i = *fptr;
        *fptr = *lptr;
        *lptr = i;
        *fptr++;
        *lptr--;
    }
}

int main()
{
    int tam = 0;

    cout << "EJERCICIO 5: Intercambiar el contenido de dos vectores" << endl;
    cout << "Ingrese la magnitud de los vectores: ";
    cin >> tam;

    int *array_a = new int[tam];
    int *array_b = new int[tam];

    capturar_vector(array_a, tam);
    capturar_vector(array_b, tam);

    cout << endl;

    cout << "Vector 1: ";
    imprimir_vector(array_a, tam);

    cout << "Vector 2: ";
    imprimir_vector(array_b, tam);

    invertir_vector(array_a, tam);
    cout << "Vector 1 invertido: ";
    imprimir_vector(array_a, tam);

    invertir_vector(array_b, tam);
    cout << "Vector 2 invertido: ";
    imprimir_vector(array_b, tam);

    delete[] array_a;
    delete[] array_b;
    return 0;
}
