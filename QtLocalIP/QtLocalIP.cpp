/*!
 *@file QtLocalIP.cpp
 *@brief 获取本地IP
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtLocalIP.h"
#include "ui_QtLocalIP.h"
#include <QHostAddress>
#include <QNetworkInterface>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    getLocalIP();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::getLocalIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list)
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            if (address.toString().contains("127.0."))
            {
                continue;
            }
            else
            {
                ui->listWidget->addItem(address.toString());
            }
        }
    }
}
