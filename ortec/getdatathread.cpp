#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "getdatathread.h"
#include <mainwindow.h>

GetDataThread::GetDataThread(){
    m_mcb = NULL;
    this->m_mainWindow = NULL;
    this->m_stop = false;
}

void GetDataThread::setMCB(QAxWidget *mcb){
    m_mcb = mcb;
}

void GetDataThread::setFilename(QString filename){
    m_filename = filename;
}

void GetDataThread::stop(bool stop){
    this->m_stop = stop;
}

void GetDataThread::setMainWindos(MainWindow* mw){
    this->m_mainWindow = mw;
}

void GetDataThread::run()
{
    int temp = 0;
    QFile f(m_filename);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open file " << m_filename << " failed\n";
        return;
    }
    QTextStream txtOutput(&f);
    txtOutput << "hi" << endl;
    while(!m_stop){
        QVariant vaData = m_mcb->dynamicCall("GetData(Qint64, Qint64)", 0, 100 );
        QList<QVariant> l = vaData.toList();
        for (int i = 0; i < l.length(); i++ ){
            txtOutput << l[i].toInt() << " ";
        }
        txtOutput << endl;
        temp++;
        sleep(1);
        /*
        txtOutput << temp << " ";
        if(temp % 10 == 9){
            txtOutput << endl;
            emit TestSignal(QString::number(temp));
        }*/
    }

    f.close();
    return;
}
