/*!
 *@file QtFontAwesome.cpp
 *@brief Qt使用FontAwesome图标字体库
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtFontAwesome.h"
#include "ui_QtFontAwesome.h"
#include <QFontDatabase>
#include <QDebug>

QtFontAwesome::QtFontAwesome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtFontAwesome)
{
    ui->setupUi(this);

    // 添加字体文件
    int fontId = QFontDatabase::addApplicationFont(":/Font/fontawesome-webfont.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    qDebug() << "fontFamilies.size() " << fontFamilies.size();

    // 创建字体
    QFont font;
    font.setFamily(fontFamilies.at(0));
    font.setPointSize(20);

    // 设置字体及样式、大小
    ui->ZoomInLabel->setFont(font);
    ui->ZoomInLabel->setText(QChar(0xf00e));
    ui->ZoomInLabel->setStyleSheet("color: rgb(0, 160, 230);");

    font.setPointSize(30);
    ui->ZoomOutLabel->setFont(font);
    ui->ZoomOutLabel->setText(QChar(0xf004));
    ui->ZoomOutLabel->setStyleSheet("color: green;");
}

QtFontAwesome::~QtFontAwesome()
{
    delete ui;
}
