#pragma execution_character_set("utf-8")

#ifndef WEAPONTAB_H
#define WEAPONTAB_H

#include <QCheckBox>
#include <QWidget>
#include <QtCore>

#include "gameconfig.h"
#include "gamedata.h"
#include "listtab.h"

#include "ui_weapontabform.h"

class WeaponTab : public ListTab, private Ui::WeaponTabForm {
    Q_OBJECT

public:
    explicit WeaponTab(SaveManager* mgr, QWidget* parent = 0, int sectionId = -1);
    ~WeaponTab();

private:
    Ui::WeaponTabForm* form;
};

#endif // WEAPONTAB_H
