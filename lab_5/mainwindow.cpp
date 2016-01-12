#include <list>
#include <QtGui>
#include <QtDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnewbodydialog.h"
#include "cuerpo.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);

        QColor sceneBackgroundColor;
        sceneBackgroundColor.setRgb(0,0,0);

        scene = new QGraphicsScene(this);

        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(sceneBackgroundColor);
        scene->setBackgroundBrush(brush);

        ui->graphicsView->setScene(scene);
    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionAgregar_triggered()
{
    AddNewBodyDialog *myDialog = new AddNewBodyDialog();
    myDialog->show();

    if ( myDialog->exec() == QDialog::Accepted )
    {
        QString nombre = myDialog->getNombre();
        int masa = myDialog->getMasa();
        int posx = myDialog->getPosX();
        int posy = myDialog->getPosY();
        int velx = myDialog->getVelX();
        int vely = myDialog->getVelY();

        Cuerpo nuevo_cuerpo (nombre, masa, posx, posy, velx, vely);
        this->agregarCuerpo(&nuevo_cuerpo);

        ui->textBrowser->append( "Nuevo cuerpo " + nombre );
        ui->textBrowser->append( "Masa: " + QString::number(masa) );
        ui->textBrowser->append( "Coordenadas: " + QString::number(posx) + ", " + QString::number(posy) );

        std::list<Cuerpo*> cuerpos = this->listarCuerpos();
        ui->textBrowser->append( "Total de cuerpos: " + QString::number(cuerpos.size()) );
    }
}

void MainWindow::agregarCuerpo(Cuerpo *cuerpo)
{
    cuerpos.push_back(cuerpo);
}

void MainWindow::enlazarCuerpos()
{
    for(std::list<Cuerpo*>::iterator iter = cuerpos.begin(); iter != cuerpos.end(); iter++){
        Cuerpo *cuerpo = *iter;

        qDebug() << *iter;
    }
}

void MainWindow::correrSimulacion()
{
    for (int x = 0; x <= 10; x++)
    {
        QPen pen(Qt::blue);

        for(std::list<Cuerpo*>::iterator iter = cuerpos.begin(); iter != cuerpos.end(); iter++){
            Cuerpo *cuerpo = *iter;

            // qDebug() << *iter;
            // qDebug() << "X:" << cuerpo->posX();
            // qDebug() << "Y:" << cuerpo->posY();

            double pos_x_prev = cuerpo->posXprev();
            double pos_y_prev = cuerpo->posYprev();
            double pos_x = cuerpo->posX();
            double pos_y = cuerpo->posY();

            qDebug() << cuerpo->getNombre();
            qDebug() << "X:" << pos_x;
            qDebug() << "Y:" << pos_y;

            this->scene->addLine(pos_x_prev, pos_y_prev, pos_x, pos_y, pen);

            // cuerpo->actualizar();
        }
        ui->lcdNumber->display(x);
    }
}

std::list<Cuerpo *> MainWindow::listarCuerpos()
{
    return cuerpos;
}

void MainWindow::on_pushButtonIniciar_clicked()
{
    std::list<Cuerpo*> cuerpos = this->listarCuerpos();
    int numero_cuerpos = cuerpos.size();

    if (numero_cuerpos > 0)
    {
        ui->textBrowser->append( "Iniciando simulacion con " + QString::number(numero_cuerpos) + " cuerpos" );
        // this->enlazarCuerpos();
        this->correrSimulacion();
    }
    else
    {
        ui->textBrowser->append( "No se pudo iniciar la simulacion con " + QString::number(numero_cuerpos) + " cuerpos" );
    }
}

void MainWindow::on_pushButtonReset_clicked()
{
    ui->lcdNumber->display(0);
}
