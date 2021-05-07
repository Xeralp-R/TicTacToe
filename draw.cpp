//
//  draw.cpp
//  Maybe
//
//  Created by Reventar on 05/05/2021.
//

#include "draw.hpp"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <string>
#include <QApplication>
#include <QFile>

DrawScreen::DrawScreen(QString name1,
                       QString name2,
                       QWidget * parent)
    : QWidget(parent), winner1(name1), winner2(name2) {
	setMinimumSize(600, 450);
	setWindowTitle("Draw!");
		
	// constants
	const int button_max_height = 50;
	const int title_text_max_height = 100;
	const int button_max_width = 200;
	//const int regul_text_max_height = 150;
		
	// the title
	titlebox = new QLabel("Draw");
	titlebox->setAlignment(Qt::AlignCenter);
	titlebox->setMaximumHeight(title_text_max_height);
	titlebox->setObjectName("title");
		
	// the text itself
	textbox = new QLabel();
	textbox->setText("Ah! it looks like there was a draw.\n\n"
					 "I would like to congratulate both players\n" +
					 winner1 + "\nand\n" + winner2 +
					 "\nfor outsmarting each other in Tic-Tac-Toe.");
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
	layout_general->addWidget(textbox);
	layout_general->addLayout(layout_buttons);
    
    // stylesheet
    QFile help_styles(":/styles/draw.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);
		
	// show
	this->show();
		
	// connect
	connect(button_finish, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
	connect(button_play, SIGNAL(clicked()), this, SIGNAL(back_to_title()));
}

GrandDrawScreen::GrandDrawScreen(QWidget *parent) : QWidget(parent) {
    setMinimumSize(600, 450);
    setWindowTitle("Draw!");
    
    // constants
    const int button_max_height = 50;
    const int title_text_max_height = 100;
    const int button_max_width = 200;
    //const int regul_text_max_height = 150;
    
    // the title
    titlebox = new QLabel("Grand");
    titlebox->setAlignment(Qt::AlignCenter);
    titlebox->setMaximumHeight(title_text_max_height);
    titlebox->setObjectName("title");
    
    // also the title
    alsotitlebox = new QLabel("Draw!");
    alsotitlebox->setAlignment(Qt::AlignCenter);
    alsotitlebox->setMaximumHeight(title_text_max_height);
    alsotitlebox->setObjectName("titleb");
    
    // the text itself
    textbox = new QLabel();
    textbox->setText("Hm! It looks like there's still a draw!\n"
                     "I would like to congratulate both players\n"
                     "for outsmarting each other in Tic-Tac-Toe,"
                     "five times over.");
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
    layout_general->addWidget(textbox);
    layout_general->addLayout(layout_buttons);
    
    // stylesheet
    QFile help_styles(":/styles/granddraw.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);
    
    // show
    this->show();
    
    // connect
    connect(button_finish, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(button_play, SIGNAL(clicked()), this, SIGNAL(back_to_title()));
}
