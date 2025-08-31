#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QWidget>
#include <QStandardPaths>

class file : public QWidget
{
    Q_OBJECT
public:
    explicit file(QWidget *parent = nullptr);
    void save(QString time_s,QString time_min);

private:

signals:
};

#endif // FILE_H
