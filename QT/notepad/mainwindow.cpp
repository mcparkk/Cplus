#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainEdit = new QTextEdit(this);             //textedit
    this->setCentralWidget(mainEdit);
    createMenu();
    this->resize(600,900);        //size

    connect(mainEdit, SIGNAL(textChanged()), this, SLOT(slot_textChanged()));
    this->setShortCut();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenu()
{
    QMenuBar *menubar = new QMenuBar(this);         //menubar
    QMenu *menu_File = new QMenu("File");
    QAction *File_new = new QAction("New");
    connect(File_new, SIGNAL(triggered(bool)),
            this, SLOT(slot_new()));
    QAction *File_open = new QAction("Open");
    connect(File_open, SIGNAL(triggered(bool)), this, SLOT(slot_open()));
    QAction *File_save = new QAction("Save");
    connect(File_save, SIGNAL(triggered(bool)), this, SLOT(slot_save()));

    QAction *File_saveAs = new QAction("SaveAs");
    connect(File_saveAs,SIGNAL(triggered(bool)), this, SLOT(slot_saveAs()));
    QAction *File_close = new QAction("Close");
    connect(File_close, SIGNAL(triggered(bool)), this, SLOT(slot_close()));

    menu_File->addAction(File_new);
    menu_File->addAction(File_open);
    menu_File->addAction(File_save);
    menu_File->addAction(File_saveAs);
    menu_File->addAction(File_close);

    QMenu *menu_Edit = new QMenu("Edit");
    QAction *edit_undo = new QAction("Undo");
    connect(edit_undo, SIGNAL(triggered(bool)), this, SLOT(slot_undo()));
    QAction *edit_redo = new QAction("Redo");
    connect(edit_redo, SIGNAL(triggered(bool)), this, SLOT(slot_redo()));
    QAction *edit_copy = new QAction("Copy");
    connect(edit_copy, SIGNAL(triggered(bool)), this, SLOT(slot_copy()));
    QAction *edit_paste = new QAction("Paste");
    connect(edit_paste, SIGNAL(triggered(bool)), this, SLOT(slot_paste()));

    menu_Edit->addAction(edit_undo);
    menu_Edit->addAction(edit_redo);
    menu_Edit->addAction(edit_copy);
    menu_Edit->addAction(edit_paste);

    QMenu *menu_Form = new QMenu("Form");
    QAction *form_font = new QAction("Font");

    menu_Form->addAction(form_font);
    connect(form_font, SIGNAL(triggered(bool)), this, SLOT(slot_font()));

    QMenu *menu_About = new QMenu("About");
    QAction *about_information = new QAction("Information");

    menu_About->addAction(about_information);
    connect(about_information, SIGNAL(triggered(bool)), this, SLOT(slot_about()));

    menubar->addMenu(menu_File);
    menubar->addMenu(menu_Edit);
    menubar->addMenu(menu_Form);
    menubar->addMenu(menu_About);

    this->setMenuBar(menubar);
    this->menuBar()->setVisible(true);
}

void MainWindow::slot_textChanged()
{
    this->textChanged = true;
}

void MainWindow::slot_new()
{
    if(textChanged)
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        if(ret == QMessageBox::Save)
            slot_saveAs();
        else if(ret==QMessageBox::Cancel)
            return;
        else
            qDebug() << "Discard";


        qDebug()<< "text changed" << ret;
    }
    current_file = "";
    this->setWindowTitle("");
    mainEdit->clear();
    textChanged = false;
}

void MainWindow::slot_open()
{

    if(textChanged)
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        if(ret == QMessageBox::Save)
            slot_saveAs();
        else if(ret==QMessageBox::Cancel)
            return;
        else
            qDebug() << "Discard";


        qDebug()<< "text changed" << ret;
    }

    qDebug() << "slot open";
    QString Filename = QFileDialog::getOpenFileName(this, "open");

    current_file = Filename;
    this-> setWindowTitle(Filename);            //파일 경로와 이름이 타이틀에 뜨도록

    QFile file(Filename);
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
        return;
    QTextStream in(&file);
    QString text = in.readAll();
    mainEdit-> setText(text);
    file.close();
    textChanged = false;
    //add : 내용이 변경되었을 때 저장 가능
}
void MainWindow::slot_saveAs()
{
    qDebug()<< "slot saveAs";
    QString Filename = QFileDialog::getSaveFileName(this, "SaveAs");
    QFile file(Filename);
    if(!file.open(QIODevice::WriteOnly | QFile::Text))
        return;

    current_file = Filename;
    this-> setWindowTitle(Filename);

    QTextStream out(&file);
    QString text = mainEdit->toPlainText();
    out << text;
    file.close();
    textChanged = false;
}
void MainWindow::slot_save()
{
    if(current_file.isEmpty())   //처음 저장인경우
    {
        slot_saveAs();
    }
    else    //그 외의 경우
    {
        QString Filename = current_file;
        QFile file(Filename);
        if(!file.open(QIODevice::WriteOnly |QFile::Text))
            return;

        current_file = Filename;
        this->setWindowTitle(Filename);

        QTextStream out(&file);
        QString text =mainEdit->toPlainText();
        out << text;
        file.close();
    }
    textChanged = false;
}

void MainWindow::slot_close()
{
    if(textChanged)
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        if(ret == QMessageBox::Save)
            slot_saveAs();
        else if(ret==QMessageBox::Cancel)
            return;
        else
            qDebug() << "Discard";


        qDebug()<< "text changed" << ret;
    }
}

void MainWindow::slot_font()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]",10),this);
    if(ok)
    {
        mainEdit-> setFont(font);
    }
    else
    {
        mainEdit-> setFont(font); //"Helvetia [Cronyx]",10 으로 setting
    }
}

void MainWindow::slot_about()
{
    QMessageBox::about(this, tr("about notepad"), tr("........................"));
}

void MainWindow::slot_undo(){mainEdit->undo();}

void MainWindow::slot_redo(){mainEdit->redo();}

void MainWindow::slot_copy(){mainEdit->copy();}

void MainWindow::slot_paste(){mainEdit->paste();}

void MainWindow::setShortCut()
{
    QShortcut *key;
    key = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this);
    connect(key, SIGNAL(activated()), this, SLOT(slot_save()));
    key = new QShortcut(QKeySequence("Ctrl+Shift+S"), this);
    connect(key, SIGNAL(activated()), this, SLOT(slot_saveAs()));
}
