#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QLabel *chk_show_label;
    QButtonGroup *btnGrp;

public slots:                  //이벤트를 처리하는 함수
    void checked_btn(int id);
};

#endif // WIDGET_H
