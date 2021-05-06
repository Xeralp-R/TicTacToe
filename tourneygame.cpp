//
//  tourneygame.cpp
//  Maybe
//
//  Created by Reventar on 06/05/2021.
//

#include "tourneygame.hpp"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QString>
#include <QGroupBox>

#include <iostream>

// ==> TourneyButton
// Constructor
TourneyButton::TourneyButton(QWidget * parent) : QPushButton(parent),
button_state(ButtonOptions::FuturePlay), button_rel_location(-1) {
    button_text = new QLabel(" ");
    button_text->setAlignment(Qt::AlignCenter);
    button_layout = new QVBoxLayout(this);
    button_layout->addWidget(button_text);
}

// Encapsulation of Buttons
void TourneyButton::setRelLocation(int given_location) {
    this->button_rel_location = given_location;
}

void TourneyButton::setState(ButtonOptions given_player) {
    this->button_state = given_player;
}

void TourneyButton::setCenteredText (const QString& text) {
    this->button_text->setText(text);
}

void TourneyButton::setCLabelName(const QString& name) {
    this->button_text->setObjectName(name);
}

int TourneyButton::getRelLocation() {
    return this->button_rel_location;
}

ButtonOptions TourneyButton::getState() {
    return this->button_state;
}

// ==> TourneyGame


TourneyGame::TourneyGame(QString name1,
                         QString name2,
                         QChar char1,
                         QChar char2,
                         QWidget *parent) : QWidget(parent) {
    // constants
    const int title_max_height = 100;
    
    // name
    player_data[1].name = name1;
    player_data[1].token = char1;
    player_data[2].name = name2;
    player_data[2].token = char2;
    
    // prepare the screen
    setMinimumSize(600, 450);
    setWindowTitle("Game!");
    
    // prepare and set the title
    title = new QLabel(this);
    title->setText("Tournament");
    title->setObjectName("Title");
    title->setAlignment(Qt::AlignCenter);
    title->setMaximumHeight(title_max_height);
    
    // prepare the scoreboards
    player1_namebox = new QLabel();
    player1_namebox->setObjectName("player1");
    player1_namebox->setText(player_data[1].name);
    player1_scorebox = new QLabel();
    player1_scorebox->setObjectName("number");
    player1_layout = new QVBoxLayout();
    player1_layout->addWidget(player1_namebox);
    player1_layout->addWidget(player1_scorebox);
    player1_box = new QGroupBox();
    player1_box->setLayout(player1_layout);
    
    player2_namebox = new QLabel();
    player2_namebox->setObjectName("player2");
    player2_namebox->setText(player_data[2].name);
    player2_scorebox = new QLabel();
    player2_scorebox->setObjectName("number");
    player2_layout = new QVBoxLayout();
    player2_layout->addWidget(player2_namebox);
    player2_layout->addWidget(player2_scorebox);
    player2_box = new QGroupBox();
    player2_box->setLayout(player2_layout);
    
    layout_scoreboard = new QHBoxLayout();
    layout_scoreboard->addWidget(player1_box);
    layout_scoreboard->addWidget(player2_box);
    
    // prepare the buttons
    layout_buttons = new QHBoxLayout();
    for (int i = 0; i < 5; ++i) {
        array_buttons[i] = new TourneyButton();
        array_buttons[i]->setObjectName(options_string(ButtonOptions::FuturePlay));
        array_buttons[i]->setCLabelName(options_string(ButtonOptions::FuturePlay));
        array_buttons[i]->setRelLocation(i);
        layout_buttons->addWidget(array_buttons[i]);
    }
    
    // prepare the overarching layout
    layout_general = new QVBoxLayout(this);
    layout_general->addWidget(title);
    layout_general->addLayout(layout_scoreboard);
    layout_general->addLayout(layout_buttons);
    
    // prepare the first turn
    current_turn = 0;
    
    // call the first output
    output();
}

void TourneyGame::output() {
    try {
        // set the state of the current turn button
        array_buttons[current_turn]->setState(ButtonOptions::NextToPlay);
        
        // set the scoreboard
        player1_scorebox->
            setText(QString::fromStdString(std::to_string(player_data[1].score)));
        player2_scorebox->
            setText(QString::fromStdString(std::to_string(player_data[2].score)));
        
        // set the buttons using format_buttons
        for (TourneyButton * button : array_buttons) {
            format_button(button);
        }
    } catch (char const* e) {
        std::cerr << "exception: " << e << "\n";
        return;
    }
    
    this->show();
    
    for (TourneyButton * button : array_buttons) {
        connect(button, SIGNAL(clicked()), this, SLOT(button_clicked()));
    }
}

void TourneyGame::format_button(TourneyButton * given_button) {
    given_button->setObjectName(options_string(given_button->getState()));
    given_button->setCLabelName(options_string(given_button->getState()));
    switch (given_button->getState()) {
        case ButtonOptions::Player1Won :
            given_button->setCenteredText(QString(player_data[1].token));
            break;
        case ButtonOptions::Player2Won :
            given_button->setCenteredText(QString(player_data[2].token));
            break;
        default:
            break;
    }
}

