#include "bookingsearch.h"
#include "ui_bookingsearch.h"
#include <QtSql>

bookingsearch::bookingsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookingsearch)
{
    ui->setupUi(this);
}

bookingsearch::~bookingsearch()
{
    delete ui;
}

void bookingsearch::on_pushButton_clicked()
{
    QString ref = ui->lineEdit_ref2->text();
    QString ref2 = "'"+ref+"'";

    //Queries db using input
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/travdb1.db");
    db.open();

    QSqlQuery qry;

    if (qry.exec("SELECT init_location FROM flight WHERE cust_id="+ref2+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->init_location->setText(qry.value(0).toString());
        }
    }

    if (qry.exec("SELECT final_location FROM flight WHERE cust_id="+ref2+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->final_location->setText(qry.value(0).toString());
        }
    }

    if (qry.exec("SELECT class FROM flight WHERE cust_id="+ref2+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->class_2->setText(qry.value(0).toString());
        }
    }
    if (qry.exec("SELECT deptime FROM flight WHERE cust_id="+ref2+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->deptime->setText(qry.value(0).toString());
        }
    }

    if (qry.exec("SELECT return_time FROM flight WHERE cust_id="+ref2+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->return_time->setText(qry.value(0).toString());
        }
    }

    if (qry.exec("SELECT startdate FROM hotelbooking WHERE cust_id="+ref2+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->startdate->setText(qry.value(0).toString());
        }
    }

    if (qry.exec("SELECT enddate FROM hotelbooking WHERE cust_id="+ref2+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->enddate->setText(qry.value(0).toString());
        }
    }

    QString country = ui->final_location->text();
    QString country2 = "'"+country+"'";
    if (qry.exec("SELECT hotelname FROM holidayhotel WHERE country="+country2+""))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->hotel->setText(qry.value(0).toString());
        }
    }
    db.close();
}

