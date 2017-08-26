#pragma execution_character_set("utf-8")

#ifndef ACCESSORYTAB_H
#define ACCESSORYTAB_H

#include <QCheckBox>
#include <QWidget>
#include <QtCore>

#include "gameconfig.h"
#include "gamedata.h"
#include "listtab.h"

#include "ui_accessorytabform.h"

class AccessoryTab : public ListTab, private Ui::AccessoryTabForm {
    Q_OBJECT

public:
    explicit AccessoryTab(SaveManager* mgr, QWidget* parent = 0, int sectionId = -1);
    ~AccessoryTab();

private:
    Ui::AccessoryTabForm* form;
};

#endif // ACCESSORYTAB_H
