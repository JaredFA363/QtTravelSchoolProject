#ifndef DETAILSDIALOG_H
#define DETAILSDIALOG_H

#include <QDialog>
#include "logindialog.h"
class LoginDialog;

namespace Ui {
class DetailsDialog;
}

class DetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsDialog(QWidget *parent = nullptr);
    ~DetailsDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DetailsDialog *ui;
    LoginDialog *loginDialog;
};

#endif // DETAILSDIALOG_H
