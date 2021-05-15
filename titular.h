#ifndef TITULAR_H
#define TITULAR_H


#include "helpscreen.h"
#include "gamesettings.h"
#include "playersettings.hpp"
#include "aboutus.hpp"
#include "tttgame.hpp"
#include "gameoptions.hpp"
#include "victory.hpp"
#include "draw.hpp"
#include "tourneygame.hpp"
#include "robotoptions.h"
#include "robotgame.hpp"

#include <QWidget>
#include <QString>
#include <QChar>
#include <vector>

QT_BEGIN_NAMESPACE
    class QPushButton;
    class QLabel;
    class QGridLayout;
    class QFrame;
    class QMediaPlayer;
    class QMediaPlaylist;
QT_END_NAMESPACE

class Titular : public QWidget
{
    Q_OBJECT
public:
    explicit Titular(QWidget *parent = nullptr);
    QMediaPlayer * music_player;
    QMediaPlaylist * rex_playlist;
    QMediaPlaylist * brent_playlist;
signals:
private slots:
    void on_button_game_clicked();
    void on_button_help_clicked();
    void on_button_sett_clicked();
    void on_button_abts_clicked();
    void on_button_cust_clicked();
    void on_button_lore_clicked();
    void on_back_from_game();
    void on_back_from_help();
    void on_back_from_sett();
    void on_back_from_cust();
    void on_back_from_abts();
    void on_back_from_lore();
    
    void solo_victory(int num);
    void from_victory();
    void solo_draw();
    void from_draw();
    
    void grand_victory(int num);
    void from_grand_victory();
    void grand_draw();
    void from_grand_draw();
    
    void antirobot_victory();
    void antirobot_draw();
    void antirobot_loss();
    void from_antirobot_loss();
    
    void do_play_rex_playlist();
    void do_play_brent_playlist();
private:
    // ==> Visible Things
    QFrame * line;
    // Goes to the game.
    QPushButton * button_to_game;
    // Goes to the help screen.
    QPushButton * button_to_help;
    // goes to game settings?
    QPushButton * button_to_sett;
    QPushButton * button_to_abts;
    // button to player settings?
    QPushButton * button_to_cust;
    QPushButton * button_to_lore;
    QGridLayout * titular_layout;
    QLabel * grand_title;
    
    // ==> Screens
    HelpScreen * help_screen;
    GameSettings * game_settings;
    PlayerSettings * player_settings;
    AboutUs * about_us;
    LoreScreen * lore_screen;
    TTTGame * ttt_game;
    VictoryScreen * victory_screen;
    DrawScreen * draw_screen;
    GrandVictoryScreen * grand_victory_screen;
    GrandDrawScreen * grand_draw_screen;
    TourneyGame * tourney_game;
    RobotGame * robot_game;
    RobotLossScreen * robot_loss_screen;
    
    // ==> Functions
    void solo_game_init();
    void tourney_game_init();
    void robot_game_init();
    
    // ==> Invisible Things: Variables
    QString PlayerName1 = "Adam";
    QString PlayerName2 = "Eve";
    QChar PlayerChar1 = 'O';
    QChar PlayerChar2 = 'X';
    
    std::vector<QString> player_names {"Nullius", "Adam", "Eve"};
    std::vector<QChar> player_chars {' ', 'O', 'X'};
    
    GameOptions game_option = GameOptions::SoloGame;
    PlaylistOptions playlist_option = PlaylistOptions::RexPlaylist;
};

#endif // TITULAR_H
