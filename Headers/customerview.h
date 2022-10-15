#ifndef CUSTOMERVIEW_H
#define CUSTOMERVIEW_H

#include <QDialog>
#include "hotelbookdialog.h"

//class DetailsDialog;

namespace Ui {
class customerview;
}

class customerview : public QDialog
{
    Q_OBJECT

public:
    explicit customerview(QWidget *parent = nullptr);
    ~customerview();

private slots:
    void on_pushButton_clicked();

private:
    Ui::customerview *ui;
    HotelbookDialog *hotelbookdialog;

};

#endif // CUSTOMERVIEW_H
