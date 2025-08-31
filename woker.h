#ifndef WOKER_H
#define WOKER_H
#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public slots:
    void run();
signals:
    void timeChanged(qint64 min, qint64 sec);
    void finished();
};

#endif // WOKER_H
