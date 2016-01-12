#ifndef CUERPO_H
#define CUERPO_H

#include <list>
#include <QString>

class Cuerpo
{
    private:
        QString nombre;
        int masa;

        double pos_x_ini, pos_y_ini;
        double pos_x, pos_y;
        double pos_x_prev, pos_y_prev;

        int vel_x_ini, vel_y_ini;
        double vel_x, vel_y;

        double acel_x, acel_y;

        std::list<Cuerpo*> cuerpos_cercanos;

        double distanciaCuerpo(Cuerpo *cuerpo);
        double anguloCuerpo(Cuerpo *cuerpo);

    public:
        Cuerpo(QString n, int m, int x, int y, int vx, int vy);
        int getMasa();
        QString getNombre();
        double posX();
        double posY();
        double posXprev();
        double posYprev();
        std::list<Cuerpo*> listarCuerposCercanos();
        void agregarCuerpo(Cuerpo *cuerpo);

        void actualizar();
};

#endif // CUERPO_H
