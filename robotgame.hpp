//
//  robotgame.hpp
//  TicTacToe
//
//  Created by Reventar on 08/05/2021.
//

#ifndef robotgame_hpp
#define robotgame_hpp

//#include <stdio.h>

#include "tttgame.hpp"
#include "robotoptions.h"

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QChar>

#include <array>
#include <vector>

class RobotInterface {
public:
    // the actual "constructor", per se
    static RobotInterface * CreateRobotPointer (RobotOptions given_option);
    
    // the constructor: DO NOT CALL
    RobotInterface() {}
    
    // a virtual destructor so that the correct subclass destructor is called
    virtual ~RobotInterface() {}
    
    // the function that will emplace the thing
    virtual void robot_move (std::array<TTTButton *, 9> & array_buttons, int turn_no) = 0;
};

class BrentRobot : public RobotInterface {
public:
    // the empty contructor
    BrentRobot () {}
    // I think the destructor should be undefined?
    // override the function
    void robot_move (std::array<TTTButton *, 9> & array_buttons, int turn_no);
private:
    // the 4 functions
    void move_1 (std::array<TTTButton *, 9> & array_buttons);
    void move_2 (std::array<TTTButton *, 9> & array_buttons);
    void move_3 (std::array<TTTButton *, 9> & array_buttons);
    void move_4 (std::array<TTTButton *, 9> & array_buttons);
};

class RandoRobot : public RobotInterface {
public:
    // the empty constructor
    RandoRobot () {}
    // override the function
    void robot_move (std::array<TTTButton *, 9> & array_buttons, int turn_no);
};

// ==> Actual Game

class RobotGame : public QWidget {
    Q_OBJECT
public:
    explicit RobotGame(QString player_name = "Adam",
                       QString robot_name = "Robot",
                       QChar player_char = 'O',
                       QChar robot_char = 'X',
                       RobotOptions given_robot = RobotOptions::BrentyBot,
                       QWidget * parent = nullptr);
private slots:
    // Validates the inputs.
    void button_clicked();
    
signals:
    // go right back tothe title screen OUTDATED
    void back_to_home();
    // state that the player is the winner
    void go_to_victory();
    // state that there is now a draw
    void go_to_draw();
    // state that the player lost
    void go_to_loss();
private:
    // ==> Visual Variables
    QVBoxLayout * layout_general;
    QLabel * title;
    QGridLayout * layout_buttons;
    std::array<TTTButton *, 9> array_buttons {
        nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr
    };
    
    // ==> Non-Visual Variables
    // the characters to be used
    std::vector<QChar> player_tokens {' ', 'O', 'X'};
    // the names to be used
    std::vector<QString> player_names {"Nullius", "Adam", "Robot"};
    // The current player
    //Players current_player = Players::NullPlayer;
    // the bot the player's going to use
    RobotOptions robot_option = RobotOptions::BrentyBot;
    // the marker if we've reached the end
    bool has_ended = false;
    // the current turn number
    int turn_number = 0;
    // the pointer to the robot
    RobotInterface * robot_pointer = nullptr;
    
    // ==> Output Functions
    // Sets the button on the screen.
    void output();
    // a helper function to output: sets the buttons correctly.
    void format_button(TTTButton * button);
    
    // ==> Processing Functions
    // checks if we have reached the end
    void check_end();
    // check if the box is full: auxilliary to check_end();
    bool check_full();
    // call a draw
    void call_draw();
    // call a winner
    void call_victor(Players winning_player);
};

#endif /* robotgame_hpp */
