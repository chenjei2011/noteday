#include "widget.h"
#include "ui_widget.h"
#include"timedialog.h"
#include"setting.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->setting->setIcon(QIcon(":/photos/setting.jpg"));
    ui->setting->setIconSize(QSize(50,50));
    ui->home->setIcon(QIcon(":/photos/home.jpg"));
    ui->home->setIconSize(QSize(50,50));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_setting_clicked()
{

}


void Widget::on_home_clicked()
{
    this->close();
    setting *set = new setting;
    set->show();


}


void Widget::on_open_clicked()
{
    this->hide();
    TimeDialog dlg(this);    // 栈上对象
    dlg.setModal(true);      // 模态
    dlg.exec();              // 阻塞
    this->show();
}

