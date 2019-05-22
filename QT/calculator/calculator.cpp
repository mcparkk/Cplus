#include "calculator.h"
#include <QGridLayout>
#include <QString>

calculator::calculator(QWidget *parent)
    : QWidget(parent)
{
    this->createUI();
}

calculator::~calculator()
{
    delete [] digitBtn[10];
    delete display;
}

QPushButton *calculator::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void calculator::digitClicked()
{
    QPushButton *clicked = qobject_cast<QPushButton *>(sender());
    int digit = clicked->text().toInt(); //convert QStirng to int
    if(display->text() == "0" && digit == 0){
        return; // ex 00
    }

    if(waitcalc) //waiting For operand
    {
        display->clear();
        waitcalc = false;
    }

    display->setText(display->text() //before number
                     + QString::number(digit)); //after number
    // convert int to Qstring
}
void calculator::operatorClicked()
{
    QPushButton *clicked = qobject_cast<QPushButton *>(sender());
    leftValue = display->text().toDouble(); //[X] oper
    m_operator = clicked->text(); //X [oper]

    waitcalc = true;
}

void calculator::singleOperatorClicked()
{
   QPushButton *clicked = qobject_cast<QPushButton *>(sender());
   leftValue = display->text().toDouble();
   QString singleOperator = clicked->text();

   if(singleOperator == tr("Sqrt"))
       m_result = std::sqr(leftValue);
   else if(singleOperator == tr("x\302\262"))
       m_result = std::pow(leftValue,2);
   else if(singleOperator == tr("1/x"))
       m_result = 1 /(leftValue);
   else {
       return; // temp
   }

   leftValue = m_result;
   m_operator = "";
   rightValue = 0;
   waitcalc = true;
   display->setText(QString::number(m_result));
}
void calculator::calculate()
{
    rightValue = display->text().toDouble();

    if(m_operator == tr("+"))
        m_result = leftValue + rightValue;
    else if(m_operator == tr("-"))
        m_result = leftValue - rightValue;
    else if(m_operator == tr("\303\227")) // *
        m_result = leftValue * rightValue;
    else if(m_operator == tr("\303\267")) // /
        m_result = leftValue / rightValue;
    else {
        return; //temp
    }

    leftValue = m_result;
    m_operator = "";
    rightValue = 0;
    waitcalc = true;
    display->setText(QString::number(m_result));
}
void calculator::clearClicked()
{

    display->setText(QString::number(0));
    waitcalc = true;
}
void calculator::clearAllClicked()
{
    m_operator = "";
    leftValue = 0;
    rightValue = 0;
    display->setText(QString::number(0));
    waitcalc = true;
}

void calculator::backspaceClicked()
{
    QString text = display->text();
    text.chop(1);
    if(text.isEmpty()){
        text="0";
        waitcalc = true;
    }
    display->setText(text);
}

void calculator::pointClicked()
{
    if(waitcalc)
        display->setText("0");
    if(display->text().contains("."))
        return;
    display->setText(display->text() + tr("."));
    waitcalc = false;
}

void calculator::createUI()
{
    display = new QLineEdit("0");
    display->setReadOnly(true);
    for (int i = 0; i < 10; i++) {
        digitBtn[i] = createButton(QString::number(i),SLOT(digitClicked()));
    }
    QPushButton *pointButton = createButton(tr("."), SLOT(pointClicked()));
    QPushButton *changeSignButton = createButton(tr("\302\261"), NULL);

    QPushButton *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    QPushButton *clearButton = createButton(tr("Clear"), SLOT(clearClicked()));
    QPushButton *clearAllButton = createButton(tr("Clear All"), SLOT(clearAllClicked()));

    QPushButton *clearMemoryButton = createButton(tr("MC"), NULL);
    QPushButton *readMemoryButton = createButton(tr("MR"), NULL);
    QPushButton *setMemoryButton = createButton(tr("MS"), NULL);
    QPushButton *addToMemoryButton = createButton(tr("M+"), NULL);

    QPushButton *divisionButton = createButton(tr("\303\267"), SLOT(operatorClicked()));
    QPushButton *timesButton = createButton(tr("\303\227"), SLOT(operatorClicked()));
    QPushButton *minusButton = createButton(tr("-"), SLOT(operatorClicked()));
    QPushButton *plusButton = createButton(tr("+"), SLOT(operatorClicked()));

    QPushButton *squareRootButton = createButton(tr("Sqrt"), SLOT(singleOperatorClicked()));
    QPushButton *powerButton = createButton(tr("x\302\262"), SLOT(singleOperatorClicked()));
    QPushButton *reciprocalButton = createButton(tr("1/x"), SLOT(singleOperatorClicked()));
    QPushButton *equalButton = createButton(tr("="), SLOT(calculate()));


    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(display, 0, 0, 1, 6);
    mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);
    mainLayout->addWidget(clearButton, 1, 2, 1, 2);
    mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);

    mainLayout->addWidget(clearMemoryButton, 2, 0);
    mainLayout->addWidget(readMemoryButton, 3, 0);
    mainLayout->addWidget(setMemoryButton, 4, 0);
    mainLayout->addWidget(addToMemoryButton, 5, 0);

    for (int i = 1; i < 10; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitBtn[i], row, column);
    }

    mainLayout->addWidget(digitBtn[0], 5, 1);
    mainLayout->addWidget(pointButton, 5, 2);
    mainLayout->addWidget(changeSignButton, 5, 3);

    mainLayout->addWidget(divisionButton, 2, 4);
    mainLayout->addWidget(timesButton, 3, 4);
    mainLayout->addWidget(minusButton, 4, 4);
    mainLayout->addWidget(plusButton, 5, 4);

    mainLayout->addWidget(squareRootButton, 2, 5);
    mainLayout->addWidget(powerButton, 3, 5);
    mainLayout->addWidget(reciprocalButton, 4, 5);
    mainLayout->addWidget(equalButton, 5, 5);



    this->setLayout(mainLayout);
}

