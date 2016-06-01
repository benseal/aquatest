#ifndef LOGDIALOG_H
#define LOGDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class LogDialog;
}

class LogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogDialog(QWidget *parent = 0);
    ~LogDialog();
    QString getLogName();
    void clearLogName();
private:
    Ui::LogDialog *ui;
};

#endif // LOGDIALOG_H
