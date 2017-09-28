/*!
 *@file QtAudioDevices.cpp
 *@brief 获取音频设备信息
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtAudioDevices.h"
#include "ui_QtAudioDevices.h"
#include <QAudioDeviceInfo>

QtAudioDevices::QtAudioDevices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtAudioDevices)
{
    ui->setupUi(this);

	//获取输入音频设备名称
    QVector<QString> aDeviceListI;
    QList<QAudioDeviceInfo> audioDeviceListI = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    foreach (QAudioDeviceInfo devInfo, audioDeviceListI)
    {
        QString strName = devInfo.deviceName();
        if (devInfo.isNull()) continue;
        if (strName[0] == 65533) continue;
        bool bFound = false;
        foreach (QString dev, aDeviceListI) {
            if (strName == dev){
                bFound = true;
            }
        }
        if (bFound == true) continue;
        aDeviceListI.push_back(strName);
        ui->comboBoxInput->addItem(strName);
    }

	//获取输出音频设备名称
    QVector<QString> aDeviceListO;
    QList<QAudioDeviceInfo> audioDeviceListO = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
    foreach (QAudioDeviceInfo devInfo, audioDeviceListO)
    {
        QString strName = devInfo.deviceName();
        if (devInfo.isNull()) continue;
        if (strName[0] == 65533) continue;
        bool bFound = false;
        foreach (QString dev, aDeviceListO) {
            if (strName == dev){
                bFound = true;
            }
        }
        if (bFound == true) continue;
        aDeviceListO.push_back(strName);
        ui->comboBoxOutput->addItem(strName);
    }
}

QtAudioDevices::~QtAudioDevices()
{
    delete ui;
}
