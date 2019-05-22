#include "widget.h"
#include <QString>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    combo = new QComboBox(this);
    combo-> setGeometry(50,50,200,30);

    combo_label = new QLabel("DEFAULT",this);
    combo_label -> setGeometry(50,90,200,30);
    //setGeometry(50, 90, 400, 400);

    QString item[6] = {"A","B","C","D","E","F"};
    for(int i=0; i<6; i++)
    {

        combo-> addItem(item[i]);

    }
    back_btn = new QPushButton("<", this);
    foward_btn = new QPushButton(">", this);
    back_btn -> setGeometry(180,130,30,30);
    foward_btn-> setGeometry(220,130,30,30);

    btn_grp = new QButtonGroup(this);
    btn_grp-> addButton(foward_btn);
    btn_grp-> addButton(back_btn);



    connect(combo, SIGNAL(currentIndexChanged(int)), this,SLOT(valueChanged(int)));
    connect(btn_grp, SIGNAL(buttonClicked(int)), this ,SLOT(btnClicked(int)));
}

void Widget::valueChanged(int index)
{
    qDebug() << "Call value changed";
    QString print_label = combo -> itemText(index) + " is selected";
    // = QString print_label = combo->currentText() + " is selected";
    combo_label->setText(print_label);
}
void Widget::btnClicked(int id)
{
    qDebug() << "call btn_clicked";

    if(btn_grp-> button(id)->text()=="<")
    {
        if(combo->currentIndex()==0)
            return;
        combo->setCurrentIndex(combo->currentIndex()-1);
    }
    else if(btn_grp->button(id)->text()==">")
    {
        if(combo->currentIndex() == combo->count()-1)
            return;
        combo->setCurrentIndex(combo->currentIndex()+1);
    }
    else
    {
        return;
    }

}

Widget::~Widget()
{
    delete btn_grp;
    delete combo;
    delete combo_label;
}
