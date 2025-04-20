#include "inbox.h"
#include "ui_inbox.h"

#include<QMessageBox>
#include<iostream>
#include<QFile>
#include<QTextStream>
#include<QPixmap>
#include<QColorDialog>
#include<QColor>
using namespace std;

inbox::inbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inbox)
{
    ui->setupUi(this);

    /*QImage Pic_bg(":/3rd/Resources/inbox.jpg");
    ui->bg_inbox->setScaledContents(true);
    ui->bg_inbox->setPixmap(QPixmap::fromImage(Pic_bg));
    ui->bg_inbox->setVisible(true);*/
}

inbox::~inbox()
{
    delete ui;
}

void inbox::on_pushButton_authenticate_clicked()
{
    QString user=ui->lineEdit_username->text();
    QString pass=ui->lineEdit_password->text();

    QFile a(user);

    if(!a.exists())
    {
        QMessageBox::warning(this,"Login","Wrong Credetials Try Again");

    }

    else if(!a.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Login","File Not Open");
    }

    QTextStream in(&a);

    QString test=in.readLine();
    QString password=in.readLine();
    QString text=in.readAll();

    if(user == test && password == pass)
    {
        QMessageBox::information(this,"Success","Authentication Successful");



        ui->plainTextEdit->setPlainText(text);
    }
    else
        QMessageBox::warning(this,"Error"," Invalid Credentials Provided !");
    a.close();


}


void inbox::on_pushButton_exit_clicked()
{
    QApplication::quit();
}


void inbox::on_pushButton_9_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
        setPalette(QPalette(color));
    }
}


void inbox::on_pushButton_11_clicked()
{
    QMessageBox::information(this,"Inbox","Same Window Choosed");
}


void inbox::on_pushButton_10_clicked()
{
    //
}

