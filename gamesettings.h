//
//  gamesettings.h
//  Maybe
//
//  Created by Reventar on 17/04/2021.
//

#ifndef gamesettings_h
#define gamesettings_h

#include "gameoptions.hpp"

#include <QWidget>
#include <QMediaPlayer>
#include <QSlider>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QFrame;
//class QMediaPlayer;
class QMediaPlaylist;
//class QSlider;
class QRadioButton;
class QVBoxLayout;
QT_END_NAMESPACE

// The Game Settings
class GameSettings : public QWidget
{
    Q_OBJECT
public:
    explicit GameSettings(QMediaPlayer * player, GameOptions old_style = GameOptions::SoloGame, QWidget *parent = nullptr);
    //QMediaPlayer * gs_music_player;
    //QSlider * gsettings_volumeslider1;
    GameOptions getGameOption();
signals:
    void back_to_home();
private slots:
    // the slot which sets the current game options
    // this game option will be sent to the titular
    void clicked_sologame();
    void clicked_tourneygame();
    void clicked_brentrbtgame();
    void clicked_randrbtgame();
private:
    // ==> Variable
    GameOptions current_style;
    
    // ==> Visible Things
    // General Layout and Title
    QVBoxLayout * gsettings_layout_general;
    QLabel * gsettings_title;
    
    // Choice 1: modes
    QVBoxLayout * gsettings_layout_choice1box;
    QWidget * gsettings_choice1box;
    QLabel * gsettings_subtitle1;
    QRadioButton * gsettings_choice1_1;
    QRadioButton * gsettings_choice1_2;
    QRadioButton * gsettings_choice1_3;
    QRadioButton * gsettings_choice1_4;
    
    // Choice 2: volume slider
    QVBoxLayout * gsettings_layout_volumebox;
    QWidget * gsettings_volumebox;
    QLabel * gsettings_subtitle2;
    QSlider * gsettings_volumeslider1;
    
    // The button back home
    QPushButton * gsettings_button_home;
};

#endif /* gamesettings_h */
