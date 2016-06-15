#ifndef LOG_H
#define LOG_H

#include <QString>

class Log
{
public:
    void logStep(QString input);
    void save(QString fileName);
    void cancel();

private:
    QString m_data;
};

#endif // LOG_H
