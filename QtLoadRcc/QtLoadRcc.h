/*!
 *@file QtLoadRcc.h
 *@brief 动态加载RCC资源
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>

namespace Ui {
    class QtLoadRcc;
}

class QtLoadRcc : public QDialog
{
    Q_OBJECT

public:
    explicit QtLoadRcc(QWidget *parent = 0);
    ~QtLoadRcc();

private slots:
    void loadRcc();
    void showPic();
    void freeRcc();

private:
    Ui::QtLoadRcc *ui;
    bool m_rccIsLoad;

    void setButtonEnabled();
};
