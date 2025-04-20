#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include<iostream>
#include<QFile>
#include<QTextStream>
#include<QPixmap>
#include<QColorDialog>
#include<QColor>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/Resources/pic1.png");

    int w=ui->label_pic->width();
    int h=ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    QImage Pic_bg(":/real/Resources/aunty.jpg");
    ui->bgpic->setScaledContents(true);
    ui->bgpic->setPixmap(QPixmap::fromImage(Pic_bg));
    ui->bgpic->setVisible(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();   //Storing input from line edit to username
    QString password = ui->lineEdit_password->text();   //Storing input from line edit to Password


    QFile a(username);  //opening a file

    if(!a.exists())     //Checking wheher file exists or not
    {
        // if not then showing warning box
        QMessageBox::warning(this,"Login","User Not Registered");
    }

    else if(!a.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Login","File Not Open");
    }
    else
    {

    QTextStream in(&a);

    QString test=in.readLine();     //reading a line from file
    QString pass=in.readLine();     //reading a line from file

    if(username == test && password == pass)    //if user input matches to file data
    {
        hide();
        QMessageBox::information(this,"Login","Logged in Successfully");    //Success message
        hide();     //Hiding Current Window
        after = new after_login(this);  //Shwing Second Dialog
        after->show();
    }
    else
    {
        QMessageBox::warning(this,"Login","Wrong Credentials Given");
    }
    }
}


void MainWindow::on_pushButton_signup_clicked() //When sigup is clicked show signup window
{
    hide();
    sign = new signup(this);
    sign->show();
}


void MainWindow::on_pushButton_backcolor_clicked()  //Function to change background color
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
        setPalette(QPalette(color));
    }
}

