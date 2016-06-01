#include "logdialog.h"
#include "ui_logdialog.h"

LogDialog::LogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogDialog)
{
    ui->setupUi(this);
}

LogDialog::~LogDialog()
{
    delete ui;
}

QString LogDialog::getLogName(){
    return ui->lineEdit->text();
}

void LogDialog::clearLogName(){
    ui->lineEdit->clear();
}
