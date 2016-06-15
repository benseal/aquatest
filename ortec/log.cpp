#include "log.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

void Log::cancel()
{
    this->m_data.clear();
    qDebug() << "reset log data " << m_data << endl;
}

void Log::logStep(QString input) {
    this->m_data.append(input);
    this->m_data.append("\n");
    qDebug() << "log append one step " << input << endl;
}

void Log::save(QString fileName) {
    QFile f(fileName);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open file " << fileName << " failed\n";
        return;
    }
    QTextStream txtOutput(&f);
    txtOutput << this->m_data << endl;
    f.close();
    return;
}
