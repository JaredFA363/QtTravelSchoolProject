#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //opening and setting database
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/jared/OneDrive/Documents/Uni-C++/Y1project/travdb1.db");
    db.open();

    if (!db.open())
    {
        qDebug()<<"problem opening database";
    }
    else
    {
        //Preset values for database
        /*QSqlQuery qry;
        qry.prepare("INSERT INTO customer(email,firstname,surname,phone,address)"
                    "VALUES (?,?,?,?,?)");
        qry.addBindValue("jay@email.com");
        qry.addBindValue("jay");
        qry.addBindValue("smith");
        qry.addBindValue("07845333244");
        qry.addBindValue("dawn house,smith street,ng5 4nh");
        qry.exec();

        qry.prepare("INSERT INTO holidaycountry(country,airport)"
                    "VALUES (?,?)");
        qry.addBindValue("Spain");
        qry.addBindValue("Barcelona Airport");
        qry.exec();

        qry.prepare("INSERT INTO holidaycountry(country,airport)"
                    "VALUES (?,?)");
        qry.addBindValue("England");
        qry.addBindValue("Heathrow Airport");
        qry.exec();

        qry.prepare("INSERT INTO holidayflight(destcountry,sourcecountry,econfare,businessfare,firstfare)"
                    "VALUES (?,?,?,?,?)");
        qry.addBindValue("Spain");
        qry.addBindValue("England");
        qry.addBindValue(70.90);
        qry.addBindValue(100.78);
        qry.addBindValue(150.87);
        qry.exec();

        qry.prepare("INSERT INTO holidayflight(destcountry,sourcecountry,econfare,businessfare,firstfare)"
                    "VALUES (?,?,?,?,?)");
        qry.addBindValue("England");
        qry.addBindValue("Spain");
        qry.addBindValue(60.90);
        qry.addBindValue(90.78);
        qry.addBindValue(140.87);
        qry.exec();

        qry.prepare("INSERT INTO holidayhotel(hotelname,dailyprice,address,country)"
                    "VALUES (?,?,?,?)");
        qry.addBindValue("Barcelona Hotel");
        qry.addBindValue(30.87);
        qry.addBindValue("87 Canello street,Barcelona,SP3 4DD");
        qry.addBindValue("Spain");
        qry.exec();

        qry.prepare("INSERT INTO holidayhotel(hotelname,dailyprice,address,country)"
                    "VALUES (?,?,?,?)");
        qry.addBindValue("Cov Hotel");
        qry.addBindValue(55.90);
        qry.addBindValue("11 Coven street,Victoria,SW11 3GH");
        qry.addBindValue("England");
        qry.exec();*/

    }

    db.close();
    MainWindow w;
    w.show();
    return a.exec();
}
