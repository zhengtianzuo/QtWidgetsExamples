/*!
 *@file QtDialog.h
 *@brief 自定义窗体系统按钮
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>

namespace Ui {
class QtDialog;
}

class QtDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QtDialog(QWidget *parent = 0);
    ~QtDialog();

public slots:
    void dialogClose();
    void dialogShowMaximized();
    void dialogShowMinimized();

private:
    Ui::QtDialog *ui;
};
