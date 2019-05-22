#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QString>
#include <QButtonGroup>
#include <QDebug>
#include <QPushButton>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QComboBox *combo;
    QLabel *combo_label;
    QPushButton *back_btn;
    QPushButton *foward_btn;
    QButtonGroup *btn_grp;


public slots:
    void valueChanged(int index);
    void btnClicked(int id);
};

#endif // WIDGET_H
