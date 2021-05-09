//
//  robotgame.cpp
//  TicTacToe
//
//  Created by Reventar on 08/05/2021.
//

#include "robotgame.hpp"
#include "tttgame.hpp"
#include "victory.hpp"
#include "robotoptions.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QString>

#include <iostream>
#include <random>
#include <chrono>

// return the pointer to the robot
RobotInterface * RobotInterface::CreateRobotPointer(RobotOptions given_option) {
    switch (given_option) {
        case RobotOptions::RandoBot:
            return new RandoRobot;
            break;
        default:
            return new BrentRobot;
            break;
    }
}

// the brent robot's thing
void BrentRobot::robot_move (std::array<TTTButton *, 9> & array_buttons, int turn_no) {
    try {
        switch (turn_no) {
            case 1:
                move_1(array_buttons);
                break;
            case 2:
                move_2(array_buttons);
                break;
            case 3:
                move_3(array_buttons);
                break;
            case 4:
                move_4(array_buttons);
                break;
            default:
                throw "absurd move number";
                break;
        }
    } catch (const char * e) {
        std::cerr << "exception: " << e << "\n";
        return;
    }
}

// the first move
// by brent
void BrentRobot::move_1 (std::array<TTTButton *, 9> & array_buttons) {
    if (array_buttons[2]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[2]->setPlayer(Players::PlayerTwo);
    }
    else
    {
        array_buttons[4]->setPlayer(Players::PlayerTwo);
    }
}

// the second move
void BrentRobot::move_2 (std::array<TTTButton *, 9> & array_buttons) {
    if (array_buttons[5]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[5]->setPlayer(Players::PlayerTwo);
    }
    else if (array_buttons[8]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[8]->setPlayer(Players::PlayerTwo);
    }
    else
    {
        array_buttons[4]->setPlayer(Players::PlayerTwo);
    }
}

// the 3rd move
void BrentRobot::move_3 (std::array<TTTButton *, 9> & array_buttons) {
    if (array_buttons[8]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[8]->setPlayer(Players::PlayerTwo);
    }
    else if (array_buttons[0]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[0]->setPlayer(Players::PlayerTwo);
    }
    else if (array_buttons[1]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[1]->setPlayer(Players::PlayerTwo);
    }
    else
    {
        array_buttons[4]->setPlayer(Players::PlayerTwo);
    }
}

// the 4th move
void BrentRobot::move_4 (std::array<TTTButton *, 9> & array_buttons) {
    if (array_buttons[3]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[3]->setPlayer(Players::PlayerTwo);
    }
    else if (array_buttons[6]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[6]->setPlayer(Players::PlayerTwo);
    }
    else if (array_buttons[0]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[0]->setPlayer(Players::PlayerTwo);
    }
    else if (array_buttons[1]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[1]->setPlayer(Players::PlayerTwo);
    }
    else if (array_buttons[7]->getPlayer() == Players::NullPlayer)
    {
        array_buttons[7]->setPlayer(Players::PlayerTwo);
    }
    else
    {
        array_buttons[4]->setPlayer(Players::PlayerTwo);
    }
}

// the randobot

void RandoRobot::robot_move(std::array<TTTButton *, 9> & array_buttons, int turn_no) {
    // copied from mastermind.cpp
    // gets the number of seconds
    // since a long, long, time ago
    uint32_t now = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count() + turn_no;
    // I don't know what this is–
    // does it set up the random number generator?
    typedef std::mt19937 MyRNG;  // the Mersenne Twister with a popular choice of parameters
    MyRNG rand_no_gen;
    rand_no_gen.seed(now);
    // this apparently sets up the distribution.
    std::uniform_int_distribution<uint32_t> uint_dist6(0,8); // range [0,8]?
    // now, let's get our number!
    auto dice_maybe = std::bind(uint_dist6, rand_no_gen);
    while (true) {
        int rand_no = dice_maybe();
        if (array_buttons[rand_no]->getPlayer() == Players::NullPlayer) {
            array_buttons[rand_no]->setPlayer(Players::PlayerTwo);
            break;
        }
    }
}

// ==> The Game Itself

// The actual constructor: delete after debugging
RobotGame::RobotGame(QString player_name,
                     QString robot_name,
                     QChar player_char,
                     QChar robot_char,
                     RobotOptions given_robot,
                     QWidget * parent) : QWidget(parent) {
    player_names[1] = player_name;
    player_names[2] = robot_name;
    player_tokens[1] = player_char;
    player_tokens[2] = robot_char;
    robot_option = given_robot;
    
    const int title_fixed_height = 40;
    
    // prepare the screen
    setMinimumSize(600, 450);
    setWindowTitle("Game!");
    
    // set the title
    title = new QLabel(this);
    title->setObjectName("NullPlayer");
    title->setAlignment(Qt::AlignCenter);
    title->setObjectName("playerone");
    title->setText(player_names[1]);
    title->setMinimumHeight(title_fixed_height);
    
    // set the buttons
    layout_buttons = new QGridLayout;
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
    
    // prepare the robot
    robot_pointer = RobotInterface::CreateRobotPointer(robot_option);
    
    // TODO: Define the QChar and QString vecotrs with the names
    // as inputted.
    turn_number = 0;
    
    // invoke the first call
    output();
}

void RobotGame::output() {
    // constants
    QSize button_fixed_size (110, 110);
    
    turn_number += 1;
    
    // switch the current player to the other guy
    try {
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
}

void RobotGame::format_button(TTTButton * button) {
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

void RobotGame::button_clicked() {
    TTTButton * button_sender = static_cast<TTTButton *>(sender());
    if (button_sender->getPlayer() == Players::NullPlayer) {
        button_sender->setPlayer(Players::PlayerOne);
        check_end();
        if (!has_ended) {
            // this should do the robot bit
            robot_pointer->robot_move(array_buttons, turn_number);
            check_end();
            if (!has_ended) {
                output();
            }
        }
    }
}

void RobotGame::check_end() {
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

bool RobotGame::check_full() {
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

void RobotGame::call_victor(Players winning_player) {
    switch (winning_player) {
        case Players::PlayerOne:
            emit go_to_victory();
            break;
        case Players::PlayerTwo:
            emit go_to_loss();
            break;
        default:
            break;
    }
}

void RobotGame::call_draw() {
    emit go_to_draw();
}

