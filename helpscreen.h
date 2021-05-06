#ifndef HELPSCREEN_H
#define HELPSCREEN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
    class QPushButton;
    class QVBoxLayout;
    class QLabel;
    class ExplainHelpScreen;
    class ModeHelpScreen;
QT_END_NAMESPACE

// The General Help Screen
class HelpScreen : public QWidget
{
    Q_OBJECT
public:
    explicit HelpScreen(QWidget *parent = nullptr);

signals:
    void back_to_home();
private slots:
    void go_back_to_home();
    void on_button_expl_clicked();
    void on_back_from_expl();
    void on_button_mode_clicked();
    void on_back_from_mode();
private:
    QVBoxLayout * layout_help;
    QLabel * title_help;
    QPushButton * button_explain;
    QPushButton * button_refresher;
    QPushButton * button_mode;
    QPushButton * button_home;
    ExplainHelpScreen * explain_help_screen;
    ModeHelpScreen * mode_help_screen;
};

// The explain help screen
class ExplainHelpScreen : public QWidget {
    Q_OBJECT
public:
    explicit ExplainHelpScreen(QWidget * parent = nullptr);
signals:
    void back_to_help();
private slots:
    void go_back_to_help();
private:
    QVBoxLayout * explain_help_layout;
    QLabel * explain_help_title;
    QLabel * explain_help_text1;
    QLabel * explain_help_text2;
    QLabel * explain_help_text3;
    QPushButton * explain_help_button1;
};

// The mode help screen
class ModeHelpScreen : public QWidget {
    Q_OBJECT
public:
    explicit ModeHelpScreen(QWidget * parent = nullptr);
signals:
    void back_to_help();
private slots:
    void go_back_to_help();
private:
    QVBoxLayout * mode_help_layout;
    QLabel * mode_help_title;
    QLabel * mode_help_text1;
    QLabel * mode_help_text2;
    QLabel * mode_help_text3;
    QPushButton * mode_help_button1;
};

#endif // HELPSCREEN_H
