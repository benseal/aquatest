#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_isDevOpen = false;
    ui->actionLog->setDisabled(true);
    m_logDlg = new LogDialog(this);

    ui->actionLog->setStatusTip("Start log");
    connect(&this->m_dataThread, SIGNAL(TestSignal(QString)), this, SLOT(setStatusBarMessage(QString)));
}

MainWindow::~MainWindow()
{
    if(m_isDevOpen){
        ui->mcbConn->dynamicCall("Close()");
        m_isDevOpen = false;
    }
    delete ui;
}

void MainWindow::setStatusBarMessage(QString msg){
    statusBar()->showMessage(msg);
}

void MainWindow::on_actionConnect_triggered()
{
    //m_conn.SetAddress("#l");
    //m_conn.Open();
    if(!m_isDevOpen){
        QString addr;
        addr.append("#1");
        ui->mcbConn->dynamicCall("SetAddress(QString)",addr);
        ui->mcbConn->dynamicCall("Open()");
        m_isDevOpen = true;
        ui->actionConnect->setText("disconnect");
        ui->actionLog->setEnabled(true);
    }else{
        ui->mcbConn->dynamicCall("Close()");
        m_isDevOpen = false;
        ui->actionConnect->setText("connect");
        ui->actionLog->setDisabled(true);
    }

//    QVariant vaData = ui->mcbConn->dynamicCall("GetData(Qint64, Qint64)", 0, 100 );
//    QString str = "";
//    QList<QVariant> l = vaData.toList();
//    for (int i = 0; i < l.length(); i++ ){
//        QString tmp = "";
//        tmp.sprintf("%d:%d\n", i, l[i].toInt());
//        str.append(tmp);
//    }
//    ui->textEdit->setText(str);
}

void MainWindow::on_actionLog_triggered()
{
    if(ui->actionLog->isChecked()){
        if(QDialog::Rejected == m_logDlg->exec()){
            return;
        }
        ui->actionConnect->setDisabled(true);
        //ui->actionLog->setDisabled(true);
        ui->actionLog->setStatusTip("Stop log");
        m_dataThread.setFilename(m_logDlg->getLogName());
        m_dataThread.stop(false);
        m_dataThread.start();
    }else{
        m_dataThread.stop(true);
        ui->actionLog->setEnabled(true);
        ui->actionConnect->setEnabled(true);
        m_logDlg->clearLogName();
        ui->actionLog->setStatusTip("Start log");

    }
}
