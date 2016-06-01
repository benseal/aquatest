#ifndef GETDATATHREAD_H
#define GETDATATHREAD_H
#include <ActiveQt/QAxWidget>
#include <QThread>

class MainWindow;

class GetDataThread : public QThread
{
    Q_OBJECT
public:
    GetDataThread();
protected:
     void run();
public:
     void setMCB(QAxWidget *mcb);
     void setFilename(QString filename);
     void stop(bool stop);
     void setMainWindos(MainWindow* mw);
signals:
    void TestSignal(QString);
private:
     QAxWidget *m_mcb;
     QString m_filename;
     bool m_stop;
     MainWindow* m_mainWindow;
};

#endif // GETDATATHREAD_H
