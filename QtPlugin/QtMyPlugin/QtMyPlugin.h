/*!
 *@file QtMyPlugin.h
 *@brief 插件
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QObject>
#include "QtMyPluginInterface.h"

class CQtMyPlugin : public QObject, public CQtMyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA ( IID "cn.camelsoft.CQtMyPluginInterface/1.0")

    Q_INTERFACES(CQtMyPluginInterface)
  
public:
    virtual QString getString();
};

