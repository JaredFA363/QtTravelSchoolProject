#include "detailsdialog.h"
#include "ui_detailsdialog.h"
#include <QSettings>
#include <QtSql>

using namespace std;

DetailsDialog::DetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsDialog)
{
    ui->setupUi(this);
}

DetailsDialog::~DetailsDialog()
{
    delete ui;
}

void DetailsDialog::on_pushButton_clicked()
{
    QString address = ui->textEdit_address->toPlainText();
    QString email = ui->lineEdit_detemail->text();
    QString phone = ui->lineEdit_phone->text();
    QString firstname = ui->lineEdit_firstname->text();
    QString surname = ui->lineEdit_surname->text();

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/travdb1.db");
    //open db
    db.open();

    if (!db.open())
    {
        qDebug()<<"problem opening database";
    }
    else
    {
        //inserts details to db
        QSqlQuery qry;
        qry.prepare("INSERT INTO customer(email,firstname,surname,phone,address)"
                    "VALUES (?,?,?,?,?)");
        qry.addBindValue(email);
        qry.addBindValue(firstname);
        qry.addBindValue(surname);
        qry.addBindValue(phone);
        qry.addBindValue(address);
        qry.exec();
        db.close();
        hide();
        loginDialog = new LoginDialog(this);
        loginDialog ->show();
    }
}

