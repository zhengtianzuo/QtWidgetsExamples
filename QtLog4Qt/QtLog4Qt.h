/*!
 *@file QtLog4Qt.h
 *@brief Log4Qt写日志
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>

namespace Ui {
    class QtLog4Qt;
}

class QtLog4Qt : public QDialog
{
    Q_OBJECT

public:
    explicit QtLog4Qt(QWidget *parent = 0);
    ~QtLog4Qt();

private:
    Ui::QtLog4Qt *ui;
};
