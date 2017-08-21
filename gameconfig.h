#pragma execution_character_set("utf-8")

#ifndef GAMECONFIG
#define GAMECONFIG

#include <QtCore>

class GameConfig {
public:
    static const int SECTIONS_CNT = 0x0C;
    static const quint8 defaultOrder[SECTIONS_CNT];
    static const quint8 sectionF2magic = 0x02;
    static const int MaterialCountMax = 196;
    static const int ItemCountMax = 128;
    static const int WeaponCountMax = 360;
    static const int ImportantCountMax = 48;
    static const int ArmorCountMax = 480;
};

#endif // GAMECONFIG
