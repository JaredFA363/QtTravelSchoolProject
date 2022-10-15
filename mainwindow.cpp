#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Register_clicked()
{
    hide();
    //shows register ui
    registerDialog = new RegisterDialog(this);
    registerDialog->show();
}


void MainWindow::on_pushButton_Login_clicked()
{
    hide();
    //shows login ui
    loginDialog = new LoginDialog(this);
    loginDialog ->show();
}


void MainWindow::on_pushButton_Admin_clicked()
{
    hide();
    //shows admin login ui
    adminDialog = new AdminDialog(this);
    adminDialog ->show();
}

