/*!
 *@file QtMyPlugin.cpp
 *@brief 插件
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include <QtCore>
#include "QtMyPlugin.h"

QString CQtMyPlugin::getString()
{
    return QStringLiteral("插件中的字符串ABCDEFG");
}
