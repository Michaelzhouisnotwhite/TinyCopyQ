#include "TinyCopyQTrayIcon.h"

TinyCopyQTrayIcon::TinyCopyQTrayIcon(QWidget* parent){
    tray_icon_ = new QSystemTrayIcon(parent);
    tray_icon_->setIcon(QIcon(":/icon/icon.png"));
    // tray_icon_->show();
}

TinyCopyQTrayIcon::~TinyCopyQTrayIcon() {
    delete tray_icon_;
}
void TinyCopyQTrayIcon::createContextMenu() {
    menu_ = new QMenu();
    quit_action_ = new QAction("退出", parent_);
    menu_->addAction(quit_action_);
}

void TinyCopyQTrayIcon::trayIconShow() {
    tray_icon_->show();
}
