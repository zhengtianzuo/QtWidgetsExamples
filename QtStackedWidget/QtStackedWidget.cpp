/*!
 *@file QtStackedWidget.cpp
 *@brief Qt堆栈窗体
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtStackedWidget.h"
#include "ui_QtStackedWidget.h"

QtStackedWidget::QtStackedWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtStackedWidget)
{
    ui->setupUi(this);
    connect(ui->pushButtonPage1, &QPushButton::clicked, this, &QtStackedWidget::setCurrentIndex);
    connect(ui->pushButtonPage2, &QPushButton::clicked, this, &QtStackedWidget::setCurrentIndex);
    ui->stackedWidget->setCurrentIndex(0);
    m_lpPropertyAni = new Cls_PropertyAni(this);
}

QtStackedWidget::~QtStackedWidget()
{
    delete m_lpPropertyAni;
    m_lpPropertyAni = nullptr;
    delete ui;
}

void QtStackedWidget::setCurrentIndex()
{
    QPushButton *btn = reinterpret_cast<QPushButton *>(sender());
    if (btn == ui->pushButtonPage1 && ui->stackedWidget->currentIndex() != 0)
    {
        m_lpPropertyAni->Init(ui->stackedWidget, true);
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if (btn == ui->pushButtonPage2 && ui->stackedWidget->currentIndex() != 1)
    {
        m_lpPropertyAni->Init(ui->stackedWidget, false);
        ui->stackedWidget->setCurrentIndex(1);
    }
}
