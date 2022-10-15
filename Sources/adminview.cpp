#include "adminview.h"
#include "ui_adminview.h"

adminview::adminview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminview)
{
    ui->setupUi(this);
}

adminview::~adminview()
{
    delete ui;
}

void adminview::on_pushButton_clicked()
{
    hide();
    Customersearch = new customersearch(this);
    Customersearch->show();
}


void adminview::on_pushButton_booking_clicked()
{
    hide();
    Bookingsearch= new bookingsearch(this);
    Bookingsearch->show();
}

