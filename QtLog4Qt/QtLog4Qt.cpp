/*!
 *@file QtLog4Qt.cpp
 *@brief Log4Qt写日志
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtLog4Qt.h"
#include "ui_QtLog4Qt.h"

QtLog4Qt::QtLog4Qt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtLog4Qt)
{
    ui->setupUi(this);

    QString strInfo = QStringLiteral("qDebug Qt 中文显示!");
    qDebug(strInfo.toStdString().c_str());
    strInfo = QStringLiteral("qWarning Qt 中文显示!");
    qWarning(strInfo.toStdString().c_str());
    strInfo = QStringLiteral("qCritical Qt 中文显示!");
    qCritical(strInfo.toStdString().c_str());
}

QtLog4Qt::~QtLog4Qt()
{
    delete ui;
}
