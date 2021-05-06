//
//  playersettings.cpp
//  Maybe
//
//  Created by Reventar on 18/04/2021.
//

#include "playersettings.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QFile>
#include <QVBoxLayout>

PlayerSettings::PlayerSettings(QString name1,
                        QString name2,
                        QChar char1,
                        QChar char2,
                        QWidget *parent) : QWidget(parent) {
    //const int text_max_height = 40;
    const int button_max_height = 50;
    const int title_text_max_height = 100;
    //const int regul_text_max_height = 150;
    
    setMinimumSize(600, 450);
    setWindowTitle("Player Settings");
    
    // Title Stuff
    psett_title = new QLabel("Settings", this);
    psett_title->setMaximumHeight(title_text_max_height);
    psett_title->setAlignment(Qt::AlignHCenter);
    psett_title->setObjectName("title");
    
    // Set the 1st Player Box
    psett_namelabel1 = new QLabel("Name:");
    psett_namelabel1->setObjectName("qualifier");
    psett_namelabel1->setToolTip("Name of player 1.");
    psett_nameedit1 = new QLineEdit();
    psett_nameedit1->setInputMask("Xxxxxxxxxxxx");
    psett_nameedit1->setText(name1);
    psett_charlabel1 = new QLabel("Character:");
    psett_charlabel1->setObjectName("qualifier");
    psett_charlabel1->setToolTip("Player 1's chip on the tic-tac-toe board.");
    psett_charedit1 = new QLineEdit();
    psett_charedit1->setInputMask("X");
    psett_charedit1->setText(QString(char1));
    // Set the layout and other stuff
    psett_layout_box1 = new QFormLayout();
    psett_layout_box1->addRow(psett_namelabel1, psett_nameedit1);
    psett_layout_box1->addRow(psett_charlabel1, psett_charedit1);
    psett_box1 = new QGroupBox();
    psett_box1->setLayout(psett_layout_box1);
    psett_box1->setTitle("Player 1 Stuff");
    
    // Set the 2nd Player Box
    psett_namelabel2 = new QLabel("Name:");
    psett_namelabel2->setObjectName("qualifier");
    psett_namelabel2->setToolTip("Name of Player 2");
    psett_nameedit2 = new QLineEdit();
    psett_nameedit2->setInputMask("Xxxxxxxxxxxx");
    psett_nameedit2->setText(name2);
    psett_charlabel2 = new QLabel("Character:");
    psett_charlabel2->setObjectName("qualifier");
    psett_charlabel2->setToolTip("Player 2's chip on the tic-tac-toe board");
    psett_charedit2 = new QLineEdit();
    psett_charedit2->setInputMask("X");
    psett_charedit2->setText(QString(char2));
    // Set the layout again
    psett_layout_box2 = new QFormLayout();
    psett_layout_box2->addRow(psett_namelabel2, psett_nameedit2);
    psett_layout_box2->addRow(psett_charlabel2, psett_charedit2);
    psett_box2 = new QGroupBox();
    psett_box2->setLayout(psett_layout_box2);
    psett_box2->setTitle("Player 2 Stuff");
    
    // Set the button stuff
    psett_button_home = new QPushButton("Return to home");
    psett_button_home->setMaximumHeight(button_max_height);
    psett_button_home->setObjectName("home");
    
    // set up the final box
    psett_layout_gen = new QVBoxLayout(this);
    psett_layout_gen->addWidget(psett_title);
    psett_layout_gen->addWidget(psett_box1);
    psett_layout_gen->addWidget(psett_box2);
    psett_layout_gen->addWidget(psett_button_home);
    
    QFile help_styles(":/styles/playersettings.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);
    
    this->show();
    
    connect(psett_button_home, SIGNAL(clicked()), this, SIGNAL(back_to_home()));
}

QString PlayerSettings::Name1() {
    return psett_nameedit1->text();
}

QString PlayerSettings::Name2() {
    return psett_nameedit2->text();
}

QChar PlayerSettings::Char1() {
    return psett_charedit1->text().at(0);
}

QChar PlayerSettings::Char2() {
    return psett_charedit2->text().at(0);
}
