#include "timedialog.h"
#include "ui_timedialog.h"
#include <QObject>
#include"woker.h"
#include<QProgressBar>
#include<QTimer>
#include <QStandardPaths>

TimeDialog::TimeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TimeDialog)
{
    ui->setupUi(this);
    QFont f("宋体",30);
    ui->textEdit_min->setFont(f);
    ui->textEdit_s->setFont(f);

}

TimeDialog::~TimeDialog()
{
    delete ui;
}

// 启动线程
void TimeDialog::on_pushButton_clicked()
{
    if (m_thread && m_thread->isRunning()) {
        // 防止重复启动
        return;
    }

    m_thread = new QThread(this);
    m_worker = new Worker;
    m_worker->moveToThread(m_thread);

    connect(m_thread, &QThread::started, m_worker, &Worker::run);
    connect(m_worker, &Worker::timeChanged, this, [=](qint64 min, qint64 sec){
        ui->textEdit_min->setText(QString::number(min));
        ui->textEdit_s->setText(QString::number(sec));

    });
    m_thread->start();


}

// 停止线程
void TimeDialog::on_pushButton_2_clicked()
{
    file MyFile;
    QString File_s=ui->textEdit_s->toPlainText();
    QString File_min=ui->textEdit_min->toPlainText();

    QProgressBar *someTime=new QProgressBar(this);

    someTime->setRange(0,100);
    someTime->show();
    someTime->setValue(20);


    if (m_thread && m_thread->isRunning()) {
        //someTime->setValue(50);
        m_thread->requestInterruption();
        m_thread->quit();
        m_thread->wait();
        ui->textEdit_min->clear();
        ui->textEdit_s->clear();
    }


    MyFile.save(File_s,File_min);

    someTime->setValue(100);
    someTime->hide();

    delete someTime;
    someTime=nullptr;
    this->close();

}
