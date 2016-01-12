#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <list>

#include "cuerpo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        std::list<Cuerpo*> listarCuerpos();
        void agregarCuerpo(Cuerpo *cuerpo);
        void enlazarCuerpos();
        void correrSimulacion();

    private slots:
        void on_actionSalir_triggered();

        void on_actionAgregar_triggered();

        void on_pushButtonIniciar_clicked();

        void on_pushButtonReset_clicked();

private:
        Ui::MainWindow *ui;

        QGraphicsScene *scene;

        std::list<Cuerpo*> cuerpos;
};

#endif // MAINWINDOW_H
