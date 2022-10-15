#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "detailsdialog.h"

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegisterDialog *ui;
    //object class details dialog opens details ui
    DetailsDialog *detailsDialog;
};

#endif // REGISTERDIALOG_H
