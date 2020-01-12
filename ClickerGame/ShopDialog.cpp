#include "ShopDialog.h"
#include "ui_ShopDialog.h"

#include <QDebug>

ShopDialog::ShopDialog(MainData *mainData, QWidget *parent) : QDialog(parent), ui(new Ui::ShopDialog)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = Qt::Window;
    flags = Qt::Tool;
    flags |= Qt::WindowStaysOnTopHint;
    flags |= Qt::FramelessWindowHint;
    setWindowFlags(flags);

    this->mainData = mainData;

    QWidget *w = ui->stackedWidget->widget(0);
    QWidget *w2 = ui->stackedWidget->widget(1);
    ui->stackedWidget->removeWidget(w);
    ui->stackedWidget->removeWidget(w2);

    shopMenu1 = new ShopMenu1(mainData);
    ui->stackedWidget->addWidget(shopMenu1);

    ui->coinsLabel->setText("Coins: " + QString::number(mainData->getPlayerCoins()));

    connect(shopMenu1, SIGNAL(buyed()), this, SLOT(onBuyed()));
}

ShopDialog::~ShopDialog() { delete ui; }

void ShopDialog::on_closeButton_clicked() { close(); }

void ShopDialog::onBuyed() { ui->coinsLabel->setText("Coins: " + QString::number(mainData->getPlayerCoins())); }

void ShopDialog::closeEvent(QCloseEvent *event) { Q_UNUSED(event) }
