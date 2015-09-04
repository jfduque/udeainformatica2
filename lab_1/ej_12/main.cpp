#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string archivo;
    cout << "Hello World!" << endl;
    cout << "EJERCICIO 12: Leer un archivo y repartirlo en otros tres" << endl;
    cout << "Ingrese el nombre del archivo: ";

    getline(cin, archivo);

    cout << "Leyendo el archivo " << archivo << endl;

    ifstream archivo_leido;

    archivo_leido.open("arch12.txt");

    char output[100];
    if (archivo_leido.is_open()) {
        while (!archivo_leido.eof())
        {
           archivo_leido >> output;
           cout<<output;
        }
    } else {
        cout << "No se pudo abrir el archivo " << archivo << endl;
    }

    return 0;
}

