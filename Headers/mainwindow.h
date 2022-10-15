#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registerdialog.h"
#include "logindialog.h"
#include "admindialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Register_clicked();

    void on_pushButton_Login_clicked();

    void on_pushButton_Admin_clicked();

private:
    Ui::MainWindow *ui;
    RegisterDialog *registerDialog;
    LoginDialog *loginDialog;
    AdminDialog *adminDialog;
};
#endif // MAINWINDOW_H
