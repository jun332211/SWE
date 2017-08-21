#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T09:45:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "SWE"
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    version_dialog.cpp \
    savemanager.cpp \
    xorshift.cpp \
    ywcipher.cpp \
    ccmcipher.cpp \
    crc32.cpp \
    error.cpp \
    tab.cpp \
    listtab.cpp \
    gamedata.cpp \
    gameconfig.cpp \
    manualeditdialog.cpp \
    QHexEdit/qhexedit.cpp \
    QHexEdit/qhexeditcomments.cpp \
    QHexEdit/qhexeditdata.cpp \
    QHexEdit/qhexeditdatadevice.cpp \
    QHexEdit/qhexeditdatareader.cpp \
    QHexEdit/qhexeditdatawriter.cpp \
    QHexEdit/qhexedithighlighter.cpp \
    QHexEdit/qhexeditprivate.cpp \
    QHexEdit/sparserangemap.cpp \
    itemtab.cpp \
    importanttab.cpp \
    section1tab.cpp \
    section.cpp \
    youkaichecklist.cpp \
    checklist.cpp \
    flagchecklist.cpp \
    trophychecklist.cpp \
    cheatcodedialog.cpp \
    cybercode/AddCode.cpp \
    cybercode/CyberCode.cpp \
    cybercode/CyberCodeParser.cpp \
    cybercode/LoopCode.cpp \
    cybercode/OffsetCode.cpp \
    cybercode/SearchCode.cpp \
    cybercode/SectionWriteCode.cpp \
    cybercode/WriteCode.cpp \
    cybercode/SectionOffsetCode.cpp \
    dataeditor/dataeditor.cpp \
    dataeditor/integereditor.cpp \
    dataeditor/biteditor.cpp \
    dataeditor/stringeditor.cpp \
    dataeditor/listeditor.cpp \
    dataeditor/hexintegereditor.cpp \
    weapontab.cpp \
    section6tab.cpp \
    armortab.cpp \
    materialtab.cpp

HEADERS  += mainwindow.h \
    version.h \
    version_dialog.h \
    savemanager.h \
    gameconfig.h \
    xorshift.h \
    ywcipher.h \
    ccmcipher.h \
    crc32.h \
    error.h \
    tab.h \
    listtab.h \
    gamedata.h \
    manualeditdialog.h \
    QHexEdit/qhexedit.h \
    QHexEdit/qhexeditcomments.h \
    QHexEdit/qhexeditdata.h \
    QHexEdit/qhexeditdatadevice.h \
    QHexEdit/qhexeditdatareader.h \
    QHexEdit/qhexeditdatawriter.h \
    QHexEdit/qhexedithighlighter.h \
    QHexEdit/qhexeditprivate.h \
    QHexEdit/sparserangemap.h \
    itemtab.h \
    importanttab.h \
    section1tab.h \
    section.h \
    youkaichecklist.h \
    checklist.h \
    flagchecklist.h \
    trophychecklist.h \
    cheatcodedialog.h \
    cybercode/AddCode.h \
    cybercode/CyberCode.h \
    cybercode/CyberCodeParser.h \
    cybercode/LoopCode.h \
    cybercode/OffsetCode.h \
    cybercode/SearchCode.h \
    cybercode/SectionWriteCode.h \
    cybercode/WriteCode.h \
    cybercode/SectionOffsetCode.h \
    dataeditor/dataeditor.h \
    dataeditor/integereditor.h \
    dataeditor/biteditor.h \
    dataeditor/stringeditor.h \
    dataeditor/listeditor.h \
    dataeditor/hexintegereditor.h \
    weapontab.h \
    section6tab.h \
    armortab.h \
    materialtab.h

FORMS    += mainwindow.ui \
    version_dialog.ui \
    manualeditdialog.ui \
    section1tab.ui \
    listtab.ui \
    itemtabform.ui \
    importanttabform.ui \
    cheatcodedialog.ui \
    weapontabform.ui \
    section6tab.ui \
    armortabform.ui \
    materialtabform.ui

TRANSLATIONS = $$PWD/translations/app_ja.ts \
$$PWD/translations/app_en.ts

macx {
APPBUNDLE = "SWE.app"
ICON = icon.icns
LIBS += -L$$PWD/../../local/lib -lcryptopp
INCLUDEPATH += $$PWD/../../local/include
QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas
QMAKE_TARGET_BUNDLE_PREFIX = jp.togenyan
}

win32:LIBS += -L$$PWD/../lib/ -lcryptlib

win32:INCLUDEPATH += $$PWD/../include
win32:DEPENDPATH += $$PWD/../include

RESOURCES += \
    resources.qrc
RC_FILE = app.rc
