#ifndef ADDNEWBODYDIALOG_H
#define ADDNEWBODYDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewBodyDialog;
}

class AddNewBodyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewBodyDialog(QWidget *parent = 0);
    ~AddNewBodyDialog();
    QString getNombre();
    int getMasa();
    int getPosX();
    int getPosY();
    int getVelX();
    int getVelY();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddNewBodyDialog *ui;
};

#endif // ADDNEWBODYDIALOG_H
