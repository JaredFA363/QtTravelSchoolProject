#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "customerview.h"
class customerview;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
    customerview *Customerview;

};

#endif // LOGINDIALOG_H
