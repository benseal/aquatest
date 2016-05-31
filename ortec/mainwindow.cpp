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
    QVariant vaData = ui->mcbConn->dynamicCall("GetData(Qint64, Qint64)", 0, 100 );
    QString str = "";
    QList<QVariant> l = vaData.toList();
    for (int i = 0; i < l.length(); i++ ){
        QString tmp = "";
        tmp.sprintf("%d:%d\n", i, l[i].toInt());
        str.append(tmp);
    }
    ui->textEdit->setText(str);
}
