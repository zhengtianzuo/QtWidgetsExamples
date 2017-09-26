/*!
 *@file QtAnimatedTextEdit.h
 *@brief 动画文本输入框
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#pragma once
#include <QTextEdit>
#include <QWidget>
#include <QMovie>
#include <QPushButton>
#include <QVBoxLayout>

class AnimatedTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    AnimatedTextEdit(QWidget * p = 0);
    ~AnimatedTextEdit();
    void addAnimation(const QUrl& url, const QString& fileName);

private slots:
    void subAnimate(int);

private:
    QList<QUrl> m_lstUrls;
    QHash<QMovie*, QUrl> m_hasUrls;
};

class Window : public QWidget
{
    Q_OBJECT
public:
    Window(QWidget *p = 0);

private:
    QPushButton *m_btnAdd;
    AnimatedTextEdit *m_editAnimated;

public slots:
    void btnAddClicked();
};
