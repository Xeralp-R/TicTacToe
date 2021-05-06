//#include "titular.h"
#include "tourneygame.hpp"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    //QFontDatabase::addApplicationFont(":/fonts/SIFONN.otf");
    QApplication a(argc, argv);
    //Titular title;
    TourneyGame play;
    //w.show();
    return a.exec();
}
