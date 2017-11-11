/*!
 *@file QtFontAwesome.cpp
 *@brief Qt使用FontAwesome图标字体库
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>

namespace Ui {
class QtFontAwesome;
}

class QtFontAwesome : public QDialog
{
    Q_OBJECT

public:
    explicit QtFontAwesome(QWidget *parent = 0);
    ~QtFontAwesome();

private:
    Ui::QtFontAwesome *ui;
};
