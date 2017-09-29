#ifndef QTGRAYIMAGE_H
#define QTGRAYIMAGE_H

#include <QDialog>

namespace Ui {
class QtGrayImage;
}

class QtGrayImage : public QDialog
{
    Q_OBJECT

public:
    explicit QtGrayImage(QWidget *parent = 0);
    ~QtGrayImage();

private slots:
    void slotGrayImage();

private:
    void grayImage(QImage& srcImage);

    Ui::QtGrayImage *ui;
};

#endif // QTGRAYIMAGE_H
