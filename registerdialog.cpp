#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <fstream>

using namespace std;

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_pushButton_clicked()
{
    //Get details from form
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();
    QString confirm = ui->lineEdit_confirm->text();

    if (password == confirm)
    {
        QFile file("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/users.txt");
        //Appends to file
        if (!file.open(QFile::Append | QFile::Text))
        {
            QMessageBox::warning(this,"Register","Error in opening file");
        }
        QTextStream out(&file);
        //Puts format to email,password and saves to textfile
        out <<"\n"<< email << "," << password;
        file.flush();
        file.close();
        QMessageBox::information(this,"Register","Successfully Registered");
        hide();
        //shows new ui
        detailsDialog = new DetailsDialog(this);
        detailsDialog->show();
    }
    else
    {
        QMessageBox::warning(this,"Register","Passwords do not match");
    }
}

