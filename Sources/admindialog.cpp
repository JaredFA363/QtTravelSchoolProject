#include "admindialog.h"
#include "ui_admindialog.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

using namespace std;

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::on_pushButton_clicked()
{
    static bool is_Login = false;
    QString email = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Adminpass->text();
    QString input = email + "," + password;
    QFile file("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/admins.txt");
    file.open(QIODevice::ReadOnly);
    if (!file.isOpen())
    {
        QMessageBox::information(this,"Admin Login","Error");
        return;
    }

    QTextStream stream(&file);
    while (!file.atEnd())
    {
    for (QString line = stream.readLine();
        !line.isNull();
        line = stream.readLine()) {
        if (input == line)
        {
            QMessageBox::information(this,"Login","Welcome Admin");
            is_Login = true;
            hide();
            Adminview = new adminview(this);
            Adminview->show();
            return;
        }
     }
    if (is_Login == false)
    {
        QMessageBox::information(this,"Login","Credentials not Found");
    }

    };
    file.close();
}

