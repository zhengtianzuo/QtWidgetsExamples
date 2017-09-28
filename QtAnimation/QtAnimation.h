/*!
 *@file QtAnimation.h
 *@brief 动画控制效果
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>

namespace Ui {
class QtAnimation;
}

class QtAnimation : public QDialog
{
    Q_OBJECT

public:
    explicit QtAnimation(QWidget *parent = 0);
    ~QtAnimation();

private:
    Ui::QtAnimation *ui;
};
