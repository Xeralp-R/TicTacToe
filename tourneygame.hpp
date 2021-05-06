//
//  tourneygame.hpp
//  Maybe
//
//  Created by Reventar on 06/05/2021.
//

#ifndef tourneygame_hpp
#define tourneygame_hpp

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
    
    // sole constructor
    PlayerData (QString str, QChar ch, int num) :
    name(str), token(ch), score(num) {};
};

enum class ButtonOptions {
    FinishedDraw = 0,
    Player1Won = 1,
    Player2Won = 2,
    NextToPlay = 3,
    FuturePlay = 4
};
std::map<ButtonOptions, QString> b_o_map {
    {ButtonOptions::FinishedDraw, "finisheddraw"},
    {ButtonOptions::Player1Won, "player1won"},
    {ButtonOptions::Player2Won, "player2won"},
    {ButtonOptions::NextToPlay, "nexttoplay"},
    {ButtonOptions::FuturePlay, "futureplay"}
};
QString options_string(ButtonOptions option) {
    return b_o_map.find(option)->second;
}

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
   // void solo_victory(int player_num);
    // when a draw is achieved
    //void solo_draw();
signals:
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
        {"Nullius", ' ', 0},
        {"Adam", 'O', 0},
        {"Eve", 'X', 0}
    };
    int current_turn;
    
    // --> functions
    // visible functions
    void output();
    void format_button(TourneyButton * given_button);
};

#endif /* tourneygame_hpp */
