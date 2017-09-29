/*!
 *@file QtGrayImage.h
 *@brief 图片转灰度
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>

namespace Ui {
class QtGrayImage;
}

class QtGrayImage : public QDialog
{
    Q_OBJECT

public:
    explicit QtGrayImage(QWidget *parent = 0);
    ~QtGrayImage();

private slots:
    void slotGrayImage();

private:
    void grayImage(QImage& srcImage);

    Ui::QtGrayImage *ui;
};
