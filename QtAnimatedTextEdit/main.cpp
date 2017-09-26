/*!
 *@file main.cpp
 *@brief 程序主文件
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/

#include <QtGui>
#include <QApplication>
#include "QtAnimatedTextEdit.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}
