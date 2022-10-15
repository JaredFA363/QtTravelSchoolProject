#include "hotelbookdialog.h"
#include "ui_hotelbookdialog.h"
#include <QtSql>
#include <QMessageBox>

HotelbookDialog::HotelbookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotelbookDialog)
{
    ui->setupUi(this);
}

HotelbookDialog::~HotelbookDialog()
{
    delete ui;
}

void HotelbookDialog::on_pushButton_clicked()
{
    QString ref = ui->lineEdit_ref->text();
    QString startdate = ui->lineEdit_startdate->text();
    QString enddate = ui->lineEdit_enddate->text();
    QString numofdays = ui->lineEdit_numofdays->text();
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/travdb1.db");
    db.open();
    QSqlQuery qry;

    //Inserts choices into database
    qry.prepare("INSERT INTO hotelbooking(startdate,enddate,numofdays,cust_id)"
                "VALUES (?,?,?,?)");
    qry.addBindValue(startdate);
    qry.addBindValue(enddate);
    qry.addBindValue(numofdays);
    qry.addBindValue(ref);
    qry.exec();
    db.close();
    QMessageBox::information(this,"Hotel","Booked Thank you for using our service");
    hide();
}

