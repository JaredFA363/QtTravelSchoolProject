#ifndef CUSTOMERSEARCH_H
#define CUSTOMERSEARCH_H

#include <QDialog>

namespace Ui {
class customersearch;
}

class customersearch : public QDialog
{
    Q_OBJECT

public:
    explicit customersearch(QWidget *parent = nullptr);
    ~customersearch();

private slots:
    void on_pushButton_custsearch_clicked();

private:
    Ui::customersearch *ui;
};

#endif // CUSTOMERSEARCH_H
