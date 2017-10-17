/*!
 *@file QtStackedWidget.h
 *@brief Qt堆栈窗体
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QDialog>
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QStackedWidget>

typedef struct PropertyAni_Stu
{
    QLabel *lblGrab;
    QPropertyAnimation *pAniGrab;
    QPropertyAnimation *pAniCome;
    QParallelAnimationGroup *pGroup;

    PropertyAni_Stu(QWidget *pThis)
    {
        lblGrab = new QLabel(pThis);
        pAniGrab = new QPropertyAnimation();
        pAniCome = new QPropertyAnimation();
        pGroup = new QParallelAnimationGroup();
    }
    ~PropertyAni_Stu()
    {
        delete lblGrab;lblGrab = nullptr;
        delete pAniGrab;pAniGrab = nullptr;
        delete pAniCome;pAniCome = nullptr;
        delete pGroup;pGroup = nullptr;
    }
    void Init(QStackedWidget *pSW, bool bolLeft)
    {
        lblGrab->resize(pSW->size());
        lblGrab->setPixmap(pSW->grab());
        lblGrab->show();

        pAniGrab->setTargetObject(lblGrab);
        pAniGrab->setPropertyName("geometry");
        pAniGrab->setDuration(100);
        pAniGrab->setStartValue(pSW->geometry());
        pAniGrab->setEndValue(QRect(-pSW->width(), pSW->y(), pSW->width(), pSW->height()));

        pAniCome->setTargetObject(pSW);
        pAniCome->setPropertyName("geometry");
        pAniCome->setDuration(100);
        pAniCome->setStartValue(QRect(pSW->width(), pSW->y(), pSW->width(), pSW->height()));
        pAniCome->setEndValue(pSW->geometry());

        pGroup->addAnimation(pAniGrab);
        pGroup->addAnimation(pAniCome);
        pGroup->start();
    }
}Cls_PropertyAni,*Cls_lpPropertyAni;

namespace Ui {
    class QtStackedWidget;
}

class QtStackedWidget : public QDialog
{
    Q_OBJECT

public:
    explicit QtStackedWidget(QWidget *parent = 0);
    ~QtStackedWidget();

private:
    Ui::QtStackedWidget *ui;
    Cls_PropertyAni *m_lpPropertyAni;

private slots:
    void setCurrentIndex();
};
