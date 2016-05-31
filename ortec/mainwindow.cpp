#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_actionConnect_triggered()
{
    //m_conn.SetAddress("#l");
    //m_conn.Open();
    QString addr;
    addr.append("#1");
    ui->mcbConn->dynamicCall("SetAddress(QString)",addr);
    ui->mcbConn->dynamicCall("Open()");
    ui->textEdit->setText("hello");
}
