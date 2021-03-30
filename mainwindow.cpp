#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_1, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_3, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_4, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_5, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_6, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_7, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_8, SIGNAL(pressed()), this, SLOT(digitClicked()));
    connect(ui->pushButton_9, SIGNAL(pressed()), this, SLOT(digitClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked()
{
    QPushButton *Button = (QPushButton *)sender();
    double string;
    QString update_display;
    string = (ui->display->text() + Button->text()).toDouble();
    update_display=QString::number(string);
    ui->display->setText(update_display);
}
