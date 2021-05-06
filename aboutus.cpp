//
//  aboutus.cpp
//  Maybe
//
//  Created by Reventar on 30/04/2021.
//

#include "aboutus.hpp"
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QFile>
#include <QPixmap>
#include <QScrollArea>
#include <QSize>

AboutUs::AboutUs (QWidget * parent) : QWidget(parent) {
    // Constants
    //const int text_max_height = 40;
    const int button_max_height = 50;
    const int title_text_max_height = 100;
    //const int regul_text_max_height = 150;
    const int image_max_width = 200;
    const int text_max_width = 400;
    const int spacer_size = 10;
    const QSize image_max_size (200, 200);
    const int boxl_min_height = 500;
    const int scroller_min_height = 1500;
    
    setMinimumSize(600, 550);
    setWindowTitle("About Us");
    
    // Overarching stuff
    abts_title = new QLabel("About Us", this);
    abts_title->setMaximumHeight(title_text_max_height);
    abts_title->setAlignment(Qt::AlignHCenter);
    abts_title->setObjectName("title");
    
    // My picture and label text
    QPixmap rex_image(":/images/RexImage.png");
    abts_b1pic = new QLabel();
    abts_b1pic->setObjectName("image");
    abts_b1pic->setAlignment(Qt::AlignHCenter);
    if (rex_image.isNull() == false) {
        abts_b1pic->setPixmap(rex_image.scaled(image_max_size, Qt::KeepAspectRatioByExpanding));
        abts_b1pic->setMaximumWidth(image_max_width);
    } else {
        abts_b1pic->setText("Rex's image, failed to load");
        abts_b1pic->setMaximumWidth(text_max_width);
    }
    abts_b1text = new QLabel();
    abts_b1text->setMaximumWidth(text_max_width);
    abts_b1text->setObjectName("paragraph");
    abts_b1text->setWordWrap(true);
    abts_b1text->setAlignment(Qt::AlignHCenter);
    abts_b1text->setText("Hello! "
                         "I am a Grade 8 student in Philipine Science High School, "
                         "which often has us create these sorts of projects. "
                         "I live in Biñan City, Laguna— an hours drive away from Manila, the capital. "
                         "To this code, I contributed much of the interface "
                         "and converted much of the internals from the beta 1.0. "
                         "My hobbies include eating and playing the piano."
                         );
    abts_b1layout = new QVBoxLayout();
    abts_b1layout->addSpacing(spacer_size);
    abts_b1layout->addWidget(abts_b1pic);
    abts_b1layout->addWidget(abts_b1text);
    abts_box1 = new QGroupBox();
    abts_box1->setLayout(abts_b1layout);
    abts_box1->setTitle("About Rex");
    
    // Brent's Stuff
    QPixmap brent_image(":/images/BrentImage.jpg");
    abts_b2pic = new QLabel();
    abts_b2pic->setObjectName("image");
    abts_b2pic->setAlignment(Qt::AlignHCenter);
    if (brent_image.isNull() == false) {
        abts_b2pic->setPixmap(brent_image.scaled(image_max_size, Qt::KeepAspectRatioByExpanding));
        abts_b2pic->setMaximumWidth(image_max_width);
    } else {
        abts_b2pic->setText("Brent's Image, failed to load");
        abts_b2pic->setMaximumWidth(text_max_width);
    }
    abts_b2text = new QLabel();
    abts_b2text->setMaximumWidth(text_max_width);
    abts_b2text->setObjectName("paragraph");
    abts_b2text->setWordWrap(true);
    abts_b2text->setAlignment(Qt::AlignHCenter);
    abts_b2text->setText("Hello! "
                         "I am also a Grade 8 student in Pisay. "
                         "I live in Malabon, which is well known for its excellent 'pansit', "
                         "a type of noodles. "
                         "The co-creator, Rex, does not know Malabon exists— "
                         "please don't bother informing him. "
                         "My hobbies include watching anime. "
                         "(This description was written by Rex.)"
                         );
    abts_b2layout = new QVBoxLayout();
    abts_b2layout->addSpacing(spacer_size);
    abts_b2layout->addWidget(abts_b2pic);
    abts_b2layout->addWidget(abts_b2text);
    abts_box2 = new QGroupBox();
    abts_box2->setLayout(abts_b2layout);
    abts_box2->setTitle("About Brent");
    
    // License Stuff
    abts_bltext = new QLabel();
    abts_bltext->setMaximumWidth(text_max_width);
    abts_bltext->setObjectName("paragraph");
    abts_bltext->setWordWrap(true);
    abts_bltext->setAlignment(Qt::AlignHCenter);
    abts_bltext->setText("Copyright 2021 Rex Alphonse Reventar et al\n\n"
                         // The next par
                         "Permission is hereby granted, free of charge, to any person "
                         "obtaining a copy of this software and associated documentation files "
                         "(the \"Software\"), to deal in the Software without restriction, "
                         "including without limitation the rights to use, copy, modify, merge, "
                         "publish, distribute, sublicense, and/or sell copies of the Software, "
                         "and to permit persons to whom the Software is furnished to do so, "
                         "subject to the following conditions:\n\n"
                         // The next par
                         "The above copyright notice and this permission notice shall be included "
                         "in all copies or substantial portions of the Software.\n\n"
                         // the next par
                         "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, "
                         "EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF "
                         "MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. "
                         "IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY "
                         "CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, "
                         "TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE "
                         "SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. END OF LICENSE.\n\n"
                         // My claiment
                         "Apparently the LGPL needs me to do this? "
                         "I am not a lawyer."
                         );
    abts_bllayout = new QVBoxLayout();
    abts_bllayout->addSpacing(spacer_size);
    abts_bllayout->addWidget(abts_bltext);
    abts_boxl = new QGroupBox();
    abts_boxl->setLayout(abts_bllayout);
    abts_boxl->setTitle("License");
    abts_boxl->setMinimumHeight(boxl_min_height);
    
    // QPushButton to home
    abts_button_home = new QPushButton("Back to Home");
    abts_button_home->setMaximumHeight(button_max_height);
    abts_button_home->setObjectName("home");
    
    // arrange the scroller
    abts_scrollay = new QVBoxLayout();
    abts_scrollay->addWidget(abts_box1);
    abts_scrollay->addWidget(abts_box2);
    abts_scrollay->addWidget(abts_boxl);
    abts_scrolee = new QWidget();
    abts_scrolee->setLayout(abts_scrollay);
    abts_scrolee->setMinimumHeight(scroller_min_height);
    abts_scroller = new QScrollArea;
    abts_scroller->setBackgroundRole(QPalette::Light);
    abts_scroller->setWidget(abts_scrolee);
    abts_scroller->setAlignment(Qt::AlignHCenter);
    
    // set up the entire thingy
    abts_lgen = new QVBoxLayout(this);
    abts_lgen->addWidget(abts_title);
    abts_lgen->addWidget(abts_scroller);
    abts_lgen->addWidget(abts_button_home);
    
    QFile help_styles(":/styles/aboutus.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);
    
    this->show();
    
    connect(abts_button_home, SIGNAL(clicked()), this, SIGNAL(back_to_home()));
}

LoreScreen::LoreScreen(QWidget *parent) : QWidget(parent) {
    const int title_text_max_height = 100;
    const int text_max_width = 400;
    const int button_max_height = 50;
    //const int spacer_size = 10;
    
    setMinimumSize(600, 600);
    setWindowTitle("Lore Screen");
    
    // Title
    lore_title = new QLabel("Lore", this);
    lore_title->setMaximumHeight(title_text_max_height);
    lore_title->setAlignment(Qt::AlignHCenter);
    lore_title->setObjectName("title");
    
    // Text
    lore_text = new QLabel();
    lore_text->setMaximumWidth(text_max_width);
    //lore_text->setContentsMargins(0, 50, 0, 50);
    lore_text->setObjectName("paragraph");
    lore_text->setWordWrap(true);
    lore_text->setAlignment(Qt::AlignCenter);
    lore_text->setText("In the year 2077, all war-like conflicts suddenly came "
                       "to a screeching halt. Amidst the war-torn landscapes of "
                       "the Earth, one man proposed an idea, a game. Instead of "
                       "wars, they played Tic-Tac-Toe, a game of luck and skill. "
                       "However, simple games cannot satiate the hunger for power "
                       "of the world leaders, which is why the Supreme Tic-Tac-Toe "
                       "Tournament was created. It was a decennial event, where "
                       "each of the countries had representatives to play for them. "
                       "The winning representative of this tournament gains an "
                       "uncountable cash prize but most importantly, the country "
                       "they represent becomes the ruling authority of the entire "
                       "world. Are you able to stand among the top as champions of this "
                       "tournament? And most of all, as a representative of your country?"
                       );
    
    // The box for the text
    lore_boxlay = new QHBoxLayout;
    lore_boxlay->addWidget(lore_text);
    lore_box = new QGroupBox;
    lore_box->setLayout(lore_boxlay);
    lore_box->setTitle("Brent's Lore");
    
    // Button
    lore_button_home = new QPushButton("Back to Home");
    lore_button_home->setMaximumHeight(button_max_height);
    lore_button_home->setObjectName("home");
    
    // Layout
    lore_layout = new QVBoxLayout(this);
    lore_layout->addWidget(lore_title);
    lore_layout->addWidget(lore_box);
    lore_layout->addWidget(lore_button_home);
    //lore_layout->setAlignment(Qt::AlignHCenter);
    
    // Screenshot
    QFile help_styles(":/styles/lorescreen.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);
    
    this->show();
    
    connect(lore_button_home, SIGNAL(clicked()), this, SIGNAL(back_to_home()));
}
