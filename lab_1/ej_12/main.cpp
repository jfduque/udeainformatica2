#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string leer_archivo(string archivo)
{
    string output;

    cout << "Leyendo el archivo " << archivo << endl;

    ifstream f;

    f.open(archivo.c_str());

    if (!f.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << archivo << endl;
    }

    string l;

    while(f.good())
    {
        getline(f,l);
        output += l;
        output += "\n";
    }

    return output;  
}

int escribir_archivos(string contenido_de_archivo)
{
    ofstream f_a;
    ofstream f_b;
    ofstream f_c;

    string A_str("A ");
    string B_str("B ");
    string C_str("C ");

    string result;
    istringstream iss(contenido_de_archivo);

    for (std::string l; getline(iss, l); )
    {
        if (l.compare(0, A_str.length(), A_str) == 0) {
            f_a.open("A.txt",ios::app);
            f_a << l << "\n";
            f_a.close(); 

            cout << "Guardando '" << l << "' en A.txt\n";
        }   

        if (l.compare(0, B_str.length(), B_str) == 0) {
            f_a.open("B.txt",ios::app);
            f_a << l << "\n";
            f_a.close(); 

            cout << "Guardando '" << l << "' en B.txt\n";
        }   

        if (l.compare(0, C_str.length(), C_str) == 0) {
            f_a.open("C.txt",ios::app);
            f_a << l << "\n";
            f_a.close(); 

            cout << "Guardando '" << l << "' en C.txt\n";
        }              
    }    

    return 0;
}

int main()
{
    string nombre_de_archivo;
    string contenido_de_archivo;

    cout << "EJERCICIO 12: Leer un archivo y repartirlo en otros tres" << endl;
    cout << "Ingrese el nombre del archivo: ";

    getline(cin, nombre_de_archivo);

    contenido_de_archivo = leer_archivo(nombre_de_archivo);

    escribir_archivos(contenido_de_archivo);

    return 0;
}

