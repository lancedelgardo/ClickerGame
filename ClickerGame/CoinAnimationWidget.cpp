#include "CoinAnimationWidget.h"

#include <QLabel>
#include <QHBoxLayout>

CoinAnimationWidget::CoinAnimationWidget(double coinAdd, const QPoint &pos, QWidget *parent) : QWidget(parent)
{
    QString labelText = "+";
    labelText += QString::number(coinAdd);
    QLabel *label = new QLabel(labelText);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(label);

    //    setStyleSheet("Background-color: green;");
    setContentsMargins(0, 0, 0, 0);

    setGeometry(pos.x() - 12, pos.y() - 28, 50, 30);
}
