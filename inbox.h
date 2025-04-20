#ifndef INBOX_H
#define INBOX_H


#include "qdialog.h"
#include "ui_inbox.h"
#include <QDialog>

class inbox : public QDialog
{
    Q_OBJECT
public:
    explicit inbox(QWidget *parent = nullptr);
    ~inbox();

private slots:
    void on_pushButton_authenticate_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::inbox *ui;
};

#endif // INBOX_H
