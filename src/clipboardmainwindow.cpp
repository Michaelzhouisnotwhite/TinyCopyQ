#include "clipboardmainwindow.h"
#include "data_structure.h"
#include "ui_clipboardmainwindow.h"

ClipboardMainWindow::ClipboardMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ClipboardMainWindow) {
    ui->setupUi(this);
    clipboard_listener_ = new ClipboardListener(this);
    window_listener_ = new WindowListener(this);
    tray_icon_ = new TinyCopyQTrayIcon(this);
    QObject::connect(
        clipboard_listener_,
        &ClipboardListener::captureNewContent,
        this,
        &ClipboardMainWindow::onCapturedNewContent);
    QObject::connect(
        getContentListWidget(),
        &ContentListWidget::leftDoubleClicked,
        this,
        &ClipboardMainWindow::onItemLeftBtnDoubleClicked);
    QObject::connect(
        window_listener_,
        &WindowListener::lossWindowFocus,
        this,
        &ClipboardMainWindow::onLossWindowFocus);
    QObject::connect(
        window_listener_,
        &WindowListener::getWindowFocus,
        this,
        &ClipboardMainWindow::onGetWindowFocus);
    QObject::connect(
        tray_icon_->quit_action_,
        &QAction::trigger,
        this,
        &ClipboardMainWindow::onTrayIconTriggered);

    clipboard_listener_->start();
    window_listener_->start();
}

ClipboardMainWindow::~ClipboardMainWindow() {
    clipboard_listener_->stop();
    window_listener_->stop();
    delete ui;
}

ContentListWidget *ClipboardMainWindow::getContentListWidget() {
    return ui->contentList;
}

void ClipboardMainWindow::onItemLeftBtnDoubleClicked(QListWidgetItem *item) {
    qDebug("%s", __FUNCTION__);
    GuiUtils::SetForegroundWindow(paste_target_, GuiUtils::status_code_);
    cpperclip::set_text_to_clipboard(item->text().toStdString());
    GuiUtils::Paste2ForeGroundWindow(GuiUtils::status_code_);
}

void ClipboardMainWindow::onCapturedNewContent(const String &content) {
    qDebug(__FUNCTION__);
    qDebug() << fmt::format("{}", content);
    getContentListWidget()->addContent(content);
}

void ClipboardMainWindow::onLossWindowFocus(const GuiUtils::WINID &winid) {
    qDebug("%s:\n---- %llu\n", __FUNCTION__, winid);
}

void ClipboardMainWindow::onGetWindowFocus(const GuiUtils::WINID &winid) {
    qDebug("%s:\n---- %llu\n", __FUNCTION__, winid);
    getContentListWidget()->updateContentListWidget();
    paste_target_ = winid;
}
QSystemTrayIcon *ClipboardMainWindow::getTrayIcon() {
    return tray_icon_->tray_icon_;
}
void ClipboardMainWindow::onTrayIconTriggered(
    QSystemTrayIcon::ActivationReason reason) {
    static auto is_hide = false;
    switch (reason) {
        case QSystemTrayIcon::Trigger: {
            if (is_hide) {
                this->show();
            } else {
                this->hide();
            }
            break;
        }
        default:
            break;
    }
}