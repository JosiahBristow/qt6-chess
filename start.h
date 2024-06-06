#ifndef START_H
#define START_H

#include <QDialog>

namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    static bool normal;
    static bool queen;
    static bool queenpro;
    static bool knight;
    explicit start(QWidget *parent = nullptr);
    ~start();


private slots:

    void on_queen_clicked();

    void on_normal_clicked();

    void on_queenpro_clicked();

    void on_queenpro_2_clicked();

private:
    Ui::start *ui;
};

#endif // START_H
