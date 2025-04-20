#ifndef G_C_INBOX_H
#define G_C_INBOX_H

#include <QDialog>

namespace Ui {
class g_c_inbox;
}

class g_c_inbox : public QDialog
{
    Q_OBJECT

public:
    explicit g_c_inbox(QWidget *parent = nullptr);
    ~g_c_inbox();

private slots:
    void on_pushButton_authenticate_2_clicked();

private:
    Ui::g_c_inbox *ui;
};

#endif // G_C_INBOX_H
