#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include "adminview.h"

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = nullptr);
    ~AdminDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdminDialog *ui;
    adminview *Adminview;
};

#endif // ADMINDIALOG_H
