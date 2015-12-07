#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <limits.h>

#include <bitset>

using namespace std;


char bintochar ( string binario )
{
    std::bitset<CHAR_BIT> bs(binario);
    char c(char(bs.to_ulong()));
    return c;
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
    int ceros_anterior = 0;
    int unos_anterior = 0;
    int ceros_actual = 0;
    int unos_actual = 0;
    string bits_invertidos;
    string destino_str;

    //string fuente_str;

    while(fuente.good())
    {
       fuente.read(fuente_str, tam);
//       cout << fuente_str << endl;

       string grupo;
       for(int i = 0; i < tam; i++)
       {
           grupo += fuente_str[i];

           if (fuente_str[i] == '0') {
               ceros_actual++;
           }

           if (fuente_str[i] == '1') {
               unos_actual++;
           }
       }

       if (primer_grupo) {
           // Invertir los bits
           bits_invertidos += invertir_bits(fuente_str);
           primer_grupo = false;
       } else {
           if (ceros_anterior == unos_anterior) {
               bits_invertidos += invertir_bits(fuente_str);
           }
           if (ceros_anterior > unos_anterior) {
               bits_invertidos += invertir_cada_n_bits(fuente_str, 2);
           }
           if (ceros_anterior < unos_anterior) {
               bits_invertidos += invertir_cada_n_bits(fuente_str, 3);
           }
       }

       ceros_anterior = ceros_actual;
       unos_anterior = unos_actual;
       ceros_actual = 0;
       unos_actual = 0;
    }

    for(string::size_type i = 0; i < bits_invertidos.size(); i += CHAR_BIT) {
        string grupo;
        for(int j = i; j < i+CHAR_BIT; j++)
        {
            grupo += bits_invertidos[j];
        }
//        cout << grupo << endl;
        cout << grupo << bintochar(grupo) << endl;

        destino_str += bintochar(grupo);
    }

//    destino_str += bintochar(bits_invertidos);

    cout << destino_str << endl;


    return 0;
}


