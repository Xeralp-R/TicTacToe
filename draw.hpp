//
//  draw.hpp
//  Maybe
//
//  Created by Reventar on 05/05/2021.
//

#ifndef draw_hpp
#define draw_hpp

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
QT_END_NAMESPACE

class DrawScreen : public QWidget {
    Q_OBJECT
public:
    explicit DrawScreen(QString name1, QString name2, QWidget * parent = nullptr);
    virtual ~DrawScreen() {};
signals:
    void back_to_title();
private:
    // ==> Visible Variables
    QVBoxLayout * layout_general;
    QLabel * titlebox;
    QLabel * textbox;
    QHBoxLayout * layout_buttons;
    QPushButton * button_play;
    QPushButton * button_finish;
    
    // ==> Invisible Variables
    QString winner1;
    QString winner2;
};

class GrandDrawScreen : public QWidget {
    Q_OBJECT
public:
    explicit GrandDrawScreen(QWidget * parent = nullptr);
signals:
    void back_to_title();
private:
    // ==> Visible Variables
    QVBoxLayout * layout_general;
    QLabel * titlebox;
    QLabel * alsotitlebox;
    QLabel * textbox;
    QHBoxLayout * layout_buttons;
    QPushButton * button_play;
    QPushButton * button_finish;
};

class RobotLossScreen : public QWidget {
    Q_OBJECT
public:
    explicit RobotLossScreen(QWidget * parent = nullptr);
signals:
    void back_to_title();
private:
    // ==> Visible Variables
    QVBoxLayout * layout_general;
    QLabel * titlebox;
    QLabel * alsotitlebox;
    QLabel * textbox;
    QHBoxLayout * layout_buttons;
    QPushButton * button_play;
    QPushButton * button_finish;
};

#endif /* draw_hpp */
