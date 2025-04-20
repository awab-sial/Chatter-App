#include "signup.h"
#include "ui_signup.h"  //Header file to open ui file of signup

#include<QMessageBox>
#include<iostream>
#include<QFile>
#include<QTextStream>
#include<QPixmap>
#include<QColorDialog>
#include<QColor>
using namespace std;

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/Resources/pic1.png");  //TO show picture in picture_label

    int w=ui->label_pic_register->width();
    int h=ui->label_pic_register->height();
    ui->label_pic_register->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio)); //Displays Picture

    QImage Pic_bg(":/3rd/Resources/IMG-20230111-WA0022.jpg");
    ui->bg_signup->setScaledContents(true);
    ui->bg_signup->setPixmap(QPixmap::fromImage(Pic_bg));
    ui->bg_signup->setVisible(true);

}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_backcolor_clicked()  //Button to change background color
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");   //Shows color Dialog
    if(color.isValid()) //Checks whether color is valid or not
    {
        setPalette(QPalette(color)); // If color is valid, sets background color
    }
}


void signup::on_pushButton_register_clicked()
{
    QString name = ui->lineEdit_name->text();   // Store data received from user in name string
    QString username = ui->lineEdit_username->text();   // Store data received from user in username string (also used in file handling)
    QString password = ui->lineEdit_password->text();   // Store data received from user in password string

    QFile file(username);   //Create a file same name as username

    if(file.exists())
    {
        QMessageBox::warning(this,"Error","Username Already Occupied");
    }
    else
    {

    if(!file.open(QFile::WriteOnly | QFile::Text))  //Cheks whether file is open or not
    {
         QMessageBox::warning(this,"Login","File Not Open");    //Warning Message Box
    }
    QTextStream out(&file);
    out<<username<<Qt::endl;    //Writes username in the file
    out<<password<<Qt::endl;    //Writes password in the file
    file.flush();   //Making sure data is written
    file.close();   //Closing the File

    QMessageBox::information(this,"SignUp","Registration Successful"); //Message for successful registration
    }

}

