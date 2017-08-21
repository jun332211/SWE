#pragma execution_character_set("utf-8")

#ifndef ARMORTAB_H
#define ARMORTAB_H

#include <QCheckBox>
#include <QWidget>
#include <QtCore>

#include "gameconfig.h"
#include "gamedata.h"
#include "listtab.h"

#include "ui_armortabform.h"

class ArmorTab : public ListTab, private Ui::ArmorTabForm {
    Q_OBJECT

public:
    explicit ArmorTab(SaveManager* mgr, QWidget* parent = 0, int sectionId = -1);
    ~ArmorTab();

private:
    Ui::ArmorTabForm* form;
};

#endif // ARMORTAB_H
