#include "file.h"
#include<QFile>
#include<QDebug>
#include<QString>
#include<iostream>

file::file(QWidget *parent)
    : QWidget{parent}
{}

void file::save(QString time_s, QString time_min)
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/noteDayFile.txt";
    QFile noteDayFile(filePath);

    if (!noteDayFile.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append)) {
        qDebug() << "Error opening file at:" << filePath << "Reason:" << noteDayFile.errorString();
        return;
    }

    QTextStream out(&noteDayFile);
    out << "分：" << time_min << "\t" << "秒：" << time_s;
    noteDayFile.close();

    qDebug() << "File written successfully to:" << filePath;
}
