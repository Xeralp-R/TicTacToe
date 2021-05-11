#include "titular.h"
//#include "tourneygame.hpp"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // set up the fonts
    QFontDatabase font_db;
    font_db.addApplicationFont(":/fonts/Quicksand-Regular.ttf");
    font_db.addApplicationFont(":/fonts/Quicksand-Bold.ttf");
    font_db.addApplicationFont(":/fonts/SIFONN.otf");
    font_db.addApplicationFont(":/fonts/Everson-Mono-Unicode-Regular.ttf");
    // call the title
    Titular title;
    //TourneyGame play;
    //w.show();
    return a.exec();
}
