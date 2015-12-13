#include "cuerpo.h"

#include <iostream>
#include <math.h>
#include <list>

#define PI 3.141592653589

Cuerpo::Cuerpo(int m, int x, int y)
{
    masa = m;

    pos_x_ini = x;
    pos_y_ini = y;
    pos_x = x;
    pos_y = y;

    vel_x_ini = 0;
    vel_y_ini = 0;
    vel_x = 0;
    vel_y = 0;

    acel_x = 0;
    acel_y = 0;
}

int Cuerpo::getMasa()
{
    return masa;
}

int Cuerpo::posX()
{
    return pos_x;
}

int Cuerpo::posY()
{
    return pos_y;
}

void Cuerpo::agregarCuerpo(Cuerpo *cuerpo)
{
    cuerpos_cercanos.push_back(cuerpo);
}

void Cuerpo::actualizar()
{
    double const_g = 6.67384e-11;

    acel_x = 0;
    acel_y = 0;
    for(std::list<Cuerpo*>::iterator iter = cuerpos_cercanos.begin(); iter != cuerpos_cercanos.end(); iter++){
        Cuerpo *cuerpo = *iter;

        std::cout << "Masa: " << cuerpo->getMasa() << std::endl;
        std::cout << "Angulo: " << anguloCuerpo(*iter) << std::endl;
        std::cout << "Distancia: " << distanciaCuerpo(*iter) << std::endl;
        double num_x = (const_g * cuerpo->getMasa()) * cos(anguloCuerpo(*iter));
        double num_y = (const_g * cuerpo->getMasa()) * sin(anguloCuerpo(*iter));
        double den = pow(distanciaCuerpo(*iter),2);

        acel_x = acel_x + num_x/den;
        acel_y = acel_y + num_y/den;
    }
    std::cout << "ACEL X: " << acel_x << std::endl;
    std::cout << "ACEL Y: " << acel_y << std::endl;
}

std::list<Cuerpo *> Cuerpo::listarCuerposCercanos()
{
    return cuerpos_cercanos;
}

double Cuerpo::distanciaCuerpo(Cuerpo *cuerpo)
{
    double radicando = (pow((cuerpo->posX() - pos_x),2) + pow((cuerpo->posY() - pos_y),2));

    return sqrt(radicando);
}

double Cuerpo::anguloCuerpo(Cuerpo *cuerpo)
{
    double num = cuerpo->posY() - pos_y;
    double den = cuerpo->posX() - pos_x;
    return atan(num/den);
//    return atan(num/den) * 180 / PI;
}
