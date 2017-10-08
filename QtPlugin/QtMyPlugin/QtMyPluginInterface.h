/*!
 *@file QtMyPluginInterface.h
 *@brief 插件接口文件
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QtPlugin>

class CQtMyPluginInterface
{
public:
    virtual ~CQtMyPluginInterface() {}
    virtual QString getString() = 0;
};

Q_DECLARE_INTERFACE(CQtMyPluginInterface, "cn.camelsoft.CQtMyPluginInterface/1.0")
