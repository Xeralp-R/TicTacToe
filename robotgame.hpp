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

class RobotGame : public QWidget {
    Q_OBJECT
public:
    explicit RobotGame(QString player_name = "Adam",
                     QChar player_char = 'O',
                     QWidget * parent = nullptr);
    //void set_first_player(Players);
public slots:
    // The effective constructor.
    //void preparator();
private slots:
    // Validates the inputs.
    void button_clicked();
    
    // gos to victory
    //void to_victory();
    //void to_draw();
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
    Players current_player = Players::NullPlayer;
    // the marker if we've reached the end
    bool has_ended = false;
    
    // ==> Output Functions
    // Sets the button on the screen.
    void output();
    // A help function to output: sets the title correctly.
    //void format_title(QLabel * title_box, Players current_player);
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
    
    // ==> Procedendo Screens
    //VictoryScreen * victory_screen;
    //DrawScreen * draw_screen;
};

#endif /* robotgame_hpp */
