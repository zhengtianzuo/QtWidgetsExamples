#include "QtGrayImage.h"
#include "ui_QtGrayImage.h"
#include <QDebug>>

QtGrayImage::QtGrayImage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtGrayImage)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slotGrayImage()));
}

QtGrayImage::~QtGrayImage()
{
    delete ui;
}

void QtGrayImage::slotGrayImage()
{
    QImage srcImage(":/1.png");
    grayImage(srcImage);
    ui->label2->setPixmap(QPixmap::fromImage(srcImage));
}

void QtGrayImage::grayImage(QImage& srcImage)
{
    for (int i = 0; i < srcImage.width(); i++)
    {
        for (int j= 0; j < srcImage.height(); j++)
        {
            QRgb color = srcImage.pixel(i, j);
            int gray = qGray(color);
            srcImage.setPixel(i, j, qRgba(gray, gray, gray, qAlpha(color)));
        }
    }
}
