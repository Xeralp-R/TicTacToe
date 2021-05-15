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
class QGroupBox;
QT_END_NAMESPACE

// The Game Settings
class GameSettings : public QWidget
{
    Q_OBJECT
public:
    explicit GameSettings(QMediaPlayer * player,
                          GameOptions old_style = GameOptions::SoloGame,
                          PlaylistOptions old_playlist = PlaylistOptions::RexPlaylist,
                          QWidget *parent = nullptr);
    //QMediaPlayer * gs_music_player;
    //QSlider * gsettings_volumeslider1;
    GameOptions getGameOption();
    PlaylistOptions getPlaylistOption();
signals:
    void back_to_home();
    void play_brent_playlist();
    void play_rex_playlist();
private slots:
    // the slot which sets the current game options
    // this game option will be sent to the titular
    void clicked_sologame();
    void clicked_tourneygame();
    void clicked_brentrbtgame();
    void clicked_randrbtgame();
    void clicked_rexplaylist();
    void clicked_brentplaylist();
private:
    // ==> Variable
    GameOptions current_style;
    PlaylistOptions current_playlist;
    
    // ==> Visible Things
    // General Layout and Title
    QVBoxLayout * gsettings_layout_general;
    QLabel * gsettings_title;
    
    // Choice 1: modes
    QVBoxLayout * gsettings_layout_choice1box;
    QGroupBox * gsettings_choice1box;
    QLabel * gsettings_subtitle1;
    QRadioButton * gsettings_choice1_1;
    QRadioButton * gsettings_choice1_2;
    QRadioButton * gsettings_choice1_3;
    QRadioButton * gsettings_choice1_4;
    
    // Choice 2: playlist options
    QVBoxLayout * playlist_layout;
    QGroupBox * playlist_box;
    QLabel * playlist_subtitle;
    QRadioButton * playlist_choice1;
    QRadioButton * playlist_choice2;
    
    // Choice 3: volume slider
    QVBoxLayout * gsettings_layout_volumebox;
    QWidget * gsettings_volumebox;
    QLabel * gsettings_subtitle2;
    QSlider * gsettings_volumeslider1;
    
    // The button back home
    QPushButton * gsettings_button_home;
};

#endif /* gamesettings_h */
