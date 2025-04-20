#include "message_send.h"
#include "ui_message_send.h"
#include"inbox.h"

#include<QMessageBox>
#include<iostream>
#include<QFile>
#include<QTextStream>
#include<QPixmap>
#include<QColorDialog>
#include<QColor>
#include<string>
using namespace std;

message_send::message_send(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message_send)
{
    ui->setupUi(this);
}

message_send::~message_send()
{
    delete ui;
}

void message_send::on_pushButton_send_message_2_clicked()
{
    QString user=ui->lineEdit_user_send_2->text();
    QString message=ui->lineEdit_message_send_2->text();



        QFile a(user);

        if(!a.exists())
        {
            QMessageBox::warning(this,"Login","Invalid UserName");

        }

        else{
        a.open(QFile::Append);

        QTextStream out(&a);
        out<<message<<Qt::endl;
        QMessageBox::information(this,"SignUp","Message Sent Successfully");
        }





}


void message_send::on_pushButton_logout_2_clicked()
{
    QMessageBox::information(this,"LogOut","Good Bye");
    QApplication::quit();
}


void message_send::on_pushButton_11_clicked()
{
    hide();
    in=new inbox();
    in->show();
}


void message_send::on_pushButton_9_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
        setPalette(QPalette(color));
    }
}


void message_send::on_pushButton_10_clicked()
{
    QMessageBox::information(this,"Send Message","Same Window Choosed");
}

