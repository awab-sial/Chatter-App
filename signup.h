#ifndef SIGNUP_H
#define SIGNUP_H

#include "qdialog.h"
#include "qtmetamacros.h"
#include "qwidget.h"
#include <QDialog>
namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_backcolor_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::signup *ui;

};

#endif // SIGNUP_H

