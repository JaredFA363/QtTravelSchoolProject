#ifndef HOTELBOOKDIALOG_H
#define HOTELBOOKDIALOG_H

#include <QDialog>

namespace Ui {
class HotelbookDialog;
}

class HotelbookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HotelbookDialog(QWidget *parent = nullptr);
    ~HotelbookDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HotelbookDialog *ui;
};

#endif // HOTELBOOKDIALOG_H
