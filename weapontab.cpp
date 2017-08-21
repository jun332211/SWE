#pragma execution_character_set("utf-8")

#include "weapontab.h"

#include "dataeditor/integereditor.h"
#include "dataeditor/listeditor.h"

WeaponTab::WeaponTab(SaveManager* mgr, QWidget* parent, int sectionId)
    : ListTab(mgr, parent, sectionId)
    , form(new Ui::WeaponTabForm)
{
    QWidget* w = new QWidget(this);
    form->setupUi(w);
    ui->form->addWidget(w);

    this->setNum1Offset(0x1000);
    this->setItemsCount(GameConfig::WeaponCountMax);
    this->setItemSize(0x20);

    for (int i = 0; i < GameConfig::WeaponCountMax; ++i) {
        ui->listWidget->addItem(QString(""));
    }

    /* intert items into combobox */
    foreach (const dataentry_t& it, GameData::getInstance().getData("weapon")) {
        form->itemCB->addItem(it.second.value("name"), it.first);
    }
    foreach (const dataentry_t& it, GameData::getInstance().getData("using")) {
        form->itemCB->addItem(it.second.value("name"), it.first);
    }

    foreach (const dataentry_t& it, GameData::getInstance().getData("hackslash_technic")) {
        form->hstCB->addItem(it.second.value("name"), it.first);
        form->hst2CB->addItem(it.second.value("name"), it.first);
    }

    form->itemCB->setCurrentIndex(-1);

    /* skill combobox*/
    foreach (const dataentry_t& it, GameData::getInstance().getData("skill")) {
        form->skillCB->addItem(it.second.value("name"), it.first);
        form->skill2CB->addItem(it.second.value("name"), it.first);
    }

    /* editors */
    ListEditor* itemE = new ListEditor(this, form->itemLabel, form->itemCB, 0x04, 32);
    this->setPrimaryEditor(itemE);
    this->editors.append(new IntegerEditor(this, form->num1Label, form->num1SB, 0x00, 16, false));
    this->editors.append(new IntegerEditor(this, form->num2Label, form->num2SB, 0x02, 16, false));
    this->editors.append(itemE);
    this->editors.append(new ListEditor(this, form->skillLabel, form->skillCB, 0x0C, 32));
    this->editors.append(new ListEditor(this, form->skill2Label, form->skill2CB, 0x10, 32));
    this->editors.append(new ListEditor(this, form->hstLabel, form->hstCB, 0x18, 32));
    this->editors.append(new ListEditor(this, form->hst2Label, form->hst2CB, 0x1C, 32));
    this->editors.append(new IntegerEditor(this, form->countLabel, form->countSB, 0x8, 8, false));
    this->editors.append(new IntegerEditor(this, form->count2Label, form->count2SB, 0x9, 8, false));
}

WeaponTab::~WeaponTab()
{
    delete form;
}
