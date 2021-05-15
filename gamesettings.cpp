//
//  gamesettings.cpp
//  Maybe
//
//  Created by Reventar on 17/04/2021.
//

//#include <stdio.h>
// To be the file that defines the game settings
#include "gamesettings.h"
// the fiel that includes the enum class game options
#include "gameoptions.hpp"
// to get the correct value for the music player
#include "titular.h"
// to interact with the app
#include <QApplication>
// the layout stuff
#include <QVBoxLayout>
// push button, to exit to home
#include <QPushButton>
// radio button, to choose the mode
#include <QRadioButton>
// label, for the titles and subtitles
#include <QLabel>
// slider to pick the volume
#include <QSlider>
// media player to change the volume
#include <QMediaPlayer>
// file to include the styles
#include <QFile>
// strings for the styles to go somewhere
#include <QString>
// the grouping box
#include <QGroupBox>

GameSettings::GameSettings(QMediaPlayer * player,
                           GameOptions old_style,
                           PlaylistOptions old_playlist,
                           QWidget *parent) : QWidget(parent) {
    const int text_max_height = 40;
    const int button_max_height = 50;
    const int title_text_max_height = 100;
    //const int regul_text_max_height = 150;
    const int slider_min_width = 450;
    
    current_style = old_style;
    current_playlist = old_playlist;
    
    setMinimumSize(600, 450);
    setWindowTitle("Game Settings");
    
    // The Title
    gsettings_title = new QLabel("Settings", this);
    gsettings_title->setAlignment(Qt::AlignCenter);
    gsettings_title->setMaximumHeight(title_text_max_height);
    gsettings_title->setObjectName("title");
    
    // Pick Game Mode
    gsettings_choice1box = new QGroupBox(this);
    gsettings_subtitle1 = new QLabel("Please pick your game mode:", gsettings_choice1box);
    gsettings_subtitle1->setMaximumHeight(text_max_height);
    gsettings_subtitle1->setObjectName("subtitle");
    gsettings_subtitle1->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    gsettings_choice1_1 = new QRadioButton("Regular Mode", gsettings_choice1box);
    gsettings_choice1_1->setObjectName("rad_butn");
    gsettings_choice1_2 = new QRadioButton("Tournament Mode", gsettings_choice1box);
    gsettings_choice1_2->setObjectName("rad_butn");
    gsettings_choice1_3 = new QRadioButton("Against Brent's Robot", gsettings_choice1box);
    gsettings_choice1_3->setObjectName("rad_butn");
    gsettings_choice1_4 = new QRadioButton("Against Random Robot", gsettings_choice1box);
    gsettings_choice1_4->setObjectName("rad_butn");
    // set things as checked as necessary
    switch (old_style) {
        //case GameOptions::NullGame:
        case GameOptions::SoloGame:
            gsettings_choice1_1->setChecked(true);
            break;
        case GameOptions::TourneyGame:
            gsettings_choice1_2->setChecked(true);
            break;
        case GameOptions::BrentRobotGame:
            gsettings_choice1_3->setChecked(true);
            break;
        case GameOptions::RandRobotGame:
            gsettings_choice1_4->setChecked(true);
            break;
        default:
            // I'm not sure what to do here
            break;
    }
    
    // I'm not sure if there should be a vbox.
    gsettings_layout_choice1box = new QVBoxLayout(gsettings_choice1box);
    gsettings_layout_choice1box->addWidget(gsettings_subtitle1);
    gsettings_layout_choice1box->addWidget(gsettings_choice1_1);
    gsettings_layout_choice1box->addWidget(gsettings_choice1_2);
    gsettings_layout_choice1box->addWidget(gsettings_choice1_3);
    gsettings_layout_choice1box->addWidget(gsettings_choice1_4);
    
    // ==> Set the playlist
    // subtitle
    playlist_subtitle = new QLabel("Please pick your playlist");
    playlist_subtitle->setMaximumHeight(text_max_height);
    playlist_subtitle->setObjectName("subtitle");
    playlist_subtitle->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    // choice 1: Rex
    playlist_choice1 = new QRadioButton();
    playlist_choice1->setText("Rex's Playlist");
    playlist_choice1->setToolTip("Classical: Excerpts from Camille Saint Saens' "
                                 "Carnival of the Animals");
    playlist_choice1->setObjectName("radbutn");
    // choice 2: Brent
    playlist_choice2 = new QRadioButton();
    playlist_choice2->setText("Brent's Playlist");
    playlist_choice2->setToolTip("Modern: Excerpts from the games Cytus "
                                 "and Glow, and the cartoon Jojo's Bizzare Adventure");
    playlist_choice2->setObjectName("radbutn");
    // switch the current choice
    switch (old_playlist) {
        case PlaylistOptions::RexPlaylist:
            playlist_choice1->setChecked(true);
            break;
        case PlaylistOptions::BrentPlaylist:
            playlist_choice2->setChecked(true);
            break;
        default:
            // I really have no idea for what to do here
            break;
    }
    // the vboxlayout
    playlist_layout = new QVBoxLayout();
    playlist_layout->addWidget(playlist_subtitle);
    playlist_layout->addWidget(playlist_choice1);
    playlist_layout->addWidget(playlist_choice2);
    // the box
    playlist_box = new QGroupBox();
    playlist_box->setLayout(playlist_layout);
    
    // ==> Set Volume
    gsettings_volumebox = new QWidget(this);
    gsettings_subtitle2 = new QLabel("Please set the volume:");
    gsettings_subtitle2->setMaximumHeight(text_max_height);
    gsettings_subtitle2->setObjectName("subtitle");
    gsettings_subtitle2->setAlignment(Qt::AlignHCenter);
    gsettings_volumeslider1 = new QSlider(Qt::Horizontal);
    gsettings_volumeslider1->setRange(0, 100);
    gsettings_volumeslider1->setMinimumWidth(slider_min_width);
    // TODO: Correct the fist value
    gsettings_volumeslider1->setValue(player->volume());
    gsettings_volumeslider1->setTickInterval(10);
    gsettings_volumeslider1->setTickPosition(QSlider::TicksBelow);
    // TODO: connect the vole slider to the actual volume
    gsettings_layout_volumebox = new QVBoxLayout(gsettings_volumebox);
    gsettings_layout_volumebox->addWidget(gsettings_subtitle2);
    gsettings_layout_volumebox->addWidget(gsettings_volumeslider1);
    
    // The button to go back home
    gsettings_button_home = new QPushButton("Return to home");
    gsettings_button_home->setMaximumHeight(button_max_height);
    gsettings_button_home->setObjectName("home");
    
    // the vbox layoout for all the stuff
    gsettings_layout_general = new QVBoxLayout(this);
    gsettings_layout_general->addWidget(gsettings_title);
    gsettings_layout_general->addWidget(gsettings_choice1box);
    gsettings_layout_general->addWidget(playlist_box);
    gsettings_layout_general->addWidget(gsettings_volumebox);
    gsettings_layout_general->addWidget(gsettings_button_home);
    
    // styles
    QFile help_styles(":/styles/gamesettings.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);
    
    this->show();
    
    connect(gsettings_button_home, SIGNAL(clicked()), this, SIGNAL(back_to_home()));
    connect(gsettings_volumeslider1, SIGNAL(valueChanged(int)),
            player, SLOT(setVolume(int)));
    connect(gsettings_choice1_1, SIGNAL(clicked()), this, SLOT(clicked_sologame()));
    connect(gsettings_choice1_2, SIGNAL(clicked()), this, SLOT(clicked_tourneygame()));
    connect(gsettings_choice1_3, SIGNAL(clicked()), this, SLOT(clicked_brentrbtgame()));
    connect(gsettings_choice1_4, SIGNAL(clicked()), this, SLOT(clicked_randrbtgame()));
    connect(playlist_choice1, SIGNAL(clicked()), this, SLOT(clicked_rexplaylist()));
    connect(playlist_choice2, SIGNAL(clicked()), this, SLOT(clicked_brentplaylist()));
    //title->music_player, SLOT(setVolume(int)));
}

void GameSettings::clicked_sologame() {
    this->current_style = GameOptions::SoloGame;
}

void GameSettings::clicked_tourneygame() {
    this->current_style = GameOptions::TourneyGame;
}

void GameSettings::clicked_brentrbtgame() {
    this->current_style = GameOptions::BrentRobotGame;
}

void GameSettings::clicked_randrbtgame() {
    this->current_style = GameOptions::RandRobotGame;
}

void GameSettings::clicked_rexplaylist() {
    this->current_playlist = PlaylistOptions::RexPlaylist;
    emit play_rex_playlist();
}

void GameSettings::clicked_brentplaylist() {
    this->current_playlist = PlaylistOptions::BrentPlaylist;
    emit play_brent_playlist();
}

GameOptions GameSettings::getGameOption() {
    return this->current_style;
}

PlaylistOptions GameSettings::getPlaylistOption() {
    return this->current_playlist;
}
