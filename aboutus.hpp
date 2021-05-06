//
//  aboutus.hpp
//  Maybe
//
//  Created by Reventar on 30/04/2021.
//

#ifndef aboutus_hpp
#define aboutus_hpp

//#include <stdio.h>
#include <QWidget>
//#include <QString>
//#include <QChar>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QVBoxLayout;
class QGroupBox;
class QScrollArea;
class QHBoxLayout;
QT_END_NAMESPACE

class AboutUs : public QWidget {
    Q_OBJECT
public:
    explicit AboutUs(QWidget *parent = nullptr);
signals:
    void back_to_home();
private:
    // ==> Visual Components
    
    // Overarching
    QVBoxLayout * abts_lgen;
    QLabel * abts_title;
    QScrollArea * abts_scroller;
    QWidget * abts_scrolee;
    QVBoxLayout * abts_scrollay;
    QPushButton * abts_button_home;
    
    // The boxes
    QGroupBox * abts_box1;
    QVBoxLayout * abts_b1layout;
    QLabel * abts_b1pic;
    QLabel * abts_b1text;
    QGroupBox * abts_box2;
    QVBoxLayout * abts_b2layout;
    QLabel * abts_b2pic;
    QLabel * abts_b2text;
    QGroupBox * abts_boxl;
    QVBoxLayout * abts_bllayout;
    QLabel * abts_bltext;
};

class LoreScreen : public QWidget {
    Q_OBJECT
public:
    explicit LoreScreen(QWidget *parent = nullptr);
signals:
    void back_to_home();
private:
    QVBoxLayout * lore_layout;
    QLabel * lore_title;
    QLabel * lore_text;
    QPushButton * lore_button_home;
    QGroupBox * lore_box;
    QHBoxLayout * lore_boxlay;
};

#endif /* aboutus_hpp */
