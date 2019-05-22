#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class calculator : public QWidget
{
    Q_OBJECT

public:
    calculator(QWidget *parent = 0);
    ~calculator();

private :
    void createButton();
    QLineEdit *display;
    QPushButton *digitBtn[10];
    QPushButton *createButton(const QString &text, const char *member);

    bool waitcalc = true;
    QString m_operator;
    double leftValue;
    double rightValue;
    double m_result;
    void createUI();

private slots:
    void digitClicked();
    void calculate();
    void operatorClicked();
    void singleOperatorClicked();
    void clearClicked();
    void clearAllClicked();
    void backspaceClicked();
    void pointClicked();


};

#endif // CALCULATOR_H
