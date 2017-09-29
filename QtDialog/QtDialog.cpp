/*!
 *@file QtDialog.cpp
 *@brief 自定义窗体系统按钮
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtDialog.h"
#include "ui_QtDialog.h"

QtDialog::QtDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->toolButtonClose,SIGNAL(clicked()),this,SLOT(dialogClose()));
    connect(ui->toolButtonMax,SIGNAL(clicked()),this,SLOT(dialogShowMaximized()));
    connect(ui->toolButtonMin,SIGNAL(clicked()),this,SLOT(dialogShowMinimized()));

    bool bMaximize = this->isMaximized();
    ui->toolButtonMax->setProperty("maximizeProperty", bMaximize ? "restore" : "maximize");
    ui->toolButtonMax->style()->unpolish(ui->toolButtonMax);
    ui->toolButtonMax->style()->polish(ui->toolButtonMax);
    ui->toolButtonMax->update();
}

QtDialog::~QtDialog()
{
    delete ui;
}

void QtDialog::dialogClose()
{
    close();
}

void QtDialog::dialogShowMaximized()
{
    bool bMaximize = this->isMaximized();
    if (bMaximize)
    {
        this->showNormal();
    }
    else
    {
        this->showMaximized();
    }
    bMaximize = this->isMaximized();
    ui->toolButtonMax->setProperty("maximizeProperty", bMaximize ? "restore" : "maximize");
    ui->toolButtonMax->style()->unpolish(ui->toolButtonMax);
    ui->toolButtonMax->style()->polish(ui->toolButtonMax);
    ui->toolButtonMax->update();
}

void QtDialog::dialogShowMinimized()
{
    this->showMinimized();
}
