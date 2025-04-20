#ifndef AFTER_LOGIN_H
#define AFTER_LOGIN_H

#include <QDialog>
#include"message_send.h"
#include"inbox.h"
#include "g_c.h"
#include "g_c_inbox.h"



namespace Ui {
class after_login;
}

class after_login : public QDialog
{
    Q_OBJECT
public:
    explicit after_login(QWidget *parent = nullptr);
    ~after_login();

private slots:
    void on_pushButton_proceed_clicked();

    void on_pushButton_backcolor_clicked();

private:
    Ui::after_login *ui;
    message_send *send;
    inbox *in;
    g_c *g;
    g_c_inbox *gin;
};

#endif // AFTER_LOGIN_H
