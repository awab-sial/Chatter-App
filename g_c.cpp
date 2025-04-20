#include "g_c.h"
#include "ui_g_c.h"

#include<QMessageBox>
#include<iostream>
#include<QFile>
#include<QTextStream>
#include<QPixmap>
#include<QColorDialog>
#include<QColor>
using namespace std;

g_c::g_c(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g_c)
{
    ui->setupUi(this);
}

g_c::~g_c()
{
    delete ui;
}

void g_c::on_pushButton_clicked()
{
    QString g_name=ui->lineEdit->text();
    QString mem_name=ui->lineEdit_2->text();

    QString mem_file=g_name + "_members";

    QFile file(mem_file);   //Create a file same name as username

    if(file.exists())
    {
        QMessageBox::warning(this,"Error","Group Already Creatd");
    }
    else
    {
        file.open(QFile::Append);
        QTextStream out(&file);
        out<<mem_name<<Qt::endl;

        file.flush();
        file.close();
    }

    QFile gcfile(g_name);   //Create a file same name as username

    if(gcfile.exists())
    {
        QMessageBox::warning(this,"Error","Group Already Creatd");
    }
    else
    {

        if(!gcfile.open(QFile::WriteOnly | QFile::Text))  //Cheks whether file is open or not
        {
            QMessageBox::warning(this,"Login","File Not Open");    //Warning Message Box
        }
        gcfile.close();

        QMessageBox::information(this,"Success","Group Creatd Successfully");
    }
}


void g_c::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Information","Member Updation Wizard");

    QString g_name=ui->lineEdit_3->text();
    QString mem_name=ui->lineEdit_4->text();

    QString mem_file=g_name + "_members";
    int flag=0;

    QFile file(mem_file);

    if(!file.exists())
    {
        QMessageBox::warning(this,"Error"," No Group Found ");
    }
    else
    {

        if(!file.open(QFile::WriteOnly | QFile::Text))  //Cheks whether file is open or not
        {
            QMessageBox::warning(this,"Login","File Not Open");    //Warning Message Box
        }

        QTextStream in(&file);

        while(!file.atEnd())
        {
            QString name=in.readLine();

            if(name==mem_name)
            {
                if(ui->radioButton_2->isCheckable())
                {
                    flag = 1;
                }
                else
                    flag=2;
            }
            else
                QMessageBox::warning(this,"Error","No Memeber Found");
        }

        file.flush();
        file.close();
    }





}

