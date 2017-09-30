/*!
 *@file main.cpp
 *@brief 程序主文件
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtLog4Qt.h"
#include <QApplication>
#include "logmanager.h"
#include "propertyconfigurator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Log4Qt::PropertyConfigurator::configure("QtLog4Qt.conf");
    Log4Qt::LogManager::setHandleQtMessages(true);

    QtLog4Qt w;
    w.show();

    return a.exec();
}
