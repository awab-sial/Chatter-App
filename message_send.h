#ifndef MESSAGE_SEND_H
#define MESSAGE_SEND_H

#include <QDialog>
#include"inbox.h"
#include "qdialog.h"
#include "qobject.h"

namespace Ui {
class message_send;
}

class message_send : public QDialog
{
    Q_OBJECT

public:
    explicit message_send(QWidget *parent = nullptr);
    ~message_send();

private slots:
    void on_pushButton_send_message_2_clicked();

    void on_pushButton_logout_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::message_send *ui;
    inbox *in;
};

#endif // MESSAGE_SEND_H
