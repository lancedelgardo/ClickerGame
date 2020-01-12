#include "AbilityTreeData.h"

AbilityTreeData::AbilityTreeData() {}

QString AbilityTreeData::getAbilityName() const { return abilityName; }

void AbilityTreeData::setAbilityName(const QString &value) { abilityName = value; }

double AbilityTreeData::getAbilityValue() const { return abilityValue; }

void AbilityTreeData::setAbilityValue(double value) { abilityValue = value; }

int AbilityTreeData::getId() const { return id; }

void AbilityTreeData::setId(int value) { id = value; }

void AbilityTreeData::toJson(QJsonObject &json)
{
    json["ID"] = id;
    json["AbilityName"] = abilityName;
    json["AbilityValue"] = abilityValue;
    json["Unlocked"] = unlocked;
    json["Price"] = price;
}

void AbilityTreeData::fromJson(const QJsonObject &json)
{
    if (json.contains("ID")) id = json["ID"].toInt();
    if (json.contains("AbilityName")) abilityName = json["AbilityName"].toString();
    if (json.contains("AbilityValue")) abilityValue = json["AbilityValue"].toDouble();
    if (json.contains("Unlocked")) unlocked = json["Unlocked"].toBool();
    if (json.contains("Price")) price = json["Price"].toInt();
}

bool AbilityTreeData::isUnlocked() const { return unlocked; }

int AbilityTreeData::getPrice() const { return price; }

void AbilityTreeData::setPrice(int value) { price = value; }

void AbilityTreeData::setUnlocked(bool value)
{
    unlocked = value;
}
