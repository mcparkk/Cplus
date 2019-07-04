#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *phoneEdit;
    QPushButton *load_Btn;  // load 버튼 
    QPushButton *save_Btn;
    QPushButton *send_Btn;

    void make_widget();     //화면 구현 함수
public slots:
    void clicked_Load();        //버튼 클릭 slot
    void clicked_Save();
    void clicked_Send();

};
#endif // WIDGET_H
