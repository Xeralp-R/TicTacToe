//
//  victory.cpp
//  Maybe
//
//  Created by Reventar on 04/05/2021.
//

#include "victory.hpp"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <string>
#include <QApplication>
#include <QFile>

VictoryScreen::VictoryScreen(QString name,
                             int number,
                             QWidget * parent) : QWidget(parent) {
    this->winner_name = name;
    this->winner_number = number;
    
    setMinimumSize(600, 450);
    setWindowTitle("Victory!");
    
    // constants
    const int button_max_height = 50;
    const int title_text_max_height = 80;
    const int button_max_width = 200;
    //const int regul_text_max_height = 150;
    
    // the title
    titlebox = new QLabel("Congrats");
    titlebox->setAlignment(Qt::AlignCenter);
    titlebox->setMaximumHeight(title_text_max_height);
    titlebox->setObjectName("title");
    
    alsotitlebox = new QLabel("To");
    alsotitlebox->setAlignment(Qt::AlignCenter);
    alsotitlebox->setMaximumHeight(title_text_max_height);
    alsotitlebox->setObjectName("title");
    
    // the text itself
    textbox = new QLabel();
    textbox->setText("Please claim your 0 peso cash prize\n"
                     "at www.example.org. Thank you!");
    textbox->setAlignment(Qt::AlignCenter);
    textbox->setObjectName("paragraph");
    
    // the name
    namebox = new QLabel();
    namebox->setText(this->winner_name + "!");
    namebox->setObjectName(QString::fromStdString("player" + std::to_string(this->winner_number)));
    namebox->setAlignment(Qt::AlignCenter);
    
    // the button to play again
    button_play = new QPushButton("Play Again");
    button_play->setObjectName("playagain");
    button_play->setMaximumHeight(button_max_height);
    button_play->setMaximumWidth(button_max_width);
    
    // the button to finish
    button_finish = new QPushButton("Finish");
    button_finish->setObjectName("finish");
    button_finish->setMaximumHeight(button_max_height);
    button_finish->setMaximumWidth(button_max_width);
    
    // the hboxlayout
    layout_buttons = new QHBoxLayout();
    layout_buttons->addWidget(button_play);
    layout_buttons->addWidget(button_finish);
    
    // the general layout
    layout_general = new QVBoxLayout(this);
    layout_general->addWidget(titlebox);
    layout_general->addWidget(alsotitlebox);
    layout_general->addWidget(namebox);
    layout_general->addWidget(textbox);
    layout_general->addLayout(layout_buttons);
    
    // stylesheet
    QFile help_styles(":/styles/victory.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);
    
    // show
    this->show();
    
    // connect
    connect(button_finish, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(button_play, SIGNAL(clicked()), this, SIGNAL(back_to_title()));
}


GrandVictoryScreen::GrandVictoryScreen(QString name,
                                       int number,
                                       QWidget *parent) :
QWidget(parent), winner_name(name), winner_number(number){
    setMinimumSize(600, 450);
    setWindowTitle("Victory Royale!");
    this->setObjectName(QString::fromStdString("player" +
                                               std::to_string(this->winner_number)));
    
    // constants
    const int button_max_height = 50;
    const int title_text_max_height = 80;
    const int button_max_width = 200;
    //const int regul_text_max_height = 150;
    
    // the title
    titlebox = new QLabel("Victory");
    titlebox->setAlignment(Qt::AlignCenter);
    titlebox->setMaximumHeight(title_text_max_height);
    titlebox->setObjectName("title");
    
    alsotitlebox = new QLabel("Royale");
    alsotitlebox->setAlignment(Qt::AlignCenter);
    alsotitlebox->setMaximumHeight(title_text_max_height);
    alsotitlebox->setObjectName("title");
    
    // the name
    namebox = new QLabel();
    namebox->setText(this->winner_name + "!");
    namebox->setObjectName("namebox");
    namebox->setAlignment(Qt::AlignCenter);
    
    // the text itself
    textbox = new QLabel();
    textbox->setText("We hereby grant you bragging rights\n"
                     "for the rest of the day. Thank you!");
    textbox->setAlignment(Qt::AlignCenter);
    textbox->setObjectName("paragraph");
    
    // the button to play again
    button_play = new QPushButton("Play Again");
    button_play->setObjectName("playagain");
    button_play->setMaximumHeight(button_max_height);
    button_play->setMaximumWidth(button_max_width);
    
    // the button to finish
    button_finish = new QPushButton("Finish");
    button_finish->setObjectName("finish");
    button_finish->setMaximumHeight(button_max_height);
    button_finish->setMaximumWidth(button_max_width);
    
    // the hboxlayout
    layout_buttons = new QHBoxLayout();
    layout_buttons->addWidget(button_play);
    layout_buttons->addWidget(button_finish);
    
    // the general layout
    layout_general = new QVBoxLayout(this);
    layout_general->addWidget(titlebox);
    layout_general->addWidget(alsotitlebox);
    layout_general->addWidget(namebox);
    layout_general->addWidget(textbox);
    layout_general->addLayout(layout_buttons);
    
    // stylesheet
    QFile help_styles(":/styles/grandvictory.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);
    
    // show
    this->show();
    
    // connect
    connect(button_finish, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(button_play, SIGNAL(clicked()), this, SIGNAL(back_to_title()));
}
