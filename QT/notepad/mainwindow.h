#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QShortcut>
#include <QKeySequence>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

//    void TextChange();
//    ~TextChange();

    QTextEdit *mainEdit;

private:
    void createMenu();
    QString current_file;
    bool textChanged = false;
    void setShortCut();

private slots :
    void slot_textChanged();
    void slot_new();
    void slot_open();
    void slot_saveAs();
    void slot_save();
    void slot_close();
    void slot_undo();
    void slot_redo();
    void slot_copy();
    void slot_paste();
    void slot_font();
    void slot_about();

};
#endif // MAINWINDOW_H
