#include "setting.h"
#include "ui_setting.h"
#include"widget.h"

setting::setting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::setting)
{
    ui->setupUi(this);
    ui->setting_setting->setIcon(QIcon(":/photos/setting.jpg"));
    ui->setting_setting->setIconSize(QSize(50,50));
    ui->setting_home->setIcon(QIcon(":/photos/home.jpg"));
    ui->setting_home->setIconSize(QSize(50,50));
}

setting::~setting()
{
    delete ui;
}

void setting::on_setting_home_clicked()
{

    this->close();
    Widget *myWindow=new Widget;
    myWindow->show();
    delete this;
}

