#include "titular.h"
//#include "tttgame.hpp"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    //QFontDatabase::addApplicationFont(":/fonts/SIFONN.otf");
    QApplication a(argc, argv);
    Titular title;
    //TTTGame play;
    //w.show();
    return a.exec();
}
