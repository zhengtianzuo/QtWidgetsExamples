/*!
 *@file QtMyPluginTest.cpp
 *@brief Qt调用插件
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtMyPluginTest.h"
#include "ui_QtMyPluginTest.h"

#include <QPluginLoader>
#include <QMessageBox>
#include "../QtMyPlugin/QtMyPluginInterface.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showPluginText()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showPluginText()
{
    QPluginLoader loader("QtMyPlugin.dll");
    if (!loader.load())
    {
        return;
    }
    CQtMyPluginInterface *plugin = qobject_cast<CQtMyPluginInterface *>(loader.instance());
    if (plugin)
    {
        QMessageBox::about(NULL, QStringLiteral("显示插件信息"), plugin->getString());
    }
}
