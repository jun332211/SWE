#pragma execution_character_set("utf-8")

#ifndef HELMETTAB_H
#define HELMETTAB_H

#include <QCheckBox>
#include <QWidget>
#include <QtCore>

#include "gameconfig.h"
#include "gamedata.h"
#include "listtab.h"

#include "ui_helmettabform.h"

class HelmetTab : public ListTab, private Ui::HelmetTabForm {
    Q_OBJECT

public:
    explicit HelmetTab(SaveManager* mgr, QWidget* parent = 0, int sectionId = -1);
    ~HelmetTab();

private:
    Ui::HelmetTabForm* form;
};

#endif // HELMETTAB_H
