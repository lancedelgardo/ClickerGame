#ifndef SHOPMENU1_H
#define SHOPMENU1_H

#include "FlowLayout.h"
#include "MainData.h"

#include <QWidget>
#include <QScrollArea>
#include <QHBoxLayout>

class ShopMenu1 : public QWidget
{
    Q_OBJECT
  public:
    explicit ShopMenu1(MainData *mainData, QWidget *parent = nullptr);

  private:
    MainData *mainData = Q_NULLPTR;
    QScrollArea *shopScrollArea = Q_NULLPTR;
    FlowLayout *flowLayoutShop = Q_NULLPTR;
    QHBoxLayout *layout = Q_NULLPTR;

  private slots:
    void onUpdateFlowLayoutShop();
    void onAbilityClicked(AbilityTreeData *abs);

  signals:
    void buyed();

  public slots:
};

#endif  // SHOPMENU1_H
