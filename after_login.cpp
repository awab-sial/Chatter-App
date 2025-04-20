#include "after_login.h"
#include "message_send.h"

#include "ui_after_login.h"
#include<QMessageBox>
#include<iostream>
#include<QFile>
#include<QTextStream>
#include<QPixmap>
#include<QColorDialog>
#include<QColor>


after_login::after_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::after_login)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/Resources/pic1.png");

    int w=ui->label_pic2->width();
    int h=ui->label_pic2->height();
    ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

after_login::~after_login()
{
    delete ui;
}

void after_login::on_pushButton_proceed_clicked()
{
    QString option = ui->lineEdit_choice_3->text();
    int choice;
    choice = option.toInt();

    if(choice == 1)
    {
        QMessageBox::information(this,"Main Menu","Send Message Choosed");
        hide();
        send =new message_send(this);
        send->show();

    }
    else if(choice == 2)
    {
        QMessageBox::information(this,"Main Menu","Inbox Choosed");
        hide();
        in=new inbox(this);
        in->show();
    }
    else if(choice == 3)
    {
        QMessageBox::information(this,"Main Menu","Group Inbox Choosed");
        hide();
        gin=new g_c_inbox(this);
        gin->show();
    }
    else if(choice == 4)
    {
        QMessageBox::information(this,"Main Menu","Group Management Choosed");
        hide();
        g=new g_c(this);
        g->show();
    }
    else
        QMessageBox::warning(this,"Main Menu","Invalid Choice");

}


void after_login::on_pushButton_backcolor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid())
    {
        setPalette(QPalette(color));
    }

}

