# This apparently serves a notable purpose.
QT  += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    helpscreen.cpp \
    main.cpp \
    titular.cpp \
    gamesettings.cpp \
    playersettings.cpp \
    aboutus.cpp \
    tttgame.cpp \
    victory.cpp \
    draw.cpp \
    tourneygame.cpp \
    robotgame.cpp

HEADERS += \
    helpscreen.h \
    titular.h \
    gamesettings.h \
    playersettings.hpp \
    aboutus.hpp \
    tttgame.hpp \
    victory.hpp \
    draw.hpp \
    tourneygame.hpp \
    gameoptions.hpp \
    robotoptions.h \
    robotgame.hpp

DISTFILES += \
    TicTacToe.xcodeproj

RESOURCES += \
    overarching.qrc

#icons
win32 {
    RC_ICON += tictactoe.ico
}
macx {
    ICON += tictactoe.icns
}
