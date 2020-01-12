#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "PlayerData.h"
#include "AbilityTreeData.h"
#include "CoinAnimationWidget.h"
#include "MainData.h"

#include <QMainWindow>
#include <QPropertyAnimation>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // QWidget interface
  protected:
    virtual void closeEvent(QCloseEvent *event) override;

    // QWidget interface
  protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

  private:
    Ui::MainWindow *ui;

    PlayerData *playerData = Q_NULLPTR;

    CoinAnimationWidget *coinAnimationWidget = Q_NULLPTR;
    QPropertyAnimation *animation = Q_NULLPTR;

    MainData *mainData = Q_NULLPTR;

    void updateCoins(double coins);

    void startAnimation(double coinAdd, const QPoint &pos);


  private slots:
    void endAnimation();

    void on_shopButton_clicked();

    void updateCoinsLabel();
};

#endif  // MAINWINDOW_H
