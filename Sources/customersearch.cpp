#include "customersearch.h"
#include "ui_customersearch.h"
#include <QtSql>

using namespace std;

customersearch::customersearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customersearch)
{
    ui->setupUi(this);
}

customersearch::~customersearch()
{
    delete ui;
}

void customersearch::on_pushButton_custsearch_clicked()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/travdb1.db");
    db.open();

    QString email =  ui->lineEdit_custsearch->text();
    QString eemail = "'"+email+"'";

    QSqlQuery qry;

    //Queries db using user input
    //Displays into line edits
    QString dets = "SELECT firstname FROM customer WHERE email="+eemail+"";

    if (qry.exec(dets))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->lineEdit_first->setText(qry.value(0).toString());
        }
    }

    if (qry.exec("SELECT surname FROM customer WHERE email="+eemail+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->lineEdit_sur->setText(qry.value(0).toString());
        }
    }

    if (qry.exec("SELECT address FROM customer WHERE email="+eemail+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->lineEdit_add->setText(qry.value(0).toString());
        }
    }

    if (qry.exec("SELECT phone FROM customer WHERE email="+eemail+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->lineEdit_phone->setText(qry.value(0).toString());
        }
    }
    db.close();

}

