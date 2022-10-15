#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QDialog>
#include "bookingsearch.h"
#include "customersearch.h"

namespace Ui {
class adminview;
}

class adminview : public QDialog
{
    Q_OBJECT

public:
    explicit adminview(QWidget *parent = nullptr);
    ~adminview();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_booking_clicked();

private:
    Ui::adminview *ui;
    bookingsearch *Bookingsearch;
    customersearch *Customersearch;
};

#endif // ADMINVIEW_H
