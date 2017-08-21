#pragma execution_character_set("utf-8")

#ifndef SECTION6TAB_H
#define SECTION6TAB_H

#include "tab.h"
#include <QWidget>

namespace Ui {
class Section6Tab;
}

class Section6Tab : public Tab {
    Q_OBJECT

public:
    explicit Section6Tab(SaveManager* mgr, QWidget* parent = 0, int sectionId = -1);
    ~Section6Tab();
public slots:
    void update();
    void apply();

private:
    Ui::Section6Tab* ui;
};

#endif // SECTION6TAB_H
