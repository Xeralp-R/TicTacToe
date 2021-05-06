//
//  playersettings.hpp
//  Maybe
//
//  Created by Reventar on 18/04/2021.
//

#ifndef playersettings_hpp
#define playersettings_hpp

#include <QWidget>
#include <QString>
#include <QChar>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QVBoxLayout;
class QFormLayout;
class QLineEdit;
class QGroupBox;
//class QString;
QT_END_NAMESPACE

class PlayerSettings : public QWidget {
    Q_OBJECT
public:
    explicit PlayerSettings(QString name1 = "adam",
                            QString name2 = "eve",
                            QChar char1 = 'O',
                            QChar char2 = 'X',
                            QWidget *parent = nullptr);
    /*
    void setName1(QString given_s);
    void setName2(QString given_s);
    void setChar1(QChar given_c);
    void setChar2(QChar given_c);
    */
    QString Name1();
    QString Name2();
    QChar Char1();
    QChar Char2();
signals:
    void back_to_home();
private:
    // ==> Visual Components
    
    // Overarching stuff
    QVBoxLayout * psett_layout_gen;
    QLabel * psett_title;
    
    // Player 1 Box
    QGroupBox * psett_box1;
    QFormLayout * psett_layout_box1;
    QLabel * psett_namelabel1;
    QLineEdit * psett_nameedit1;
    QLabel * psett_charlabel1;
    QLineEdit * psett_charedit1;
    
    // Player 2 Box
    QGroupBox * psett_box2;
    QFormLayout * psett_layout_box2;
    QLabel * psett_namelabel2;
    QLineEdit * psett_nameedit2;
    QLabel * psett_charlabel2;
    QLineEdit * psett_charedit2;
    
    // button out
    QPushButton * psett_button_home;
    
    // ==> Non-Visual Components: Variables
    
    // The New Name, which can change
    QString NewName1 = "";
    QString NewName2 = "";
    // The old name, which shouldn't change
    //QString OldName1 = "";
    //QString OldName2 = "";
    // The new characters, which can change
    QChar NewChar1 = char(32);
    QChar NewChar2 = char(32);
    // The old characters, which can't change
    //QChar OldChar1 = char(32);
    //QChar OldChar2 = char(32);
};

#endif /* playersettings_hpp */
