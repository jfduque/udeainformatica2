#include <iostream>
#include <fstream>

#include "cuerpo.h"

using namespace std;


int main()
{
    // cout << "Hello World!" << endl;

    ofstream posiciones_cuerpos;

    Cuerpo c1 (1e10,3,3);
    Cuerpo c2 (1e3,0,5);
    Cuerpo c3 (1e3,5,0);
    Cuerpo c4 (1e3,2,0);

    c1.agregarCuerpo(&c2);
    c1.agregarCuerpo(&c3);
    c1.agregarCuerpo(&c4);

    c2.agregarCuerpo(&c1);
    c2.agregarCuerpo(&c3);
    c2.agregarCuerpo(&c4);

    c3.agregarCuerpo(&c1);
    c3.agregarCuerpo(&c2);
    c3.agregarCuerpo(&c4);

    c4.agregarCuerpo(&c1);
    c4.agregarCuerpo(&c2);
    c4.agregarCuerpo(&c3);


    posiciones_cuerpos.open("posiciones.txt");
    posiciones_cuerpos << "Tiempo\tC1_X\tC1_Y\tC2_X\tC2_Y\tC3_X\tC3_Y\tC4_X\tC4_Y\t\n";
    posiciones_cuerpos.close();

    posiciones_cuerpos.open("posiciones.txt",ios::app);
    for (int x = 0; x <= 500; x++)\
    {
        posiciones_cuerpos << x <<'\t'<< c1.posX() <<'\t'<< c1.posY() <<'\t'<< c2.posX() <<'\t'<< c2.posY() <<'\t'<< c3.posX() <<'\t'<< c3.posY() <<'\t'<< c4.posX() <<'\t'<< c4.posY() << endl;

        c1.actualizar();
        c2.actualizar();
        c3.actualizar();
        c4.actualizar();
    }
    posiciones_cuerpos.close();

    return 0;
}

