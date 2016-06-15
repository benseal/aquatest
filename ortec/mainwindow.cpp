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
    m_log = new Log();

    ui->actionLog->setStatusTip("Start log");
    m_dataThread.setMCB(ui->mcbConn);
    connect(&this->m_dataThread, SIGNAL(TestSignal(QString)), this, SLOT(setStatusBarMessage(QString)));
}

MainWindow::~MainWindow()
{
    if(m_isDevOpen){
        ui->mcbConn->dynamicCall("Close()");
        m_isDevOpen = false;
    }
    delete m_log;
    delete ui;
}

void MainWindow::setStatusBarMessage(QString msg){
    statusBar()->showMessage(msg);
}

void MainWindow::on_actionConnect_triggered()
{
    if(!m_isDevOpen){
        QString addr;
        addr.append("#1");
        ui->mcbConn->dynamicCall("SetAddress(QString)",addr);
        ui->mcbConn->dynamicCall("Open()");
        m_isDevOpen = true;
        ui->actionConnect->setText("disconnect");
        ui->actionLog->setEnabled(true);
    }else{
        m_log->save("test.log");
        ui->mcbConn->dynamicCall("Close()");
        m_isDevOpen = false;
        ui->actionConnect->setText("connect");
        ui->actionLog->setDisabled(true);
    }

}

void MainWindow::on_actionLog_triggered()
{
    if(ui->actionLog->isChecked()){
        if(QDialog::Rejected == m_logDlg->exec()){
            return;
        }
        ui->actionConnect->setDisabled(true);
        ui->actionLog->setStatusTip("Stop log");

        // do get data
        for (int j = 0; j < 1000; j++ ){
            QVariant vaData = ui->mcbConn->dynamicCall("GetData(Qint64, Qint64)", 0, 1024 );
            QString str = "";
            QList<QVariant> l = vaData.toList();
            for (int i = 0; i < l.length(); i++ ){
                QString tmp = "";
                tmp.sprintf("%d\t", l[i].toInt());
                str.append(tmp);
            }
            m_log->logStep(str);
        }



    }else{
        m_log->logStep("###END###");
        m_log->save(m_logDlg->getLogName());
        ui->actionLog->setEnabled(true);
        ui->actionConnect->setEnabled(true);
        m_logDlg->clearLogName();
        ui->actionLog->setStatusTip("Start log");

    }
}
