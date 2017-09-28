/*!
 *@file QtAnimation.cpp
 *@brief 动画控制效果
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtAnimation.h"
#include "ui_QtAnimation.h"
#include <QPropertyAnimation>
#include <QPushButton>
#include <QStateMachine>
#include <QFont>
#include <QSignalTransition>

QtAnimation::QtAnimation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtAnimation)
{
    ui->setupUi(this);

    QPushButton *pButton = ui->pushButton;

    //创建状态机
    QStateMachine *pStateMachine = new QStateMachine(this);

    //设置起始状态
    QState *pStartState = new QState(pStateMachine);
    //绑定属性
    pStartState->assignProperty(pButton, "geometry",
            QRect(10,(this->height()-pButton->height())/2,pButton->width(),pButton->height()));
    //设置为起始状态
    pStateMachine->setInitialState(pStartState);

    //设置结束状态
    QState *pEndState = new QState(pStateMachine);
    //绑定属性
    pEndState->assignProperty(pButton, "geometry",
            QRect(this->width()-pButton->width()*2-10,
            (this->height()-pButton->height()*2)/2,
            pButton->width()*2,pButton->height()*2));

    //设置动画效果
    QPropertyAnimation *pPropertyAnimation = new QPropertyAnimation(pButton, "geometry");
    pPropertyAnimation->setDuration(2000);
    pPropertyAnimation->setEasingCurve(QEasingCurve::OutBounce);

    //绑定动画信号槽
    QSignalTransition *pTransitionStart2End = pStartState->addTransition(pButton, SIGNAL(clicked()), pEndState);
    pTransitionStart2End->addAnimation(pPropertyAnimation);

    QSignalTransition *pTransitionEnd2Start = pEndState->addTransition(pButton, SIGNAL(clicked()), pStartState);
    pTransitionEnd2Start->addAnimation(pPropertyAnimation);

    //开启状态机
    pStateMachine->start();
}

QtAnimation::~QtAnimation()
{
    delete ui;
}
