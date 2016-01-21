#include <iostream>
#include <math.h>
#include <list>
#include <QString>
#include <QtDebug>

#include "cuerpo.h"

#define PI 3.141592653589

Cuerpo::Cuerpo(QString n, int m, int x, int y, int vx, int vy)
{
    nombre = n;

    masa = m;

    pos_x_ini = x;
    pos_y_ini = y;
    pos_x = x;
    pos_y = y;
    pos_x_prev = x;
    pos_y_prev = y;

    vel_x_ini = vx;
    vel_y_ini = vy;
    vel_x = 0;
    vel_y = 0;

    acel_x = 0;
    acel_y = 0;
}

int Cuerpo::getMasa()
{
    return masa;
}

QString Cuerpo::getNombre()
{
    return nombre;
}

double Cuerpo::posX()
{
    return pos_x;
}

double Cuerpo::posY()
{
    return pos_y;
}

double Cuerpo::posXprev()
{
    return pos_x_prev;
}

double Cuerpo::posYprev()
{
    return pos_y_prev;
}

void Cuerpo::agregarCuerpo(Cuerpo *cuerpo)
{
    cuerpos_cercanos.push_back(cuerpo);
}

void Cuerpo::actualizar()
{
    double const_g = 6.67384e-11;

    qDebug() << "Cuerpos cercanos: " << cuerpos_cercanos.size();

    for(std::list<Cuerpo*>::iterator iter = cuerpos_cercanos.begin(); iter != cuerpos_cercanos.end(); iter++){
        Cuerpo *cuerpo = *iter;

        double angulo = anguloCuerpo(*iter);

        double num_x = (const_g * cuerpo->getMasa()) * cos(angulo);
        double num_y = (const_g * cuerpo->getMasa()) * sin(angulo);
        double den = pow(distanciaCuerpo(*iter),2);

        acel_x = acel_x + num_x/den;
        acel_y = acel_y + num_y/den;
    }

    vel_x = vel_x + acel_x;
    vel_y = vel_y + acel_y;

    pos_x_prev = pos_x;
    pos_y_prev = pos_y;

    pos_x = pos_x + vel_x + acel_x/2;
    pos_y = pos_y + vel_y + acel_y/2;
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

    return atan2(num,den);
}
