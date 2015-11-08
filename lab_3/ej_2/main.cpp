#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <limits.h>

using namespace std;

string invertir_bits(string cadena)
{
    string output;
    for(string::size_type i = 0; i < cadena.size(); i++) {
        if (cadena[i] == '0') {
            output += '1';
        }

        if (cadena[i] == '1') {
            output += '0';
        }
    }

    return output;
}

string invertir_cada_n_bits(string cadena, int cada)
{
    string output;
    for(string::size_type i = 1; i <= cadena.size(); i++) {
        if (i % cada == 0) {
            if (cadena[i-1] == '0') {
                output += '1';
            }

            if (cadena[i-1] == '1') {
                output += '0';
            }
        } else {
            output += cadena[i-1];
        }
    }
    return output;
}


int main(int argc, char* argv[])
{
    cout << "EJERCICIO 2: Decodificar archivos de texto" << endl;
    cout << "Se usaran bloques de " << argv[1] << " bits" << endl;
    cout << "Archivo fuente: " << argv[2] << endl;
    cout << "Archivo destino: " << argv[3] << endl;

    int tam = atoi(argv[1]);

    ifstream fuente;

    fuente.open(argv[2]);
    if (!fuente.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo fuente " << argv[2] << endl;
    }

    char *fuente_str = new char[tam];
    bool primer_grupo = true;
    //string fuente_str;
    while(fuente.good())
    {
       fuente.read(fuente_str, tam);
       // cout << fuente_str << endl;

       if (primer_grupo) {
           // Invertir los bits
           destino_str += invertir_bits(fuente_str);
           primer_grupo = false;
       } else {
           if (ceros_anterior == unos_anterior) {
               destino_str += invertir_bits(fuente_str);
           }
           if (ceros_anterior > unos_anterior) {
               destino_str += invertir_cada_n_bits(fuente_str, 2);
           }
           if (ceros_anterior < unos_anterior) {
               destino_str += invertir_cada_n_bits(fuente_str, 3);
           }
       }
       //getline(fuente,l);
       //for(string::size_type i = 0; i < l.size(); ++i) {
       //    fuente_str += chartobin(l[i]);
           // cout << l[i] << chartobin(l[i]) << endl;
       //}
    }


    return 0;
}

