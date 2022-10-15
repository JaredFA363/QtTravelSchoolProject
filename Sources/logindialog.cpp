#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

using namespace std;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    static bool is_Login = false;
    QString email = ui->lineEdit_Logemail->text();
    QString password = ui->lineEdit_Logpass->text();
    QString input = email + "," + password;
    QFile file("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/users.txt");
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen())
    {
        QMessageBox::information(this,"Login","Error");
        return;
    }

    QTextStream stream(&file);
    while (!file.atEnd())
    {
    for (QString line = stream.readLine();
        !line.isNull();
         //Reads each line of textfile and compares to input
        line = stream.readLine()) {
        if (input == line)
        {
            QMessageBox::information(this,"Login","Credentials Found");
            is_Login = true;
            hide();
            //shows customer view ui
            Customerview = new customerview(this);
            Customerview->show();
            return;
        }
     }
    //if not found displays appropriate message
    if (is_Login == false)
    {
        QMessageBox::information(this,"Login","Credentials not Found");
    }

    };
    file.close();

}

