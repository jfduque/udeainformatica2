#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <limits.h>

using namespace std;

char* chartobin ( unsigned char c )
{
    static char bin[CHAR_BIT + 1] = { 0 };
    int i;

    for ( i = CHAR_BIT - 1; i >= 0; i-- )
    {
        bin[i] = (c % 2) + '0';
        c /= 2;
    }

    return bin;
}

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

int escribir_destino(char *nombre_archivo, string contenido)
{
    ofstream destino;
    string nombre_archivo_str(nombre_archivo);

    destino.open(nombre_archivo_str.c_str(),ios::app);
    destino << contenido;
    destino.close();

    return 0;
}

int main(int argc, char* argv[])
{
    cout << "EJERCICIO 1: Codificar archivos de texto" << endl;
    cout << "Se usaran bloques de " << argv[1] << " bits" << endl;
    cout << "Archivo fuente: " << argv[2] << endl;
    cout << "Archivo destino: " << argv[3] << endl;

    int tam = atoi(argv[1]);

    ifstream fuente;

    fuente.open(argv[2]);
    if (!fuente.is_open()) {
            cout << "ERROR: No se pudo abrir el archivo " << argv[2] << endl;
        }

    string l;
    string fuente_str;
    while(fuente.good())
    {
       getline(fuente,l);
       for(string::size_type i = 0; i < l.size(); ++i) {
           fuente_str += chartobin(l[i]);
           // cout << l[i] << chartobin(l[i]) << endl;
       }
    }

    bool primer_grupo = true;
    int ceros_anterior = 0;
    int unos_anterior = 0;
    int ceros_actual = 0;
    int unos_actual = 0;
    string destino_str;

    for(string::size_type i = 0; i < fuente_str.size(); i += tam) {

        string grupo;
        for(int j = i; j < i+tam; j++)
        {
            grupo += fuente_str[j];

            if (fuente_str[j] == '0') {
                ceros_actual++;
            }

            if (fuente_str[j] == '1') {
                unos_actual++;
            }
            //cout << i << ", " << j << ", " << fuente_str[j] << endl;
        }

        if (primer_grupo) {
            // Invertir los bits
            destino_str += invertir_bits(grupo);
            primer_grupo = false;
        } else {
            if (ceros_anterior == unos_anterior) {
                destino_str += invertir_bits(grupo);
            }
            if (ceros_anterior > unos_anterior) {
                destino_str += invertir_cada_n_bits(grupo, 2);
            }
            if (ceros_anterior < unos_anterior) {
                destino_str += invertir_cada_n_bits(grupo, 3);
            }
        }
//        cout << "grupo 0: " << grupo << endl;
//        cout << "grupo i: " << invertir_bits(grupo) << endl;
//        cout << "grupo 2: " << invertir_cada_n_bits(grupo, 2) << endl;
//        cout << "grupo 3: " << invertir_cada_n_bits(grupo, 3) << endl;

//        cout << "ceros anterior: " << ceros_anterior << endl;
        ceros_anterior = ceros_actual;

//        cout << "unos anterior: " << unos_anterior << endl;
        unos_anterior = unos_actual;

//        cout << "ceros actual: " << ceros_actual << endl;
        ceros_actual = 0;

//        cout << "unos actual: " << unos_actual << endl;
        unos_actual = 0;

        // cout << i << endl << output[i] << endl;
    }

    escribir_destino(argv[3], destino_str);

    return 0;
}

