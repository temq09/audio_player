#include "modernslider.h"

modernSlider::modernSlider(QWidget *parent) :
    QSlider(parent)
{
}

void modernSlider::sliderChange(SliderChange change)
{
    QString name = this->objectName();
    emit sliderChangeWithName(name,this->value());
}
