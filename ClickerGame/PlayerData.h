#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include "AbilityTreeData.h"

#include <QObject>
#include <QJsonObject>

class PlayerData : public QObject
{
    Q_OBJECT
  public:
    explicit PlayerData(QObject *parent = nullptr);

    double getCoins() const;
    void setCoins(double value);

    long getClicks() const;
    void setClicks(int value);

    void save(const QString &filename);
    bool load(const QString &filename);

    QList< AbilityTreeData * > getPlayerAbilitysList() const;
    void setPlayerAbilitysList(const QList< AbilityTreeData * > &value);

    void addCoins(double coins);

  private:
    double coins = 0.0;
    int clicks = 0;
    QList< AbilityTreeData * > playerAbilitysList;

    void toJson(QJsonObject &json);
    void fromJson(const QJsonObject &json);

  signals:
    void coinsAdded();

  public slots:
};

#endif  // PLAYERDATA_H
