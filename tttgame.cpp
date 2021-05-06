//
//  tttgame.cpp
//  Maybe
//
//  Created by Reventar on 02/05/2021.
//

#include "tttgame.hpp"
#include "victory.hpp"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <iostream>
#include <QFile>
#include <QString>


TTTButton::TTTButton(QWidget * parent)  : QPushButton(parent),
button_location(BoardOptions::NullValue), button_player(Players::NullPlayer) {
	button_text = new QLabel(" ");
	button_text->setAlignment(Qt::AlignCenter);
	button_layout = new QVBoxLayout(this);
	button_layout->addWidget(button_text);
}

void TTTButton::setLocation(BoardOptions given_location) {
    this->button_location = given_location;
}
BoardOptions TTTButton::getLocation() {
    return this->button_location;
}
void TTTButton::setPlayer(Players given_player) {
    this->button_player = given_player;
}
Players TTTButton::getPlayer() {
    return this->button_player;
}
void TTTButton::setCenteredText (const QString& text) {
	this->button_text->setText(text);
}
void TTTButton::setCLabelName(const QString& name) {
	this->button_text->setObjectName(name);
}

// The actual constructor: delete after debugging
TTTGame::TTTGame(QString name1,
                 QString name2,
                 QChar char1,
                 QChar char2,
                 QWidget * parent) : QWidget(parent) {
    player_names[1] = name1;
    player_names[2] = name2;
    player_tokens[1] = char1;
    player_tokens[2] = char2;
    
    // prepare the screen
    setMinimumSize(600, 450);
    setWindowTitle("Game!");
    
    // set the title
    title = new QLabel(this);
    title->setObjectName("NullPlayer");
	title->setAlignment(Qt::AlignCenter);
    
    // set the buttons
    layout_buttons = new QGridLayout;
	/*
    layout_buttons->setColumnMinimumWidth(1, col_min_width);
    layout_buttons->setColumnMinimumWidth(3, col_min_width);
    layout_buttons->setRowMinimumHeight(1, row_min_height);
    layout_buttons->setRowMinimumHeight(3, row_min_height);
	 */
    for (int i = 0; i < 9; ++i) {
        array_buttons[i] = new TTTButton(this);
        array_buttons[i]->setObjectName("playernull");
		array_buttons[i]->setCLabelName("playernull");
        //array_buttons[i]->setMinimumSize(button_min_width, button_min_height);
        layout_buttons->addWidget(array_buttons[i], (i/3)+1, (i%3)+1);
    }
    
    // set the overarching thing
    layout_general = new QVBoxLayout (this);
    layout_general->addWidget(title);
    layout_general->addLayout(layout_buttons);
    
    
    // TODO: Define the QChar and QString vecotrs with the names
    // as inputted.
    
    // invoke the first call
    output();
}

void TTTGame::output() {
	// constants
	QSize button_fixed_size (110, 110);
	int title_fixed_height = 40;
	
    // switch the current player to the other guy
    try {
        
        if (current_player == Players::PlayerOne) {
            current_player = Players::PlayerTwo;
        } else if ((current_player == Players::PlayerTwo) ||
                   (current_player == Players::NullPlayer)) {
            current_player = Players::PlayerOne;
        } else {
            throw "invalid_player_exeption: current player absurd";
        }

        // change the title accordingly
        format_title(title, current_player);
		title->setMinimumHeight(title_fixed_height);
        
        // format each of the buttons accordingly
        for (int i = 0; i < 9; ++i) {
            format_button(array_buttons[i]);
			array_buttons[i]->setFixedSize(button_fixed_size);
			
        }
    } catch (char const* e) {
        std::cerr << "exception: " << e << "\n";
        return;
    }
	
	QFile help_styles(":/styles/tttgame.qss");
	help_styles.open(QFile::ReadOnly);
	QString help_string{ QLatin1String(help_styles.readAll()) };
	this->setStyleSheet(help_string);
    
    // show this
    this->show();
    
    /*
    connects manually
    I know this isn't 100% expansible, but it's not my job.
    For future refactorers, please feel free to make a class for the push button.
     Maybe? I changed it?
     connect(array_buttons[i], SIGNAL(clickedLocation(BoardOptions)),
     this, SLOT(validate(BoardOptions)));
    */
    
    for (int i = 0; i < 9; ++i) {
        connect(array_buttons[i], SIGNAL(clicked()), this, SLOT(button_clicked()));
    }
    
    //connect(array_buttons[0], SIGNAL(clicked()), this, SLOT(button_clicked()));
}

void TTTGame::format_title(QLabel * title_box, Players current_player) {
    switch (current_player) {
        case Players::PlayerOne:
            title_box->setText(player_names[1]);
            title_box->setObjectName("playerone");
            break;
            
        case Players::PlayerTwo:
            title_box->setText(player_names[2]);
            title_box->setObjectName("playertwo");
            break;
            
        case Players::NullPlayer:
        default:
            throw "invalid_player_exeption: title player absurd";
            break;
    }
}

void TTTGame::format_button(TTTButton * button) {
    Players player = button->getPlayer();
    switch (player) {
        case Players::PlayerOne:
            button->setCenteredText(QString(player_tokens[1]));
            button->setObjectName("playerone");
			button->setCLabelName("playerone");
            break;
            
        case Players::PlayerTwo:
            button->setCenteredText(QString(player_tokens[2]));
            button->setObjectName("playertwo");
			button->setCLabelName("playertwo");
            break;
            
        case Players::NullPlayer:
            button->setCenteredText(QString(player_tokens[0]));
            button->setObjectName("playernull");
			button->setCLabelName("playernull");
            break;
        default:
            throw "invalid_player_exeption: button player absurd";
            break;
    }
}

void TTTGame::button_clicked() {
    TTTButton * button_sender = static_cast<TTTButton *>(sender());
    if (button_sender->getPlayer() == Players::NullPlayer) {
        button_sender->setPlayer(current_player);
        check_end();
        if (!has_ended) {
            output();
            
            // tells me output was called---
            // delete in final version
            /*
            try {
                throw "got here! ";
            } catch (const char* e) {
                std::cerr << "exception: " << e << static_cast<int>(current_player) << "\n";
                return;
            }
             */
        }
    }
}

void TTTGame::check_end() {
    //int x = 0, y = 0;
    // /*
    for (int x = 0; x < 3; ++x) {
        //Horizontal Checking
        if (
            (array_buttons[x*3]->getPlayer() == array_buttons[x*3+1]->getPlayer()) &&
            (array_buttons[x*3]->getPlayer() == array_buttons[x*3+2]->getPlayer()) &&
            (array_buttons[x*3]->getPlayer() != Players::NullPlayer) &&
            (has_ended == false)
            ) {
            call_victor(array_buttons[x*3]->getPlayer());
            has_ended = true;
            //break;
            return;
        } else if ( //Vertical Checking
                   (array_buttons[x]->getPlayer() == array_buttons[x+3]->getPlayer()) &&
                   (array_buttons[x]->getPlayer() == array_buttons[x+6]->getPlayer()) &&
                   (array_buttons[x]->getPlayer() != Players::NullPlayer) &&
                   (has_ended == false)
                   ) {
            call_victor(array_buttons[x]->getPlayer());
            has_ended = true;
            //break;
            return;
        }
    }
    if (//Diagonal Left to Right Checking
        (array_buttons[0]->getPlayer() == array_buttons[4]->getPlayer()) &&
        (array_buttons[0]->getPlayer() == array_buttons[8]->getPlayer()) &&
        (array_buttons[0]->getPlayer() != Players::NullPlayer) &&
        (has_ended == false)
        ){
        call_victor(array_buttons[0]->getPlayer());
        has_ended = true;
        return;
    } else if (//Diagonal Right to Left Checking
               (array_buttons[2]->getPlayer() == array_buttons[4]->getPlayer()) &&
               (array_buttons[2]->getPlayer() == array_buttons[6]->getPlayer()) &&
               (array_buttons[2]->getPlayer() != Players::NullPlayer) &&
               (has_ended == false)
               ){
        call_victor(array_buttons[2]->getPlayer());
		has_ended = true;
        return;
    }

    //Check if box is full
    // it should not get here if any other thing is returned
	if ( (check_full() == true) && (has_ended == false) ) {
        call_draw();
		has_ended = true;
        return;
    }
}

bool TTTGame::check_full() {
    int empty_boxes = 0;
    for (int i = 0; i < 9; ++i) {
        if (array_buttons[i]->getPlayer() == Players::NullPlayer) {
            ++empty_boxes;
        }
    }
    if (empty_boxes == 0) {
        return true;
    } else {
        return false;
    }
}

void TTTGame::call_victor(Players winning_player) {
    int player_num = static_cast<int>(winning_player);
    emit go_to_victory(player_num);
    /*
    int player_num = static_cast<int>(winning_player);
    
    victory_screen = new VictoryScreen(player_names[player_num], player_num);
    connect(victory_screen, SIGNAL(back_to_title()), this, SLOT(from_victory()));
    victory_screen->show();
    this->hide();
    
    // delete in final version
    
    try {
        throw "Winner is Player ";
    } catch (const char* e) {
        std::cerr << "exception: " << e << player_num << "\n";
        return;
    }
     */
}

/*
void TTTGame::from_victory() {
    delete victory_screen;
    this->show();
    emit back_to_home();
}*/

void TTTGame::call_draw() {
    emit go_to_draw();
    /*
    draw_screen = new DrawScreen(player_names[1], player_names[2]);
    connect(draw_screen, SIGNAL(back_to_title()), this, SLOT(from_draw()));
    draw_screen->show();
    this->hide();
    
    // delete in final version
    
    try {
        throw "Draw";
    } catch (const char* e) {
        std::cerr << "exception: " << e << "\n";
        return;
    }
     */
}

/*
void TTTGame::from_draw() {
    delete draw_screen;
    this->show();
    emit back_to_home();
}*/
