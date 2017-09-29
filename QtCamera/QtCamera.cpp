/*!
 *@file QtCamera.cpp
 *@brief 操作摄像头
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtCamera.h"
#include "ui_QtCamera.h"

QtCamera::QtCamera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtCamera)
{
    ui->setupUi(this);

    m_pCamera = new QCamera(this);
    m_pViewfinder = new QCameraViewfinder(this);
    m_pImageCapture = new QCameraImageCapture(m_pCamera);

    ui->hView->addWidget(m_pViewfinder);
    ui->lblImage->setScaledContents(true);

    m_pCamera->setViewfinder(m_pViewfinder);
    m_pCamera->start();

    connect(m_pImageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));

    connect(ui->pushButtonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(ui->pushButtonSave, SIGNAL(clicked()), this, SLOT(saveImage()));
    connect(ui->pushButtonQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

QtCamera::~QtCamera()
{
    delete ui;
}

void QtCamera::captureImage()
{
    m_pImageCapture->capture();
}

void QtCamera::displayImage(int, QImage image)
{
    ui->lblImage->setPixmap(QPixmap::fromImage(image));
}

void QtCamera::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(
                this, QStringLiteral("保存到文件"), QDir::homePath(),
                QStringLiteral("jpeg文件(*.jpg)"));
    if (fileName.isEmpty()){return;}
    const QPixmap* pixmap = ui->lblImage->pixmap();
    if (pixmap) {pixmap->save(fileName);}
}
