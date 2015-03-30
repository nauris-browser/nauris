#include "browsertab.h"
#include "ui_browsertab.h"

BrowserTab::BrowserTab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowserTab)
{
    ui->setupUi(this);
    QObject::connect(ui->webView, &QWebView::urlChanged,
                     this, &BrowserTab::updateUI);
    QObject::connect(ui->webView, &QWebView::titleChanged,
                     this, &BrowserTab::titleChanged);
}

BrowserTab::~BrowserTab()
{
    delete ui;
}

void BrowserTab::updateUI() {
    ui->urlEdit->setText(ui->webView->url().toString());

    ui->backButton->setEnabled(ui->webView->history()->canGoBack());
    ui->forwardButton->setEnabled(ui->webView->history()->canGoForward());
}

void BrowserTab::on_backButton_clicked()
{
    ui->webView->back();
}

void BrowserTab::on_forwardButton_clicked()
{
    ui->webView->forward();
}

void BrowserTab::on_refreshButton_clicked()
{
    ui->webView->reload();
}

void BrowserTab::on_goButton_clicked()
{
    //trim submitted text
    QString text = ui->urlEdit->text().trimmed();

    //create QUrl from text, add http protocol if not specified
    QString textWithProtocol;
    if (!(text.startsWith("http://") || text.startsWith("https://"))){
        textWithProtocol = "http://" + text;
    } else {
        textWithProtocol = text;
    }
    QUrl url = QUrl(textWithProtocol);

    //check if url has a valid host
    QHostInfo info = QHostInfo::fromName(url.host(QUrl::EncodeUnicode));
    std::cout<<info.error()<<std::endl;

    if (info.error() != 0) {
        //if host is invalid, use text as search term instead of URL
        url = QUrl("http://www.google.com/search?q=" + text);
    }
    std::cout<<url.toDisplayString().toStdString()<<std::endl;
    ui->webView->load(url);
}

void BrowserTab::on_urlEdit_returnPressed()
{
    on_goButton_clicked();
}

QString BrowserTab::getPageTitle()
{
    return ui->webView->title();
}

QIcon BrowserTab::getPageIcon()
{
    return ui->webView->icon();
}
