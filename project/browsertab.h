#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QWebView>
#include <QWebHistory>
#include <QHostInfo>
#include <QUrl>
#include <iostream>

namespace Ui {
class BrowserTab;
}

class BrowserTab : public QDialog
{
    Q_OBJECT

public:
    explicit BrowserTab(QWidget *parent = 0);
    ~BrowserTab();
    QString getPageTitle();
    QIcon getPageIcon();

signals:
    void titleChanged();

private slots:
    void on_backButton_clicked();

    void on_forwardButton_clicked();

    void on_refreshButton_clicked();

    void on_goButton_clicked();

    void on_urlEdit_returnPressed();

    void updateUI();

private:
    Ui::BrowserTab *ui;
};

#endif // DIALOG_H
