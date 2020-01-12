#include "PlayerData.h"

#include <QFile>
#include <QJsonDocument>
#include <QDebug>

PlayerData::PlayerData(QObject *parent) : QObject(parent) {}

void PlayerData::toJson(QJsonObject &json)
{
    json["Coins"] = coins;
    json["Clicks"] = clicks;
}

void PlayerData::fromJson(const QJsonObject &json)
{
    if (json.contains("Coins")) coins = json["Coins"].toDouble();
    if (json.contains("Clicks")) clicks = json["Clicks"].toInt();
}

double PlayerData::getCoins() const { return coins; }

void PlayerData::setCoins(double value) { coins = value; }

long PlayerData::getClicks() const { return clicks; }

void PlayerData::setClicks(int value) { clicks = value; }

void PlayerData::save(const QString &filename)
{
    QJsonObject rootObject;

    toJson(rootObject);

    QJsonDocument doc;
    doc.setObject(rootObject);

    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.flush();
    file.close();
    qInfo() << "Konfiguration in Datei gespeichert " << filename;
}

bool PlayerData::load(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject rootObject = doc.object();

    fromJson(rootObject);

    return true;
}

QList< AbilityTreeData * > PlayerData::getPlayerAbilitysList() const { return playerAbilitysList; }

void PlayerData::setPlayerAbilitysList(const QList< AbilityTreeData * > &value) { playerAbilitysList = value; }

void PlayerData::addCoins(double coins)
{
    this->coins += coins;
    coinsAdded();
}
