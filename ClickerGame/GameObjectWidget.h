#ifndef GAMEOBJECTWIDGET_H
#define GAMEOBJECTWIDGET_H

#include "AbilityTreeData.h"

#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>

class GameData;

class GameObjectWidget : public QWidget
{
    Q_OBJECT

  public:
    static GameObjectWidget *createWidget(AbilityTreeData *absData, QWidget *parent = Q_NULLPTR);

  private:
    AbilityTreeData *absData = Q_NULLPTR;

    QFormLayout *formlayout = Q_NULLPTR;

    QVBoxLayout *vbox = Q_NULLPTR;
    QWidget *headerWidget = Q_NULLPTR;
    QLabel *headerLabel = Q_NULLPTR;

  protected:
    GameObjectWidget(AbilityTreeData *absData, QWidget *parent = Q_NULLPTR);
    //    GameObjectWidget(BTData *btData, QWidget *parent = Q_NULLPTR);

    void formLayoutAddRow(const QString &rowName, QWidget *widget);
    void formLayoutAddRow(QWidget *label, QWidget *field);

    virtual void updateWidget();

    // QWidget interface
  protected:
    void paintEvent(QPaintEvent *);

  protected slots:
    void mousePressEvent(QMouseEvent *event);

  signals:
    void selectionChanged();
    void clicked(AbilityTreeData *);
};

#endif  // GAMEOBJECTWIDGET_H
