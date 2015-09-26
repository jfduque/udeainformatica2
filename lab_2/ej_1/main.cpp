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

float promedio (int *ptrVect, int tam)
{
    int sum = 0;
    float avg = 0.0;
    for (int i = 0; i < tam; ++i)
    {
        sum += ptrVect[i];
    }
    avg = ((float)sum)/tam;
    return avg;
}

int main()
{
    int tam;

    cout << "EJERCICIO 1: Calcular el promedio de una serie de numeros" << endl;
    cout << "Cuantos numeros va a ingresar?: ";
    cin >> tam;

    int *array = new int[tam];
    capturar_vector(array, tam);
    float avg = promedio(array, tam);

    cout << "El promedio de ";
    for (int i = 0; i < tam; i++)
    {
        if (i == tam-1) {
            cout << array[i] << " ";
        } else {
            cout << array[i] << ", ";
        }
    }
    cout << "es: " << avg << endl;

    delete[] array;
    return 0;
}

