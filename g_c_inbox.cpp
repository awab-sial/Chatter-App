#include "g_c_inbox.h"
#include "ui_g_c_inbox.h"

#include<QMessageBox>
#include<iostream>
#include<QFile>
#include<QTextStream>
#include<QPixmap>
#include<QColorDialog>
#include<QColor>
using namespace std;

g_c_inbox::g_c_inbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g_c_inbox)
{
    ui->setupUi(this);
}

g_c_inbox::~g_c_inbox()
{
    delete ui;
}

void g_c_inbox::on_pushButton_authenticate_2_clicked()
{
    QString name=ui->lineEdit_username_2->text();
    QString g_name=ui->lineEdit_group_name->text();

    QString mem_file=g_name + "_members";

    QFile file(mem_file);
    int flag;

    if(!file.exists())
    {
        QMessageBox::warning(this,"Error"," No Group Found ");
    }
    else
    {

        if(!file.open(QFile::ReadOnly | QFile::Text))  //Cheks whether file is open or not
        {
            QMessageBox::warning(this,"Login","File Not Open");    //Warning Message Box
        }

        QTextStream in(&file);

        while(!file.atEnd())
        {
            QString mem_name=in.readLine();

            if(name==mem_name)
            {

                    flag = 1;

            }
            else
                QMessageBox::warning(this,"Error","No Memeber Found");
        }

        if(flag)
        {
            QFile file(g_name);

            if(!file.exists())
            {
                QMessageBox::warning(this,"Error"," No Group Found ");
            }
            else
            {

                if(!file.open(QFile::ReadOnly | QFile::Text))  //Cheks whether file is open or not
                {
                    QMessageBox::warning(this,"Login","File Not Open");    //Warning Message Box
                }

                QTextStream in(&file);
                QString text = in.readAll();

                ui->plainTextEdit_2->setPlainText(text);

            }
        }
    }
}
