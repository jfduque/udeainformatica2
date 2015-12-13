#include <iostream>
#include "cuerpo.h"

using namespace std;


int main()
{
    cout << "Hello World!" << endl;
    Cuerpo c1 (1,0,0);
    Cuerpo c2 (3,10,5);
    Cuerpo c3 (2,5,10);

    c1.agregarCuerpo(&c2);
    c1.agregarCuerpo(&c3);
    c2.agregarCuerpo(&c1);
    c2.agregarCuerpo(&c3);
    c3.agregarCuerpo(&c1);
    c3.agregarCuerpo(&c2);
//    std::list<Cuerpo*> lista1 = c1.listarCuerposCercanos();

//    for(list<Cuerpo*>::iterator iter = lista1.begin(); iter != lista1.end(); iter++){
//       cout<<*iter<<endl;
//    }

    cout << "C1 en X: " << c1.posX() << endl;
    cout << "C1 en Y: " << c1.posY() << endl;
//    cout << "Angulo de C1 a C2: " << c1.anguloCuerpo(&c2) << endl;
//    cout << "Angulo de C1 a C3: " << c1.anguloCuerpo(&c3) << endl;

    cout << "C2 en X: " << c2.posX() << endl;
    cout << "C2 en Y: " << c2.posY() << endl;
//    cout << "Angulo de C2 a C1: " << c2.anguloCuerpo(&c1) << endl;
//    cout << "Angulo de C2 a C3: " << c2.anguloCuerpo(&c3) << endl;

    cout << "C3 en X: " << c3.posX() << endl;
    cout << "C3 en Y: " << c3.posY() << endl;
//    cout << "Angulo de C3 a C1: " << c3.anguloCuerpo(&c1) << endl;
//    cout << "Angulo de C3 a C2: " << c3.anguloCuerpo(&c2) << endl;

    c1.actualizar();
//    c2.actualizar();

    return 0;
}

