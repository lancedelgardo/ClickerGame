#ifndef ABILITIETREEDATA_H
#define ABILITIETREEDATA_H

#include <QString>
#include <QJsonObject>

class AbilityTreeData
{
  public:
    AbilityTreeData();

    QString getAbilityName() const;
    void setAbilityName(const QString &value);

    double getAbilityValue() const;
    void setAbilityValue(double value);

    int getId() const;
    void setId(int value);

    void toJson(QJsonObject &json);
    void fromJson(const QJsonObject &json);

    bool isUnlocked() const;

    int getPrice() const;
    void setPrice(int value);

    void setUnlocked(bool value);

  private:
    QString abilityName;
    double abilityValue = 0.0;
    int id = 0;
    bool unlocked = false;
    int price = 0;
};

#endif  // ABILITIETREEDATA_H
