#include "ShopMenu1.h"

#include "GameObjectWidget.h"

#include <QScroller>
#include <QTimer>

ShopMenu1::ShopMenu1(MainData *mainData, QWidget *parent) : QWidget(parent)
{
    this->mainData = mainData;

    layout = new QHBoxLayout(this);

    shopScrollArea = new QScrollArea();
    shopScrollArea->setWidgetResizable(true);

    flowLayoutShop = new FlowLayout(shopScrollArea);

    flowLayoutShop->clear();
    foreach (auto abs, mainData->getAllAbilitysList())
    {
        auto w = GameObjectWidget::createWidget(abs, shopScrollArea);
        w->setVisible(true);
        flowLayoutShop->addWidget(w);
        connect(w, SIGNAL(clicked(AbilityTreeData *)), this, SLOT(onAbilityClicked(AbilityTreeData *)));
    }

    flowLayoutShop->update();

    QScroller::grabGesture(shopScrollArea, QScroller::TouchGesture);

    QTimer::singleShot(50, this, SLOT(onUpdateFlowLayoutShop()));

    layout->addWidget(shopScrollArea);
}

void ShopMenu1::onUpdateFlowLayoutShop() { flowLayoutShop->update(); }

void ShopMenu1::onAbilityClicked(AbilityTreeData *abs)
{
    if (abs->isUnlocked()) return;
    if (mainData->getPlayerCoins() < abs->getPrice()) return;

    mainData->buy(abs);
    buyed();
}
