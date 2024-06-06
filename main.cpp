#include "setting.h"
#include <QApplication>
#include "start.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start s;
    s.show();
    return a.exec();
}
