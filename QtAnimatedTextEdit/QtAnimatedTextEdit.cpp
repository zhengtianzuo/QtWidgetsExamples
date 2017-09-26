/*!
 *@file QtAnimatedTextEdit.cpp
 *@brief 动画文本输入框
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
#include "QtAnimatedTextEdit.h"

AnimatedTextEdit::AnimatedTextEdit(QWidget * e)
    : QTextEdit(e)
{

}

AnimatedTextEdit::~AnimatedTextEdit()
{
    QHash<QMovie*, QUrl>::const_iterator i;
    for (i = m_hasUrls.constBegin(); i != m_hasUrls.constEnd(); ++i)
    {
        delete i.key();
    }
}

void AnimatedTextEdit::addAnimation(
        const QUrl& url, const QString& fileName)
{
    //插入Html描述的图片
    insertHtml("<img src='" + url.toString() + "'/>");

    //判断是否是相同的图片
    if (m_lstUrls.contains(url))
    {
        return;
    }
    else
    {
        m_lstUrls.append(url);
    }

    //创建QMovie以显示Gif
    QMovie* movie = new QMovie(this);
    movie->setFileName(fileName);
    movie->setCacheMode(QMovie::CacheNone);

    m_hasUrls.insert(movie, url);

    //绑定帧切换信号槽
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(subAnimate(int)));
    movie->start();
}
void AnimatedTextEdit::subAnimate(int a)
{
    //使用QMovie中的当前帧替换掉富文本中的图片元素
    QMovie* movie = qobject_cast<QMovie*>(sender());
    document()->addResource(QTextDocument::ImageResource,
            m_hasUrls.value(movie), movie->currentPixmap());
    setLineWrapColumnOrWidth(lineWrapColumnOrWidth());
}
Window::Window(QWidget *p)
    :QWidget(p)
{
    this->setMinimumHeight(400);
    this->setMinimumWidth(400);\
    this->setWindowTitle(QStringLiteral("Qt富文本框插入Gif动画"));

    QVBoxLayout *layout = new QVBoxLayout(this);
    m_btnAdd = new QPushButton(QStringLiteral("添加一个Gif动画"));
    m_editAnimated = new AnimatedTextEdit();

    layout->addWidget(m_btnAdd);
    layout->addWidget(m_editAnimated);
    
    this->setLayout(layout);
    connect(m_btnAdd, SIGNAL(clicked()), this, SLOT(btnAddClicked()));
}

void Window::btnAddClicked()
{
    m_editAnimated->addAnimation(
        QUrl("yyy"), "QtAnimatedTextEdit.gif");
}
