#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QtMath>

double Number;

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
    connect(ui->pushButton_plus, SIGNAL(pressed()), this, SLOT(operations()));
    connect(ui->pushButton_minus, SIGNAL(pressed()), this, SLOT(operations()));
    connect(ui->pushButton_ravno, SIGNAL(pressed()), this, SLOT(Ravno()));
    connect(ui->pushButton_clear, SIGNAL(pressed()), this, SLOT(clear_all()));
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear_all()
{
    ui->display->clear();
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

void MainWindow::operations()
{
    QPushButton *Button = (QPushButton *)sender();
    Number = ui->display->text().toDouble();
    ui->display->clear();
    Button->setChecked(true);
}

void MainWindow::Ravno()
{
    double znachenie;
    double second_number;
    QString resultat;
    second_number = ui->display->text().toDouble();
    if(ui->pushButton_plus->isChecked())
    {
        znachenie = Number + second_number;
        ui->pushButton_plus->setChecked(false);
    }
    else(ui->pushButton_minus->isChecked());
    {
        znachenie = Number - second_number;
        ui->pushButton_minus->setChecked(false);
    }
    resultat=QString::number(znachenie);
    ui->display->setText(resultat);
}
