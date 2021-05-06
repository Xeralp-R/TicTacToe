//
//  tttgame.hpp
//  Maybe
//
//  Created by Reventar on 02/05/2021.
//

#ifndef tttgame_hpp
#define tttgame_hpp

#include "victory.hpp"
#include "draw.hpp"

#include <QWidget>
#include <QPushButton>
#include <array>
#include <vector>
#include <QString>
#include <QChar>

QT_BEGIN_NAMESPACE
//class QPushButton;
class QLabel;
class QVBoxLayout;
class QGridLayout;
QT_END_NAMESPACE

enum class BoardOptions {
    A1 = 0, A2 = 1, A3 = 2,
    B1 = 4, B2 = 5, B3 = 6,
    C1 = 7, C2 = 7, C3 = 8,
    NullValue = -1
};

enum class Players {
    NullPlayer = 0,
    PlayerOne = 1,
    PlayerTwo = 2
};

class TTTButton : public QPushButton {
    Q_OBJECT
public:
    explicit TTTButton(QWidget * parent = nullptr);
    
    void setLocation(BoardOptions given_location);
    BoardOptions getLocation();
    void setPlayer(Players given_player);
    Players getPlayer ();
    
    // I just copied this right from TicTacToe online
    QSizePolicy sizePolicy() const
    { return QSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred ); }
    QSize sizeHint() const { return QSize( 32, 32 ); }
    QSize minimumSizeHint() const { return QSize( 10, 10 ); }
    
    // more stuff
    void setCenteredText (const QString& text);
    void setCLabelName (const QString& name);
private:
    BoardOptions button_location;
    Players button_player;
    QVBoxLayout * button_layout;
    QLabel * button_text;
};

class TTTGame : public QWidget {
    Q_OBJECT
public:
    explicit TTTGame(QString name1 = "Adam",
                     QString name2 = "Eve",
                     QChar char1 = 'O',
                     QChar char2 = 'X',
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
    // state that there is now a winner
    void go_to_victory(int);
    // state that there is now a draw
    void go_to_draw();
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
    std::vector<QString> player_names {"Nullius", "Adam", "Eve"};
    // The current player
    Players current_player = Players::NullPlayer;
    // the marker if we've reached the end
    bool has_ended = false;
    
    // ==> Output Functions
    // Sets the button on the screen.
    void output();
    // A help function to output: sets the title correctly.
    void format_title(QLabel * title_box, Players current_player);
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
    VictoryScreen * victory_screen;
    DrawScreen * draw_screen;
};

#endif /* tttgame_hpp */
