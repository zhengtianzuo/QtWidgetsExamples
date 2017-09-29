/*!
 *@file QtCamera.h
 *@brief 操作摄像头
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
#include <QDir>

namespace Ui {
    class QtCamera;
}

class QtCamera : public QDialog
{
    Q_OBJECT

public:
    explicit QtCamera(QWidget *parent = 0);
    ~QtCamera();

private slots:
    void captureImage();
    void displayImage(int, QImage);
    void saveImage();

private:
    Ui::QtCamera *ui;
    QCamera *m_pCamera;
    QCameraViewfinder *m_pViewfinder;
    QCameraImageCapture *m_pImageCapture;
};
