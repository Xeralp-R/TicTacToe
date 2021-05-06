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

GameSettings::GameSettings(QMediaPlayer * player,
                           GameOptions old_style,
                           QWidget *parent) : QWidget(parent) {
    const int text_max_height = 40;
    const int button_max_height = 50;
    const int title_text_max_height = 100;
    //const int regul_text_max_height = 150;
    const int slider_min_width = 450;
    
    setMinimumSize(600, 450);
    setWindowTitle("Game Settings");
    
    // The Title
    gsettings_title = new QLabel("Settings", this);
    gsettings_title->setAlignment(Qt::AlignCenter);
    gsettings_title->setMaximumHeight(title_text_max_height);
    gsettings_title->setObjectName("title");
    
    // Pick Game Mode
    gsettings_choice1box = new QWidget(this);
    gsettings_subtitle1 = new QLabel("Please pick your game mode:", gsettings_choice1box);
    gsettings_subtitle1->setMaximumHeight(text_max_height);
    gsettings_subtitle1->setObjectName("subtitle");
    gsettings_subtitle1->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    gsettings_choice1_1 = new QRadioButton("Regular Mode", gsettings_choice1box);
    gsettings_choice1_1->setObjectName("rad_butn1");
    gsettings_choice1_2 = new QRadioButton("Tournament Mode", gsettings_choice1box);
    gsettings_choice1_2->setObjectName("rad_butn2");
    // set things as checked as necessary
    switch (old_style) {
        case GameOptions::NullGame:
        case GameOptions::SoloGame:
            gsettings_choice1_1->setChecked(true);
            break;
        case GameOptions::TourneyGame:
            gsettings_choice1_2->setChecked(true);
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
    
    // Set Volume
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
    //title->music_player, SLOT(setVolume(int)));
}

void GameSettings::clicked_sologame() {
    this->current_style = GameOptions::SoloGame;
}

void GameSettings::clicked_tourneygame() {
    this->current_style = GameOptions::TourneyGame;
}

GameOptions GameSettings::getGameOption() {
    return this->current_style;
}
