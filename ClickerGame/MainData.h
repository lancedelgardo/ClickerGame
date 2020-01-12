#ifndef MAINDATA_H
#define MAINDATA_H

#include "AbilityTreeData.h"
#include "PlayerData.h"

class MainData
{
  public:
    MainData(PlayerData *player);

    void saveAbilitys(const QString &filename);

    double getClickValue() const;

    void calcClickValue();

    QList< AbilityTreeData * > getAllAbilitysList() const;

    void buy(AbilityTreeData *abs);

    double getPlayerCoins();

  private:
    void createAbilitys();
    bool loadAbilitys(const QString &filename);
    void toJsonAbilitys(QJsonObject &json);
    void fromJsonAbilitys(const QJsonObject &json);

    QList< AbilityTreeData * > allAbilitysList;

    PlayerData *player = Q_NULLPTR;

    double clickValue = 0.0;
};

#endif  // MAINDATA_H
