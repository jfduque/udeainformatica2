#ifndef CUERPO_H
#define CUERPO_H

#include <list>

class Cuerpo
{
    private:
        int masa;

        int pos_x_ini, pos_y_ini;
        double pos_x, pos_y;

        int vel_x_ini, vel_y_ini;
        double vel_x, vel_y;

        double acel_x, acel_y;

        std::list<Cuerpo*> cuerpos_cercanos;

        double distanciaCuerpo(Cuerpo *cuerpo);
        double anguloCuerpo(Cuerpo *cuerpo);

    public:
        Cuerpo(int m, int x, int y);
        int getMasa();
        int posX();
        int posY();
        std::list<Cuerpo*> listarCuerposCercanos();
        void agregarCuerpo(Cuerpo *cuerpo);

        void actualizar();
};

#endif // CUERPO_H
