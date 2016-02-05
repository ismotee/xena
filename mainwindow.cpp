#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QDateTime date = QDateTime::currentDateTime();
    visitorsToday.push_back(date);
    ui->textBrowser->append(date.toString() + ": Visitor added");
    ui->lineEdit->setText(visitorsToday.back().time().toString());

    visitorsCount++;
    ui->lineEdit_2->setText(QString::number(visitorsCount));

}

void MainWindow::on_pushButton_clicked()
{
    if(!visitorsToday.empty()) {
        ui->textBrowser->append(visitorsToday.back().toString() + ": Visitor removed");
        visitorsToday.erase(visitorsToday.end() - 1);
        visitorsCount--;
        ui->lineEdit_2->setText(QString::number(visitorsCount));
    }
    else
        ui->textBrowser->append("no visitors in the list");

    // emptiness needed to check again because of the removal
    if(!visitorsToday.empty())
        ui->lineEdit->setText(visitorsToday.back().time().toString());
    else
        ui->lineEdit->setText("no visitors");

}
