#include <iostream>

using namespace std;

float convertir_a_flotante(char *s)
{
  float cantidad = 0;
  float signo = 1;

  if (*s == '-'){
      signo = -1;
      s++;
  }

  for (int punto = 0; *s; s++){
      if (*s == '.'){
        punto = 1;
        continue;
      }
      // Convertir char a int
      int d = *s - '0';

      // Si d es un digito, multiplicar por 10 e ir acumulando en cantidad
      if (d >= 0 && d <= 9){
        if (punto) {
            signo /= 10.0f;
        }
        cantidad = cantidad * 10.0f + (float)d;
      }
  }

  return cantidad * signo;
}

int main()
{
    char cadena[80];

    cout << "EJERCICIO 9: Convertir una cadena de caracteres a un numero" << endl;
    cout << "Ingrese la cadena: ";

    cin >> cadena;

    cout << "El numero convertido es: " << convertir_a_flotante(cadena) << endl;

    return 0;
}

