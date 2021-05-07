//
//  tourneygame.hpp
//  Maybe
//
//  Created by Reventar on 06/05/2021.
//

#ifndef tourneygame_hpp
#define tourneygame_hpp

#include "tttgame.hpp"
#include "draw.hpp"
#include "victory.hpp"

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QChar>

#include <array>
#include <vector>
#include <map>

QT_BEGIN_NAMESPACE
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QGroupBox;
QT_END_NAMESPACE

struct PlayerData {
    // data
    QString name;
    QChar token;
    int score;
    int player_num;
    
    // sole constructor
    PlayerData (QString str, QChar ch, int num, int num2) :
    name(str), token(ch), score(num), player_num(num2) {};
};

enum class ButtonOptions {
    FinishedDraw = 0,
    Player1Won = 1,
    Player2Won = 2,
    NextToPlay = 3,
    FuturePlay = 4
};

class TourneyButton : public QPushButton {
    Q_OBJECT
public:
    explicit TourneyButton(QWidget * parent = nullptr);
    
    // encapsulation stuff
    void setRelLocation(int given_location);
    void setState(ButtonOptions given_player);
    void setCenteredText (const QString& text);
    void setCLabelName (const QString& name);
    int getRelLocation();
    ButtonOptions getState();
    
    // I just copied this right from TicTacToe online
    QSizePolicy sizePolicy() const
    { return QSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred ); }
    QSize sizeHint() const { return QSize( 32, 32 ); }
    QSize minimumSizeHint() const { return QSize( 10, 10 ); }
private:
    QVBoxLayout * button_layout;
    QLabel * button_text;
    ButtonOptions button_state;
    int button_rel_location;
};

class TourneyGame : public QWidget {
    Q_OBJECT
public:
    explicit TourneyGame (QString name1 = "Adam",
                          QString name2 = "Eve",
                          QChar char1 = 'O',
                          QChar char2 = 'X',
                          QWidget * parent = nullptr);
private slots:
    // validate when the next button is clicked
    void button_clicked();
    
    
    // when a single victory is achieced
    void solo_victory(int player_num);
    // when a draw is achieved
    void solo_draw();
    // get back from the grand draw screen
    //void from_grand_draw();
    // from the grand victory screen
    //void from_grand_victory();
signals:
    void to_home_screen();
    void to_grand_victory(int num);
    void to_grand_draw();
private:
    // ==> visible variables
    
    // --> top bit
    QVBoxLayout * layout_general;
    QLabel * title;
    
    // --> scoreboard
    QHBoxLayout * layout_scoreboard;
    QGroupBox * player1_box;
    QVBoxLayout * player1_layout;
    QLabel * player1_namebox;
    QLabel * player1_scorebox;
    QGroupBox * player2_box;
    QVBoxLayout * player2_layout;
    QLabel * player2_namebox;
    QLabel * player2_scorebox;
    
    // --> buttons
    QHBoxLayout * layout_buttons;
    std::array<TourneyButton *, 5> array_buttons {
        nullptr, nullptr, nullptr, nullptr, nullptr
    };
    
    // ==> invisible portions
    
    // --> variables
    std::vector<PlayerData> player_data {
        {"Nullius", ' ', 0, 0},
        {"Adam", 'O', 0, 1},
        {"Eve", 'X', 0, 2}
    };
    int current_turn;
    bool has_ended = false;
    bool was_button_clicked = true;
    
    // --> functions
    void output();
    void format_button(TourneyButton * given_button);
    void init_game();
    void check_end();
    void call_grand_victor(PlayerData winning_player_data);
    void call_grand_draw();
    
    // --> screens
    TTTGame * ttt_game;
    GrandVictoryScreen * grand_victory_screen;
    GrandDrawScreen * grand_draw_screen;
    
    // other stuff
    std::map<ButtonOptions, QString> button_option_map {
        {ButtonOptions::FinishedDraw, "finisheddraw"},
        {ButtonOptions::Player1Won, "player1won"},
        {ButtonOptions::Player2Won, "player2won"},
        {ButtonOptions::NextToPlay, "nexttoplay"},
        {ButtonOptions::FuturePlay, "futureplay"}
    };
    QString options_string(ButtonOptions option) {
        return button_option_map.find(option)->second;
    }
};

#endif /* tourneygame_hpp */
