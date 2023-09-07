#include "TinyCopyQTrayIcon.h"

TinyCopyQTrayIcon::TinyCopyQTrayIcon(QWidget *parent) : parent_(parent) {
    tray_icon_ = new QSystemTrayIcon(parent);
    auto icon = QIcon(":/icon/ui/icon.png");
    if (icon.isNull()) {
        throw std::runtime_error(":/icon/ui/icon.png not found");
    }
    tray_icon_->setIcon(icon);
    this->createContextMenu();
}

TinyCopyQTrayIcon::~TinyCopyQTrayIcon() {
    delete menu_;
    delete quit_action_;
    delete tray_icon_;
}
void TinyCopyQTrayIcon::createContextMenu() {
    menu_ = new QMenu(parent_);
    quit_action_ = new QAction("退出", parent_);
    menu_->addAction(quit_action_);
    tray_icon_->setContextMenu(menu_);
}

void TinyCopyQTrayIcon::trayIconShow() {
    tray_icon_->show();
}
