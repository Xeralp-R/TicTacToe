//
//  victory.hpp
//  Maybe
//
//  Created by Reventar on 04/05/2021.
//

#ifndef victory_hpp
#define victory_hpp

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
QT_END_NAMESPACE

class VictoryScreen : public QWidget {
    Q_OBJECT
public:
    explicit VictoryScreen(QString name,
                           int number,
                           QWidget * parent = nullptr);
signals:
    void back_to_title();
private:
    // ==> Visible Variables
    QVBoxLayout * layout_general;
    QLabel * titlebox;
    QLabel * alsotitlebox;
    QLabel * textbox;
    QLabel * namebox;
    QHBoxLayout * layout_buttons;
    QPushButton * button_play;
    QPushButton * button_finish;
    
    // ==> Invisible Variables
    QString winner_name;
    int winner_number;
};

#endif /* victory_hpp */
