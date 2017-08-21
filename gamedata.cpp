#pragma execution_character_set("utf-8")

#include "gamedata.h"

#include <QtCore>

GameData::GameData()
{
    this->availableData << "armor"
                        << "consume"
                        << "skill"
                        << "hackslash_technic"
                        << "important"
                        << "material"
                        << "weapon"
                        << "using";
    foreach (QString s, this->availableData) {
        QFile f(QString(":/data/data/%1.xml").arg(s));
        QFile g(QString(":/data/data/%1_%2.xml").arg(s).arg(QLocale().name()));
        QFile* file = &g;
        if (!g.exists()) {
            file = &f;
        }
        if (file->open(QIODevice::ReadOnly)) {
            QXmlStreamReader r;
            r.setDevice(&*file);
            while (!r.atEnd()) {
                r.readNext();
                if (r.isStartElement()) {
                    if (r.name().toString() == "item") {
                        QHash<QString, QString> item;
                        foreach (QXmlStreamAttribute attr, r.attributes()) {
                            if (attr.name() == "id") {
                                continue;
                            }
                            item[attr.name().toString()] = attr.value().toString();
                        }
                        this->data[s].append(qMakePair(r.attributes().value("id").toUInt(), item));
                    }
                }
            }
            f.close();
        }
    }
}

GameData::~GameData()
{
}

const QList<dataentry_t>& GameData::getData(const QString& s)
{
    return this->data[s];
}

const QJsonArray& GameData::getJSONData(const QString& s)
{
    return this->jsonData[s];
}
