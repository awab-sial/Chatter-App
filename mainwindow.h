#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"signup.h"
#include"after_login.h"
#include"message_send.h"
#include"inbox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();

    void on_pushButton_backcolor_clicked();

private:
    Ui::MainWindow *ui;
    after_login *after;
    signup *sign;
    message_send *send;
    inbox *in;
};
#endif // MAINWINDOW_H
