/*!
 *@file QtAudioDevices.h
 *@brief 获取音频设备信息
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>

namespace Ui {
class QtAudioDevices;
}

class QtAudioDevices : public QDialog
{
    Q_OBJECT

public:
    explicit QtAudioDevices(QWidget *parent = 0);
    ~QtAudioDevices();

private:
    Ui::QtAudioDevices *ui;
};
