#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    createHBoxLayout();                    //createHBoxLayout 호출
    createGridLayout();
    createFormLayout();
    QVBoxLayout *mainLayout = new QVBoxLayout;      //전체적인 위젯을 세로배치
    mainLayout->addWidget(hGrpBox);
    mainLayout->addWidget(gGrpBox);
    mainLayout->addWidget(fGrpBox);
    this->setLayout(mainLayout);
}

Dialog::~Dialog()
{

}

void Dialog::createHBoxLayout()
{
    hGrpBox = new QGroupBox("Horizontal layout");
    QHBoxLayout *layout = new QHBoxLayout;          //가로박스 레이아웃 생성
    QPushButton *button[4];                         //푸쉬버튼 4개 생성

    for(int i=0; i<4; i++)
    {
        button[i] = new QPushButton(tr("Button %1").arg(i+1));
        layout->addWidget(button[i]);
    }
    hGrpBox-> setLayout(layout);                    //hGrpBox에 레이아웃 지정
}

void Dialog::createGridLayout()
{
    gGrpBox = new QGroupBox("Grid layout");
    QGridLayout *layout = new QGridLayout;

    QLabel *labels[3];
    QLineEdit *lineEdit[3];

    for(int i =0; i<3; i++)
    {
        labels[i] = new QLabel(tr("line %1").arg(i+1));
        lineEdit[i] = new QLineEdit;

        layout->addWidget(labels[i], i,0);
        layout->addWidget(lineEdit[i],i,1);
    }
    QTextEdit *smallEdit = new QTextEdit;
    smallEdit->setText("text Edit");
    layout->addWidget(smallEdit,0,2,3,1);               //행, 열, 행3칸, 열1칸

    gGrpBox->setLayout(layout);
}
void Dialog::createFormLayout()

{
    fGrpBox = new QGroupBox("Form Layout");
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel("Line 1:"),
                   new QLineEdit);
    layout->addRow(new QLabel("Line 2 long test:"),
                   new QComboBox);
    layout->addRow(new QLabel("Line 3:"),
                   new QSpinBox);
    fGrpBox->setLayout(layout);
}
