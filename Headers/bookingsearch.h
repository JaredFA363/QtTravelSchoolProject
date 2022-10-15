#ifndef BOOKINGSEARCH_H
#define BOOKINGSEARCH_H

#include <QDialog>

namespace Ui {
class bookingsearch;
}

class bookingsearch : public QDialog
{
    Q_OBJECT

public:
    explicit bookingsearch(QWidget *parent = nullptr);
    ~bookingsearch();

private slots:
    void on_pushButton_clicked();

private:
    Ui::bookingsearch *ui;
};

#endif // BOOKINGSEARCH_H
