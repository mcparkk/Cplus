#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:

    QGroupBox *hGrpBox;
    QGroupBox *gGrpBox;
    QGroupBox *fGrpBox;

    void createHBoxLayout();
    void createGridLayout();
    void createFormLayout();
};

#endif // DIALOG_H
