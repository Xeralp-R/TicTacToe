#include "titular.h"
#include "gamesettings.h"
#include "playersettings.hpp"
#include "aboutus.hpp"
#include "tttgame.hpp"
#include "gameoptions.hpp"
#include "robotoptions.h"

#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QFrame>
#include <QFile>
#include <QString>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QUrl>

Titular::Titular(QWidget *parent) : QWidget(parent)
{
    // const ints
    //const QSize button_min_size(200, 20);
    const int button_max_height = 50;
    const int text_max_height = 90;
    // Set size of the window
    setMinimumSize(600, 450);
    setWindowTitle("The Title");

    // Create and position the buttons
    button_to_game = new QPushButton("Let's Play!", this);
    button_to_help = new QPushButton("How To Play?", this);
    button_to_sett = new QPushButton("Game Settings", this);
    button_to_cust = new QPushButton("Player Settings", this);
    button_to_abts = new QPushButton("About Us", this);
    button_to_lore = new QPushButton("Lore", this);
    // set the qualified names
    button_to_game->setObjectName("button_to_game");
    button_to_help->setObjectName("button_to_help");
    button_to_sett->setObjectName("button_to_sett");
    button_to_abts->setObjectName("button_to_abts");
    button_to_cust->setObjectName("button_to_cust");
    button_to_lore->setObjectName("button_to_lcns");
    // set the maximum height
    button_to_game->setMaximumHeight(button_max_height);
    button_to_help->setMaximumHeight(button_max_height);
    button_to_sett->setMaximumHeight(button_max_height);
    button_to_abts->setMaximumHeight(button_max_height);
    button_to_cust->setMaximumHeight(button_max_height);
    button_to_lore->setMaximumHeight(button_max_height);

    // make the title
    grand_title = new QLabel();
    grand_title->setText("Tic-Tac-Toe");
    grand_title->setAlignment(Qt::AlignCenter);
    grand_title->setMaximumHeight(text_max_height);

    // create the layout
    titular_layout = new QGridLayout(this);
    // add it to the list
    titular_layout->addWidget(grand_title, 0, 0, 1, 2);
    //titular_layout->addWidget(line, 1, 0, 1, 2);
    titular_layout->addWidget(button_to_game, 2, 0);
    titular_layout->addWidget(button_to_help, 2, 1);
    titular_layout->addWidget(button_to_sett, 3, 0);
    titular_layout->addWidget(button_to_cust, 3, 1);
    titular_layout->addWidget(button_to_abts, 4, 0);
    titular_layout->addWidget(button_to_lore, 4, 1);

    // set the styles mo
    QFile styles_titular(":styles/titular.qss");
    styles_titular.open(QFile::ReadOnly);
    QString string_titular { QLatin1String(styles_titular.readAll()) };
    this->setStyleSheet(string_titular);

    // /*
    rex_playlist = new QMediaPlaylist();
    rex_playlist->addMedia(QUrl("qrc:/music/Rex_Playlist.mp3"));
    rex_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    
    brent_playlist = new QMediaPlaylist();
    brent_playlist->addMedia(QUrl("qrc:/music/Brent_Playlist.mp3"));
    brent_playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music_player = new QMediaPlayer();
    music_player->setPlaylist(rex_playlist);
    music_player->setVolume(50);
    music_player->play();
    //*/

    //show:
    this->show();

    // NEW : Do the connection
    connect(button_to_game, SIGNAL(clicked()), this, SLOT(on_button_game_clicked()));
    connect(button_to_help, SIGNAL(clicked()), this, SLOT(on_button_help_clicked()));
    connect(button_to_sett, SIGNAL(clicked()), this, SLOT(on_button_sett_clicked()));
    connect(button_to_cust, SIGNAL(clicked()), this, SLOT(on_button_cust_clicked()));
    connect(button_to_abts, SIGNAL(clicked()), this, SLOT(on_button_abts_clicked()));
    connect(button_to_lore, SIGNAL(clicked()), this, SLOT(on_button_lore_clicked()));
}

// ==> Let's go to stuff

void Titular::on_button_game_clicked() {
    switch (game_option) {
        case GameOptions::SoloGame:
            this->solo_game_init();
            break;
        case GameOptions::TourneyGame:
            this->tourney_game_init();
            break;
        case GameOptions::BrentRobotGame:
        case GameOptions::RandRobotGame:
            this->robot_game_init();
            break;
        default:
            // I'm not sure what to place here. Again.
            break;
    }
}

void Titular::solo_game_init() {
    ttt_game = new TTTGame(this->player_names[1],
                           this->player_names[2],
                           this->player_chars[1],
                           this->player_chars[2]);
    //connect(ttt_game, SIGNAL(back_to_home()), this, SLOT(on_back_from_game()));
    connect(ttt_game, SIGNAL(go_to_victory(int)), this, SLOT(solo_victory(int)));
    connect(ttt_game, SIGNAL(go_to_draw()), this, SLOT(solo_draw()));
    ttt_game->show();
    this->hide();
}

void Titular::tourney_game_init() {
    tourney_game = new TourneyGame(this->player_names[1],
                                   this->player_names[2],
                                   this->player_chars[1],
                                   this->player_chars[2]);
    connect(tourney_game, SIGNAL(to_grand_victory(int)), this, SLOT(grand_victory(int)));
    connect(tourney_game, SIGNAL(to_grand_draw()), this, SLOT(grand_draw()));
    tourney_game->show();
    this->hide();
}

void Titular::robot_game_init() {
    RobotOptions opt;
    switch (game_option) {
        case GameOptions::RandRobotGame:
            opt = RobotOptions::RandoBot;
            break;
        case GameOptions::BrentRobotGame:
        default:
            opt = RobotOptions::BrentyBot;
            break;
    }
    robot_game = new RobotGame(this->player_names[1],
                               this->player_names[2],
                               this->player_chars[1],
                               this->player_chars[2],
                               opt);
    connect(robot_game, SIGNAL(go_to_victory()), this, SLOT(antirobot_victory()));
    connect(robot_game, SIGNAL(go_to_draw()), this, SLOT(antirobot_draw()));
    connect(robot_game, SIGNAL(go_to_loss()), this, SLOT(antirobot_loss()));
    robot_game->show();
    this->hide();
}

void Titular::on_button_help_clicked() {
    help_screen = new HelpScreen();
    connect(help_screen, SIGNAL(back_to_home()), this, SLOT(on_back_from_help()));
    help_screen->show();
    this->hide();
}

void Titular::on_button_sett_clicked() {
    game_settings = new GameSettings(this->music_player,
                                     this->game_option,
                                     this->playlist_option);
    connect(game_settings, SIGNAL(back_to_home()), this, SLOT(on_back_from_sett()));
    connect(game_settings, SIGNAL(play_rex_playlist()), this, SLOT(do_play_rex_playlist()));
    connect(game_settings, SIGNAL(play_brent_playlist()), this, SLOT(do_play_brent_playlist()));
    game_settings->show();
    this->hide();
}

void Titular::on_button_cust_clicked() {
    player_settings = new PlayerSettings(player_names[1], player_names[2],
                                         player_chars[1], player_chars[2]);
    connect(player_settings, SIGNAL(back_to_home()), this, SLOT(on_back_from_cust()));
    player_settings->show();
    this->hide();
}

void Titular::on_button_abts_clicked() {
    about_us = new AboutUs();
    connect(about_us, SIGNAL(back_to_home()), this, SLOT(on_back_from_abts()));
    about_us->show();
    this->hide();
}

void Titular::on_button_lore_clicked() {
    lore_screen = new LoreScreen();
    connect(lore_screen, SIGNAL(back_to_home()), this, SLOT(on_back_from_lore()));
    lore_screen->show();
    this->hide();
}

// ==> intermediate

void Titular::do_play_rex_playlist() {
    music_player->stop();
    music_player->setPlaylist(rex_playlist);
    music_player->play();
}

void Titular::do_play_brent_playlist() {
    music_player->stop();
    music_player->setPlaylist(brent_playlist);
    music_player->play();
}

void Titular::solo_victory(int num) {
    delete ttt_game;
    ttt_game = nullptr;
    
    victory_screen = new VictoryScreen(player_names[num], num);
    connect(victory_screen, SIGNAL(back_to_title()), this, SLOT(from_victory()));
    victory_screen->show();
    this->hide();
    
    // delete in final version
    /*
     try {
     throw "Winner is Player ";
     } catch (const char* e) {
     std::cerr << "exception: " << e << player_num << "\n";
     return;
     }
     */
}

void Titular::solo_draw() {
    delete ttt_game;
    ttt_game = nullptr;
    //this->show();
    
    draw_screen = new DrawScreen(player_names[1], player_names[2]);
    connect(draw_screen, SIGNAL(back_to_title()), this, SLOT(from_draw()));
    draw_screen->show();
    this->hide();
    
    // delete in final version
    /*
     try {
     throw "Draw";
     } catch (const char* e) {
     std::cerr << "exception: " << e << "\n";
     return;
     }
     */
}

void Titular::grand_victory(int num) {
    tourney_game->hide();
    delete tourney_game;
    tourney_game = nullptr;
    
    grand_victory_screen = new GrandVictoryScreen(player_names[num], num);
    connect(grand_victory_screen, SIGNAL(back_to_title()), this, SLOT(from_grand_victory()));
    grand_victory_screen->show();
    this->hide();
}

void Titular::grand_draw() {
    tourney_game->hide();
    delete tourney_game;
    tourney_game = nullptr;
    
    grand_draw_screen = new GrandDrawScreen;
    connect(grand_draw_screen, SIGNAL(back_to_title()), this, SLOT(from_grand_draw()));
    grand_draw_screen->show();
    this->hide();
}

void Titular::antirobot_victory() {
    robot_game->hide();
    delete robot_game;
    robot_game = nullptr;
    
    // just reusing the code from solo victory
    // I don't think I need to make a new one
    victory_screen = new VictoryScreen(player_names[1], 1);
    connect(victory_screen, SIGNAL(back_to_title()), this, SLOT(from_victory()));
    victory_screen->show();
    this->hide();
}

void Titular::antirobot_draw() {
    robot_game->hide();
    delete robot_game;
    robot_game = nullptr;
    
    // reusing the code from solo draw
    draw_screen = new DrawScreen(player_names[1], "The Robot");
    connect(draw_screen, SIGNAL(back_to_title()), this, SLOT(from_draw()));
    draw_screen->show();
    this->hide();
}

void Titular::antirobot_loss() {
    robot_game->hide();
    delete robot_game;
    robot_game = nullptr;
    
    robot_loss_screen = new RobotLossScreen();
    connect(robot_loss_screen, SIGNAL(back_to_title()), this, SLOT(from_antirobot_loss()));
}

// ==> On back from stuff

void Titular::on_back_from_game() {
    delete ttt_game;
    ttt_game = nullptr;
    this->show();
}

void Titular::on_back_from_help() {
    delete help_screen;
    help_screen = nullptr;
    this->show();
}

void Titular::on_back_from_sett() {
    this->game_option = game_settings->getGameOption();
    this->playlist_option = game_settings->getPlaylistOption();
    delete game_settings;
    game_settings = nullptr;
    this->show();
}

void Titular::on_back_from_cust() {
    this->player_names[1] = player_settings->Name1();
    this->player_names[2] = player_settings->Name2();
    this->player_chars[1] = player_settings->Char1();
    this->player_chars[2] = player_settings->Char2();
    delete player_settings;
    player_settings = nullptr;
    this->show();
}

void Titular::on_back_from_abts() {
    delete about_us;
    about_us = nullptr;
    this->show();
}

void Titular::on_back_from_lore() {
    delete lore_screen;
    lore_screen = nullptr;
    this->show();
}

void Titular::from_victory() {
    delete victory_screen;
    victory_screen = nullptr;
    this->show();
}

void Titular::from_draw() {
    delete draw_screen;
    draw_screen = nullptr;
    this->show();
}

void Titular::from_grand_victory() {
    delete grand_victory_screen;
    grand_victory_screen = nullptr;
    this->show();
}

void Titular::from_grand_draw() {
    delete grand_draw_screen;
    grand_draw_screen = nullptr;
    this->show();
}

void Titular::from_antirobot_loss() {
    robot_loss_screen->hide();
    delete robot_loss_screen;
    robot_loss_screen = nullptr;
    this->show();
}
