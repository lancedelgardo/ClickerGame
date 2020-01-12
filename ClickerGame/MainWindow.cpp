#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "ShopDialog.h"

#include <QDir>
#include <QDebug>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QRect>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusBar->setVisible(false);

    playerData = new PlayerData(this);
    playerData->load("/home/dev/Documents/Dev/ClickerGame/save.json");
    connect(playerData, SIGNAL(coinsAdded()), this, SLOT(updateCoinsLabel()));

    updateCoinsLabel();

    mainData = new MainData(playerData);
    mainData->calcClickValue();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    mainData->saveAbilitys("/home/dev/Documents/Dev/ClickerGame/abs.json");
    playerData->save("/home/dev/Documents/Dev/ClickerGame/save.json");
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    double c = mainData->getClickValue();

    updateCoins(c);

    startAnimation(c, event->pos());
}

void MainWindow::updateCoins(double coins) { playerData->addCoins(coins); }

void MainWindow::startAnimation(double coinAdd, const QPoint &pos)
{
    if (coinAnimationWidget)
    {
        coinAnimationWidget->hide();
        disconnect(animation, SIGNAL(finished()), this, Q_NULLPTR);
        endAnimation();
    }
    coinAnimationWidget = new CoinAnimationWidget(coinAdd, pos, this);

    coinAnimationWidget->show();

    animation = new QPropertyAnimation(coinAnimationWidget, "geometry");
    animation->setDuration(1000);
    animation->setStartValue(coinAnimationWidget->geometry());
    QRect rect = coinAnimationWidget->geometry();
    rect.setTop(rect.top() - 200);
    animation->setEndValue(rect);
    animation->start();

    connect(animation, SIGNAL(finished()), this, SLOT(endAnimation()));
}

void MainWindow::endAnimation()
{
    if (coinAnimationWidget)
    {
        coinAnimationWidget->hide();
        disconnect(animation, SIGNAL(finished()), this, Q_NULLPTR);
    }
    animation = Q_NULLPTR;
    animation->deleteLater();
    coinAnimationWidget = Q_NULLPTR;
    coinAnimationWidget->deleteLater();
}

void MainWindow::on_shopButton_clicked()
{
    //
    ShopDialog *dia = new ShopDialog(mainData);
    dia->setGeometry(geometry());
    dia->exec();
    updateCoinsLabel();
}

void MainWindow::updateCoinsLabel() { ui->coinsLabel->setText("Coins: " + QString::number(playerData->getCoins())); }
