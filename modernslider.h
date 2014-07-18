#ifndef MODERNSLIDER_H
#define MODERNSLIDER_H

#include <QAbstractSlider>
#include <QSlider>

class modernSlider : public QSlider
{
    Q_OBJECT
public:
    explicit modernSlider(QWidget *parent = 0);

    void sliderChange(SliderChange change);

signals:
    void sliderChangeWithName(QString name, int value);

public slots:

};

#endif // MODERNSLIDER_H
