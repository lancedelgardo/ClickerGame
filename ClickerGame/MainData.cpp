#include "MainData.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QDebug>

MainData::MainData(PlayerData *player)
{
    this->player = player;
    loadAbilitys("/home/dev/Documents/Dev/ClickerGame/abs.json");
}

void MainData::createAbilitys() {}

bool MainData::loadAbilitys(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject rootObject = doc.object();

    fromJsonAbilitys(rootObject);

    return true;
}

void MainData::saveAbilitys(const QString &filename)
{
    QJsonObject rootObject;

    toJsonAbilitys(rootObject);

    QJsonDocument doc;
    doc.setObject(rootObject);

    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.flush();
    file.close();
    qInfo() << "Konfiguration in Datei gespeichert " << filename;
}

void MainData::toJsonAbilitys(QJsonObject &json)
{
    QJsonArray array;
    foreach (auto abs, allAbilitysList)
    {
        QJsonObject abilitysObject;
        abs->toJson(abilitysObject);
        array.append(abilitysObject);
    }
    json["Abilitys"] = array;
}

void MainData::fromJsonAbilitys(const QJsonObject &json)
{
    if (!json.contains("Abilitys") || !json["Abilitys"].isArray()) return;

    auto array = json["Abilitys"].toArray();

    foreach (auto arrayItem, array)
    {
        if (!arrayItem.isObject()) continue;
        auto jsonAbs = arrayItem.toObject();

        AbilityTreeData *abilitysData = new AbilityTreeData();
        abilitysData->fromJson(jsonAbs);
        allAbilitysList.append(abilitysData);
    }
    calcClickValue();
}

QList< AbilityTreeData * > MainData::getAllAbilitysList() const { return allAbilitysList; }

void MainData::buy(AbilityTreeData *abs)
{
    if (abs->isUnlocked()) return;
    abs->setUnlocked(true);
    calcClickValue();

    player->setCoins(player->getCoins() - abs->getPrice());
}

double MainData::getPlayerCoins() { return player->getCoins(); }

double MainData::getClickValue() const { return clickValue; }

void MainData::calcClickValue()
{
    clickValue = 1.0;
    foreach (auto abs, allAbilitysList)
    {
        if (abs->isUnlocked()) clickValue += abs->getAbilityValue();
    }
}
