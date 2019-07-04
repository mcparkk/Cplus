#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    make_widget();
}

Widget::~Widget()
{

}

void Widget::make_widget()
{
    QGridLayout *MainLayout = new QGridLayout(this);
    this -> setLayout(MainLayout);
    QLabel *name =new QLabel("Name");
    QLabel *age = new QLabel("Age");
    QLabel *phone = new QLabel("Phone");
    nameEdit = new QLineEdit(this);
    ageEdit = new QLineEdit(this);
    phoneEdit = new QLineEdit(this);
    load_Btn = new QPushButton("Load");
    save_Btn = new QPushButton("Save");
    send_Btn = new QPushButton("Send");

    MainLayout->addWidget(name,0,0);
    MainLayout->addWidget(age,1,0);
    MainLayout->addWidget(phone,2,0);
    MainLayout->addWidget(nameEdit,0,1);
    MainLayout->addWidget(ageEdit,1,1);
    MainLayout->addWidget(phoneEdit,2,1);
    MainLayout->addWidget(load_Btn,0,2);
    MainLayout->addWidget(save_Btn,1,2);
    MainLayout->addWidget(send_Btn,2,2);


    connect(load_Btn, SIGNAL(clicked()), this, SLOT(clicked_Load()));
    connect(save_Btn, SIGNAL(clicked()), this, SLOT(clicked_Save()));
    connect(send_Btn, SIGNAL(clicked()), this, SLOT(clicked_Send()));
}

void Widget::clicked_Load() {}
void Widget::clicked_Save() {}
void Widget::clicked_Send() {}
