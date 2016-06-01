#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <logdialog.h>
#include <getdatathread.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

private slots:
    void on_actionConnect_triggered();

    void on_actionLog_triggered();
    void setStatusBarMessage(QString msg);

private:
    Ui::MainWindow *ui;
    //UMCBILib::UCONN m_conn;
    bool m_isDevOpen;
    LogDialog* m_logDlg;
    QString m_logName;
    GetDataThread m_dataThread;
};

#endif // MAINWINDOW_H
