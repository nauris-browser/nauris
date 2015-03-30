#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCornerWidget(ui->addTabButton);
    on_addTabButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUI() {
    for (int i = 0; i<ui->tabWidget->count(); i++) {
        BrowserTab* b = (BrowserTab*)(ui->tabWidget->widget(i));
        ui->tabWidget->setTabText(i, b->getPageTitle().left(30));
        ui->tabWidget->setTabIcon(i, b->getPageIcon());
    }
}

void MainWindow::on_addTabButton_clicked()
{
    BrowserTab* tab = new BrowserTab();
    QObject::connect(tab, &BrowserTab::titleChanged,
                     this, &MainWindow::updateUI);
    ui->tabWidget->addTab(tab, "Loading");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    this->updateUI();
}

void MainWindow::on_tabWidget_tabCloseRequested(int i)
{
    BrowserTab* b = (BrowserTab*)(ui->tabWidget->widget(i));
    ui->tabWidget->removeTab(i);
    delete b;
    if (ui->tabWidget->count() == 0) {
        QApplication::quit();
    }
}
