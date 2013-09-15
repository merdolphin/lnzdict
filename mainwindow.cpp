#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QProcess>

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


void MainWindow::on_lineEditInput_returnPressed()
{

   // ui->textEditshowMeaning->clear();

    QString lookforword;
    lookforword = ui->lineEditInput->text();

    QProcess::execute("ls");
}

void MainWindow::on_pushButtonHistory_clicked()
{
    QString readFileName = "/home/lina/.dict_history";
    if(!readFileName.isEmpty()){
        QFile file(readFileName);
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        ui->textEditHistory->setText(in.readAll());
    }
}
