#include "start.h"
#include "ui_start.h"
#include "setting.h"
#include <QApplication>
#include "start.h"
start::start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    this->setWindowTitle("start");
    this->setWindowIcon(QIcon(":/pics/pic/black king.png"));
}

start::~start()
{
    delete ui;
}

    bool start::normal=0;
    bool start::queen=0;
    bool start::queenpro=0;
    bool start::knight=0;
void start::on_queen_clicked()
{
    queen=1;
    setting *w=new setting;
    w->show();
}

void start::on_normal_clicked()
{
    normal=1;
    setting *w=new setting;
    w->show();
}

void start::on_queenpro_clicked()
{
    queenpro=1;
    setting *w=new setting;
    w->show();
}

void start::on_queenpro_2_clicked()
{
    knight=1;
    setting *w=new setting;
    w->show();
}
