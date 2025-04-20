#ifndef G_C_H
#define G_C_H

#include <QDialog>

namespace Ui {
class g_c;
}

class g_c : public QDialog
{
    Q_OBJECT

public:
    explicit g_c(QWidget *parent = nullptr);
    ~g_c();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::g_c *ui;
};

#endif // G_C_H
