#include <QtGui>
#include <QtDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->append( "Iniciando simulacion" );

    Cuerpo c1 (1e7,30,30);
    Cuerpo c2 (1e3,0,50);
    Cuerpo c3 (1e3,50,0);
    Cuerpo c4 (1e3,20,0);

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

    QPen pen_blue(Qt::blue);
    // pen_blue.setWidth(5);
    // pen_blue.setCosmetic(true);
    QPen pen_green(Qt::green);
    QPen pen_red(Qt::red);
    QPen pen_yellow(Qt::yellow);

    for (int x = 0; x <= 500; x++)\
    {
        ui->textBrowser->append( "Bucle #" + QString::number(x) );

        this->scene->addLine(c1.posXPrev(), c1.posYPrev(), c1.posX(), c1.posY(), pen_blue);
        this->scene->addLine(c2.posXPrev(), c2.posYPrev(), c2.posX(), c2.posY(), pen_green);
        this->scene->addLine(c3.posXPrev(), c3.posYPrev(), c3.posX(), c3.posY(), pen_red);
        this->scene->addLine(c4.posXPrev(), c4.posYPrev(), c4.posX(), c4.posY(), pen_yellow);


        c1.actualizar();
        c2.actualizar();
        c3.actualizar();
        c4.actualizar();
    }
    ui->textBrowser->append( "Simulacion terminada" );

    // qDebug() << "Height: " << this->scene->height();
    // qDebug() << "C4 X: " << c4.posX();
    // qDebug() << "C4 Y: " << c4.posY();
}
