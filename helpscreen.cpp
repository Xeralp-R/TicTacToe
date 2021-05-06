#include "helpscreen.h"
#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QFile>
#include <QString>

HelpScreen::HelpScreen(QWidget *parent) : QWidget(parent)
{
    const int button_max_height = 50;
    const int text_max_height = 100;
    // Set size of the window
    setMinimumSize(600, 450);
    setWindowTitle("How Do I Play?");

    button_explain = new QPushButton(this);
    //button_refresher = new QPushButton(this);
    button_home = new QPushButton(this);
    button_mode = new QPushButton(this);

    button_explain->setText("What is Tic Tac Toe?");
    //button_refresher->setText("How Do You Play This Implementation?");
    button_home->setText("Back to Home");
    button_mode->setText("About Modes");

    button_explain->setObjectName("button_explain");
    //button_refresher->setObjectName("button_refresher");
    button_home->setObjectName("button_home");
    button_mode->setObjectName("button_modes");

    button_explain->setMaximumHeight(button_max_height);
    //button_refresher->setMaximumHeight(button_max_height);
    button_home->setMaximumHeight(button_max_height);
    button_mode->setMaximumHeight(button_max_height);

    title_help = new QLabel();
    title_help->setText("Help");
    title_help->setAlignment(Qt::AlignCenter);
    title_help->setMaximumHeight(text_max_height);
    title_help->setObjectName("title");

    layout_help = new QVBoxLayout(this);
    layout_help->addWidget(title_help);
    layout_help->addWidget(button_explain);
    //layout_help->addWidget(button_refresher);
    layout_help->addWidget(button_mode);
    layout_help->addWidget(button_home);

    QFile help_styles(":/styles/helpscreen.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);

    this->show();

    connect(button_home, SIGNAL(clicked()), this, SLOT(go_back_to_home()));
    connect(button_explain, SIGNAL(clicked()), this, SLOT(on_button_expl_clicked()));
    connect(button_mode, SIGNAL(clicked()), this, SLOT(on_button_mode_clicked()));
}

void HelpScreen::go_back_to_home() {
    emit back_to_home();
}

void HelpScreen::on_button_expl_clicked() {
    explain_help_screen = new ExplainHelpScreen;
    connect(explain_help_screen, SIGNAL(back_to_help()), this, SLOT(on_back_from_expl()));
    explain_help_screen->show();
    this->hide();
}

void HelpScreen::on_back_from_expl() {
    delete explain_help_screen;
    this->show();
}

void HelpScreen::on_button_mode_clicked() {
    mode_help_screen = new ModeHelpScreen;
    connect(mode_help_screen, SIGNAL(back_to_help()), this, SLOT(on_back_from_mode()));
    mode_help_screen->show();
    this->hide();
}

void HelpScreen::on_back_from_mode() {
    delete mode_help_screen;
    this->show();
}

//The explanation
ExplainHelpScreen::ExplainHelpScreen(QWidget * parent) : QWidget(parent) {
    //const int button_max_height = 50;
    const int button_max_height = 50;
    const int title_text_max_height = 100;
    const int regul_text_max_height = 150;

    setMinimumSize(600, 450);
    setWindowTitle("What Is Tic Tac Toe?");

    explain_help_title = new QLabel;
    explain_help_title->setText("Help");
    explain_help_title->setAlignment(Qt::AlignCenter);
    explain_help_title->setMaximumHeight(title_text_max_height);
    explain_help_title->setObjectName("title");

    explain_help_text1 = new QLabel;
    explain_help_text1->setText(
        "\"Tic Tac Toe (American English)...\n"
        "is a paper-and-pencil game for two players...\n"
        "who take turns marking the spaces in a 3×3 grid."
    );
    explain_help_text1->setAlignment(Qt::AlignCenter);
    explain_help_text1->setMaximumHeight(regul_text_max_height);
    explain_help_text1->setObjectName("paragraph");

    explain_help_text2 = new QLabel;
    explain_help_text2->setText(
        "The player who succeeds in placing three of their marks\n"
        "in a diagonal, horizontal, or vertical row is the winner.\"\n"
        "Wikipedia"
    );
    explain_help_text2->setAlignment(Qt::AlignCenter);
    explain_help_text2->setMaximumHeight(regul_text_max_height);
    explain_help_text2->setObjectName("paragraph");

    explain_help_text3 = new QLabel;
    explain_help_text3->setText(
        "Depending on your game version,\n"
        "You may have the option to customize which character you mark,\n"
        "your player name, or the size of the board."
    );
    explain_help_text3->setAlignment(Qt::AlignCenter);
    explain_help_text3->setMaximumHeight(regul_text_max_height);
    explain_help_text3->setObjectName("paragraph");

    explain_help_button1 = new QPushButton("Back to Help", this);
    explain_help_button1->setMaximumHeight(button_max_height);

    explain_help_layout = new QVBoxLayout(this);
    explain_help_layout->addWidget(explain_help_title);
    explain_help_layout->addWidget(explain_help_text1);
    explain_help_layout->addWidget(explain_help_text2);
    explain_help_layout->addWidget(explain_help_text3);
    explain_help_layout->addWidget(explain_help_button1);

    QFile help_styles(":/styles/helpscreen.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);

    this->show();

    connect(explain_help_button1, SIGNAL(clicked()), this, SLOT(go_back_to_help()));
}

void ExplainHelpScreen::go_back_to_help() {
    emit back_to_help();
}

// about mode stuff
ModeHelpScreen::ModeHelpScreen(QWidget * parent) : QWidget (parent) {
    const int button_max_height = 50;
    const int title_text_max_height = 100;
    const int regul_text_max_height = 150;

    setMinimumSize(600, 450);
    setWindowTitle("About Modes");

    mode_help_title = new QLabel;
    mode_help_title->setText("Help");
    mode_help_title->setAlignment(Qt::AlignCenter);
    mode_help_title->setMaximumHeight(title_text_max_height);
    mode_help_title->setObjectName("title");

    mode_help_text1 = new QLabel;
    mode_help_text1->setText(
        "The normal mode is called Regular Mode.\n"
        "The victor is declared upon finishing 1 game,\n"
        "and is played against another person."
    );
    mode_help_text1->setAlignment(Qt::AlignCenter);
    mode_help_text1->setMaximumHeight(regul_text_max_height);
    mode_help_text1->setObjectName("paragraph");

    mode_help_text2 = new QLabel;
    mode_help_text2->setText(
        "There is an alternative mode called Tourney Mode.\n"
        "The victor is the one who get 3 point in a best-of-5 match,\n"
        "and is also played against another person."
    );
    mode_help_text2->setAlignment(Qt::AlignCenter);
    mode_help_text2->setMaximumHeight(regul_text_max_height);
    mode_help_text2->setObjectName("paragraph");

    mode_help_text3 = new QLabel;
    mode_help_text3->setText(
        "Depending on your version, you may be able to play in Robot Mode.\n"
        "You will play a best-of-1 match against a robot.\n"
        "Please note that the algorithm is incomplete, and may not be excellent."
    );
    mode_help_text3->setAlignment(Qt::AlignCenter);
    mode_help_text3->setMaximumHeight(regul_text_max_height);
    mode_help_text3->setObjectName("paragraph");

    mode_help_button1 = new QPushButton("Back to Help", this);
    mode_help_button1->setMaximumHeight(button_max_height);

    mode_help_layout = new QVBoxLayout(this);
    mode_help_layout->addWidget(mode_help_title);
    mode_help_layout->addWidget(mode_help_text1);
    mode_help_layout->addWidget(mode_help_text2);
    mode_help_layout->addWidget(mode_help_text3);
    mode_help_layout->addWidget(mode_help_button1);

    QFile help_styles(":/styles/helpscreen.qss");
    help_styles.open(QFile::ReadOnly);
    QString help_string{ QLatin1String(help_styles.readAll()) };
    this->setStyleSheet(help_string);

    this->show();

    connect(mode_help_button1, SIGNAL(clicked()), this, SLOT(go_back_to_help()));
}

void ModeHelpScreen::go_back_to_help() {
    emit back_to_help();
}
