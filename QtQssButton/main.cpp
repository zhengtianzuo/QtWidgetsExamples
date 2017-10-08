/*!
 *@file main.cpp
 *@brief 程序主文件
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtQssButton.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile(":/QtQssButton.qss");
    if (!styleFile.open(QIODevice::ReadOnly))
    {
        return(-1);
    }
    a.setStyleSheet(styleFile.readAll());

    Dialog w;
    w.show();

    return a.exec();
}
