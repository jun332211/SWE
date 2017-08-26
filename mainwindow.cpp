#pragma execution_character_set("utf-8")

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIcon>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mgr(new SaveManager)
    , manualEdit(new ManualEditDialog(this, mgr))
    , cheatEdit(new CheatCodeDialog(this, mgr))
{
    QIcon icon(":/appInfo/small_icon.png");
    ui->setupUi(this);
    this->setWindowIcon(icon);
    ui->version_label->setText(QString(VERSION_STRING));
    connect(ui->actionVersion_information, SIGNAL(triggered()), SLOT(showVersionDialog()));
    connect(ui->actionOpen, SIGNAL(triggered()), SLOT(openFile()));
    connect(ui->actionSave, SIGNAL(triggered()), SLOT(saveFile()));
    connect(ui->actionOpenDecrypted, SIGNAL(triggered()), SLOT(openDecryptedFile()));
    connect(ui->actionSaveDecrypted, SIGNAL(triggered()), SLOT(saveDecryptedFile()));
    connect(ui->actionManual_Edit, SIGNAL(triggered(bool)), SLOT(showHexEditor()));
    connect(ui->actionCheatCode_Edit, SIGNAL(triggered(bool)), SLOT(showCheatEditor()));

    this->setAcceptDrops(true);

    this->manualEdit->setTreeWidget(this->mgr->getTw());

    // common
    ItemTab* it = new ItemTab(this->mgr, this, 0x20);
    WeaponTab* wt = new WeaponTab(this->mgr, this, 0x22);
    ImportantTab* imt = new ImportantTab(this->mgr, this, 0x26);
    HelmetTab* ht = new HelmetTab(this->mgr, this, 0x23);
    ArmorTab* at = new ArmorTab(this->mgr, this, 0x24);
    AccessoryTab* ast = new AccessoryTab(this->mgr, this, 0x25);
    MaterialTab* mt = new MaterialTab(this->mgr, this, 0x21);
    Section6Tab* s6t = new Section6Tab(this->mgr, this, 0x06);

    this->ui->tabWidget->addTab(it, tr("ITEM"));
    this->ui->tabWidget->addTab(wt, tr("WEAPON"));
    this->ui->tabWidget->addTab(ht, tr("HELMET"));
    this->ui->tabWidget->addTab(at, tr("ARMOR"));
    this->ui->tabWidget->addTab(ast, tr("ACCESSORY"));
    this->ui->tabWidget->addTab(mt, tr("MATERIAL"));
    this->ui->tabWidget->addTab(imt, tr("IMPORTANT"));
    this->ui->tabWidget->addTab(s6t, tr("INFO"));

    this->sectionTabs.append(it);
    this->sectionTabs.append(wt);
    this->sectionTabs.append(ht);
    this->sectionTabs.append(at);
    this->sectionTabs.append(ast);
    this->sectionTabs.append(mt);
    this->sectionTabs.append(imt);
    this->sectionTabs.append(s6t);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mgr;
}

Error::ErrorCode MainWindow::openFileWithError(const QString& file, bool encrypted)
{
    if (file.isEmpty()) {
        return Error::IO_ERROR;
    }
    Error::ErrorCode status;

    if (encrypted) {
        status = this->mgr->loadFile(file);
    } else {
        status = this->mgr->loadDecryptedFile(file);
    }
    if (this->mgr->loaded()) {
        ui->actionSave->setEnabled(true);
        ui->actionSaveDecrypted->setEnabled(true);
        ui->actionManual_Edit->setEnabled(true);
        ui->actionCheatCode_Edit->setEnabled(true);
        this->updateTabs();
    }
    if (status == Error::SUCCESS) {
        this->setWindowTitle(this->mgr->getFilepath() + " - SWE");
    }
    return status;
}

void MainWindow::openFileWithPath(const QString& file, bool encrypted)
{
    Error::ErrorCode status;
    if ((status = openFileWithError(file, encrypted)) != Error::SUCCESS) {
        QMessageBox::critical(this, tr("ERROR"), QString(tr("ERROR (%1)")).arg(status));
    }
}

void MainWindow::saveFileWithPath(const QString& file, bool encrypted)
{
    if (file.isEmpty()) {
        return;
    }
    Error::ErrorCode status;
    if (encrypted) {
        status = this->mgr->writeFile(file);
    } else {
        status = this->mgr->writeDecryptedFile(file);
    }
    if (status != Error::SUCCESS) {
        QMessageBox::critical(this, tr("ERROR"), QString(tr("ERROR (%1)")).arg(status));
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent* e)
{
    e->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent* e)
{
    Error::ErrorCode s1, s2;
    if (e->mimeData()->hasUrls()) {
        QString path = e->mimeData()->urls().first().toLocalFile();
        if (path.endsWith(".ywd")) {
            this->openFileWithPath(path, false);
        } else {
            if ((s1 = this->openFileWithError(path, true)) != Error::SUCCESS
                && (s2 = this->openFileWithError(path, false)) != Error::SUCCESS) {
                /* 暗号化済み・復号済みとみなしてもともに失敗した */
                QMessageBox::critical(this, tr("ERROR"), QString(tr("ERROR (%1-%2)")).arg(s1).arg(s2));
                return;
            }
        }
    }
}

void MainWindow::showVersionDialog()
{
    Version_Dialog* dlg;
    dlg = new Version_Dialog(this);
    dlg->exec();
}

void MainWindow::openFile(bool encrypted)
{
    QString file;
    QString filter;

    if (encrypted) {
        filter = QString(tr("SNACK_WORLD_TREJARERS_SAVEDATA (*.sw)"));
    } else {
        filter = QString(tr("SNACK_WORLD_TREJARERS_DECRYPTED_SAVEDATA (*.swd *.sw)"));
    }
    file = QFileDialog::getOpenFileName(this, tr("SELECT_FILE_TO_OPEN"),
        this->mgr->getFilepath(), filter);
    if (file.isEmpty()) {
        return;
    }
    openFileWithPath(file, encrypted);
}

void MainWindow::saveFile(bool encrypted)
{
    QString file;
    QString filter;

    if (this->mgr->loaded()) {
        if (encrypted) {
            filter = QString(tr("SNACK_WORLD_TREJARERS_SAVEDATA (*.sw)"));
        } else {
            filter = QString(tr("SNACK_WORLD_TREJARERS_DECRYPTED_SAVEDATA (*.swd *.sw)"));
        }
        file = QFileDialog::getSaveFileName(this, tr("INPUT_FILENAME"),
            this->mgr->getFilepath(), filter);

        if (file.isEmpty()) {
            return;
        }
        saveFileWithPath(file, encrypted);
    }
}

void MainWindow::openDecryptedFile()
{
    this->openFile(false);
}

void MainWindow::saveDecryptedFile()
{
    this->saveFile(false);
}

void MainWindow::showHexEditor()
{
    this->setAcceptDrops(false);
    int st = this->manualEdit->exec();
    if (st == QDialog::Accepted) {
        this->updateTabs();
    }
    this->setAcceptDrops(true);
}

void MainWindow::showCheatEditor()
{
    this->setAcceptDrops(false);
    this->cheatEdit->exec();
    if (this->cheatEdit->getIsDirty()) {
        this->updateTabs();
    }
    this->setAcceptDrops(true);
}

void MainWindow::updateTabs()
{
    for (QList<Tab*>::const_iterator it = this->sectionTabs.constBegin();
         it != this->sectionTabs.constEnd();
         ++it) {
        (*it)->update();
    }
}
