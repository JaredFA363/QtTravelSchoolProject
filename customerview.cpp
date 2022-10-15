#include "customerview.h"
#include "ui_customerview.h"
#include <QtSql>
#include <QMessageBox>
#include <iostream>

using namespace std;

customerview::customerview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerview)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/travdb1.db");
    db.open();

    QSqlQuery qry;

    ui->comboBox_location->addItem("Location");
    ui->comboBox_init_location->addItem("Departure Location");
    //Queries db for countries in the db
    if (qry.exec("SELECT [country] FROM [holidaycountry]"))
    {
        for (int i = 0;qry.next();i++)
        {
            ui->comboBox_location->addItem(qry.value(0).toString());
            ui->comboBox_init_location->addItem(qry.value(0).toString());
        }
    }

    ui->comboBox_time->addItem("Departure Flight Time");
    ui->comboBox_time->addItem("09:00");
    ui->comboBox_time->addItem("12:00");
    ui->comboBox_time->addItem("15:00");
    ui->comboBox_time->addItem("19:00");

    ui->comboBox_returntime->addItem("Return Flight Time");
    ui->comboBox_returntime->addItem("09:00");
    ui->comboBox_returntime->addItem("12:00");
    ui->comboBox_returntime->addItem("15:00");
    ui->comboBox_returntime->addItem("19:00");

    ui->comboBox_fare->addItem("Class");
    ui->comboBox_fare->addItem("Economy");
    ui->comboBox_fare->addItem("Business");
    ui->comboBox_fare->addItem("First");
    db.close();
}

customerview::~customerview()
{
    delete ui;
}

void customerview::on_pushButton_clicked()
{
    QString ref = ui->lineEdit_ref->text();
    QString init_location = ui->comboBox_init_location->currentText();
    QString location = ui->comboBox_location->currentText();
    QString time = ui->comboBox_time->currentText();
    QString fare = ui->comboBox_fare->currentText();
    QString return_time = ui->comboBox_returntime->currentText();
    if (init_location == location)
    {
        QMessageBox::information(this,"Booking","Departure & Arrival locations the same");
    }
    else
    {
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/travdb1.db");
        db.open();

        //inserts values in db
        QSqlQuery query;
        query.prepare("INSERT INTO flight(init_location,final_location,class,deptime,return_time,cust_id)"
                      "VALUES (?,?,?,?,?,?)");
        query.addBindValue(init_location);
        query.addBindValue(location);
        query.addBindValue(fare);
        query.addBindValue(time);
        query.addBindValue(return_time);
        query.addBindValue(ref);
        query.exec();

        //changes value for each class chosen
        QString location_2 =  "'"+location+"'";
        if (fare == "Economy")
        {
            if (query.exec("SELECT econfare FROM holidayflight WHERE destcountry="+location_2+""))
            {
                for (int i = 0;query.next();i++)
                {
                    hide();
                    QMessageBox::information(this,"flightfare","FlightFare"+query.value(0).toString()+"£");
                    hide();
                    query.exec("SELECT hotelname FROM holidayhotel WHERE country="+location_2+"");
                    query.next();
                    QMessageBox::information(this,"Hotel","Hotel: "+query.value(0).toString());
                    query.exec("SELECT dailyprice FROM holidayhotel WHERE country="+location_2+"");
                    query.next();
                    QMessageBox::information(this,"Hotel","DailyPrice: "+query.value(0).toString()+" £");
                }
            }
        }
        else if (fare == "Business")
        {
            if (query.exec("SELECT businessfare FROM holidayflight WHERE destcountry="+location_2+""))
            {
                for (int i = 0;query.next();i++)
                {
                    hide();
                    QMessageBox::information(this,"flightfare","FlightFare"+query.value(0).toString()+"£");
                    hide();
                    query.exec("SELECT hotelname FROM holidayhotel WHERE country="+location_2+"");
                    query.next();
                    QMessageBox::information(this,"Hotel","Hotel: "+query.value(0).toString());
                    query.exec("SELECT dailyprice FROM holidayhotel WHERE country="+location_2+"");
                    query.next();
                    QMessageBox::information(this,"Hotel","DailyPrice: "+query.value(0).toString()+" £");
                }
            }
        }
        else if (fare == "First")
        {
            if (query.exec("SELECT firstfare FROM holidayflight WHERE destcountry="+location_2+""))
            {
                for (int i = 0;query.next();i++)
                {
                    hide();
                    QMessageBox::information(this,"flightfare","FlightFare "+query.value(0).toString()+" £");
                    hide();
                    query.exec("SELECT hotelname FROM holidayhotel WHERE country="+location_2+"");
                    query.next();
                    QMessageBox::information(this,"Hotel","Hotel: "+query.value(0).toString());
                    query.exec("SELECT dailyprice FROM holidayhotel WHERE country="+location_2+"");
                    query.next();
                    QMessageBox::information(this,"Hotel","DailyPrice: "+query.value(0).toString()+" £");
                }
            }
        }
        db.close();
        hide();
        hotelbookdialog = new HotelbookDialog(this);
        hotelbookdialog->show();
    }
}


