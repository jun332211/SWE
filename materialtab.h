#pragma execution_character_set("utf-8")

#ifndef MATERIALTAB_H
#define MATERIALTAB_H

#include <QCheckBox>
#include <QWidget>
#include <QtCore>

#include "gameconfig.h"
#include "gamedata.h"
#include "listtab.h"

#include "ui_materialtabform.h"

class MaterialTab : public ListTab, private Ui::MaterialTabForm {
    Q_OBJECT

public:
    explicit MaterialTab(SaveManager* mgr, QWidget* parent = 0, int sectionId = -1);
    ~MaterialTab();

private:
    Ui::MaterialTabForm* form;
};

#endif // MATERIALTAB_H
