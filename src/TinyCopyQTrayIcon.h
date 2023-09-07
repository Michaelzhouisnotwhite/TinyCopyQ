#ifndef SRC_TINYCOPYQTRAYBTN
#define SRC_TINYCOPYQTRAYBTN

#include "pch.hpp"
class TinyCopyQTrayIcon {
public:
    QMenu* menu_;
    QWidget* parent_;
    QAction* quit_action_;
    QSystemTrayIcon *tray_icon_;
    TinyCopyQTrayIcon(QWidget* parent=nullptr);
    ~TinyCopyQTrayIcon();
    void createContextMenu();
    void trayIconShow();
private:
};

#endif /* SRC_TINYCOPYQTRAYBTN */
