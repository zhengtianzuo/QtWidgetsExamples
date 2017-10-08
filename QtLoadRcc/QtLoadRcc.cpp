/*!
 *@file QtLoadRcc.cpp
 *@brief 动态加载RCC资源
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtLoadRcc.h"
#include "ui_QtLoadRcc.h"
#include <QResource>
#include <QMovie>

QtLoadRcc::QtLoadRcc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtLoadRcc),
    m_rccIsLoad(false)
{
    ui->setupUi(this);
    connect(ui->pushButtonLoad, SIGNAL(clicked()), this, SLOT(loadRcc()));
    connect(ui->pushButtonShow, SIGNAL(clicked()), this, SLOT(showPic()));
    connect(ui->pushButtonFree, SIGNAL(clicked()), this, SLOT(freeRcc()));
    setButtonEnabled();
}

QtLoadRcc::~QtLoadRcc()
{
    delete ui;
}

void QtLoadRcc::loadRcc()
{
    QResource::registerResource("QtLoadRcc.rcc");
    m_rccIsLoad = true;
    setButtonEnabled();
}

void QtLoadRcc::showPic()
{
    QPixmap image(":/Face.png");
    ui->label->setPixmap(image);
}

void QtLoadRcc::freeRcc()
{
    ui->label->setPixmap(QPixmap());
    QResource::unregisterResource("QtLoadRcc.rcc");
    m_rccIsLoad = false;
    setButtonEnabled();
}

void QtLoadRcc::setButtonEnabled()
{
    ui->pushButtonLoad->setEnabled(!m_rccIsLoad);
    ui->pushButtonShow->setEnabled(m_rccIsLoad);
    ui->pushButtonFree->setEnabled(m_rccIsLoad);
}
