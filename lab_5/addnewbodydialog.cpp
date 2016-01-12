#include "addnewbodydialog.h"
#include "ui_addnewbodydialog.h"

AddNewBodyDialog::AddNewBodyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewBodyDialog)
{
    ui->setupUi(this);
}

AddNewBodyDialog::~AddNewBodyDialog()
{
    delete ui;
}

void AddNewBodyDialog::on_buttonBox_accepted()
{
    this->setResult(QDialog::Accepted);
}

void AddNewBodyDialog::on_buttonBox_rejected()
{
    this->setResult(QDialog::Rejected);
}

QString AddNewBodyDialog::getNombre()
{
    return ui->lineEditNombre->text();
}

int AddNewBodyDialog::getMasa()
{
    return ui->SliderMasa->value();
}

int AddNewBodyDialog::getPosX()
{
    return ui->dialposx->value();
}

int AddNewBodyDialog::getPosY()
{
    return ui->dialposy->value();
}

int AddNewBodyDialog::getVelX()
{
    return ui->dialvelx->value();
}

int AddNewBodyDialog::getVelY()
{
    return ui->dialvely->value();
}
