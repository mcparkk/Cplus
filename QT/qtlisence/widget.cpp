#include "widget.h"
#include <QCheckBox>
#include <QButtonGroup>
#include <QString>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QString chk_label[6] = {"A","B","C","D","E","F"};
    QCheckBox *chk_btn[6];
    btnGrp = new QButtonGroup(this);
    int x_pos = 30;
    int y_pos = 30;
    for(int i = 0; i<6; i++)
    {
        chk_btn[i] = new QCheckBox(chk_label[i],this);
        btnGrp->addButton(chk_btn[i]);
        if(i<3)
            chk_btn[i]-> setGeometry(x_pos,y_pos+(i*40),100,30);
        else
        {
           chk_btn[i]->setGeometry(x_pos+120,y_pos+((i-3)*40),100,30);
        }
    }

    btnGrp->setExclusive(true);

    chk_show_label = new QLabel(this);
    chk_show_label->setGeometry(30,170,200,30);
    chk_show_label->setText("DEFAULT");

    connect(btnGrp, SIGNAL(buttonClicked(int)),
            this,SLOT(checked_btn(int)));




/*
    QCheckBox *chk_a = new QCheckBox("A", this);  //this - 위젯에 속하게..
    chk_a-> setChecked(true);
    chk_a-> setGeometry(30,30,100,30);      //위치 설정 좌표값
    QCheckBox *chk_b = new QCheckBox("B",this);
    chk_b-> setGeometry(30,70,100,30);
    QCheckBox *chk_c = new QCheckBox("C", this);
    chk_c-> setGeometry(30,110,100,30);
    QCheckBox *chk_d = new QCheckBox("D", this);
    chk_d-> setGeometry(150,30,100,30);
    QCheckBox *chk_e = new QCheckBox("E", this);
    chk_e-> setGeometry(150,70,100,30);
    QCheckBox *chk_f = new QCheckBox("F",this);
    chk_f-> setGeometry(150,110,100,30);


    QButtonGroup *btnGrp = new QButtonGroup(this);
    btnGrp->addButton(chk_a);
    btnGrp->addButton(chk_b);
    btnGrp->addButton(chk_c);
    btnGrp->addButton(chk_d);
    btnGrp->addButton(chk_e);
    btnGrp->addButton(chk_f);
    btnGrp->setExclusive(true);
*/
}

void Widget::checked_btn(int id)
{
    qDebug() << btnGrp-> button(id)->text();
    QString print_label = btnGrp->button(id)->text() + " is checked";
    chk_show_label->setText(print_label);
    //btnGrp->button(id)->text()
}

Widget::~Widget()
{

}
