#ifndef COINANIMATIONWIDGET_H
#define COINANIMATIONWIDGET_H

#include <QObject>
#include <QWidget>

class CoinAnimationWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit CoinAnimationWidget(double coinAdd, const QPoint &pos, QWidget *parent = nullptr);

  private:
  signals:

  public slots:
};

#endif  // COINANIMATIONWIDGET_H
