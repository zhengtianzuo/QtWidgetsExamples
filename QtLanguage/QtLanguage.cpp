/*!
 *@file QtLanguage.cpp
 *@brief 语言切换
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtLanguage.h"
#include "ui_QtLanguage.h"
#include <QTranslator>
#include <QRadioButton>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
    connect(ui->radioButton,SIGNAL(toggled(bool)),this,SLOT(changeLanguage()));
    connect(ui->radioButton_2,SIGNAL(toggled(bool)),this,SLOT(changeLanguage()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::changeLanguage()
{
    QTranslator translator;
    QRadioButton* radio = qobject_cast<QRadioButton*>(sender());
    if(radio == ui->radioButton)
    {
        translator.load(":/en_US.qm");
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
    }
    else if(radio == ui->radioButton_2)
    {
        translator.load(":/zh_CN.qm");
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
    }
}
