#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H

#include <QDialog>
#include <QObject>
#include <QThread>
#include <chrono>
#include <thread>
#include"woker.h"
#include<QProgressBar>
#include"file.h"
#include<QString>

namespace Ui {
class TimeDialog;
}

class TimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeDialog(QWidget *parent = nullptr);
    ~TimeDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TimeDialog *ui;
    QThread* m_thread = nullptr;
    Worker*  m_worker = nullptr;
};

#endif // TIMEDIALOG_H
