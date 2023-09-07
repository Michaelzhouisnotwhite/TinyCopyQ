#include "NativeEventFilter.h"
#include "pch.hpp"
#include <windows.h>
GlobalKeyEventFilter::GlobalKeyEventFilter(
    QApplication &app_handler, const uint32_t &mod, const uint32_t &key)
    : mod_(mod), key_(key), app_handler_(app_handler) {
}

bool GlobalKeyEventFilter::nativeEventFilter(
    const QByteArray &eventType, void *message, int64_t *result) {
    qDebug() << eventType << Qt::endl;
    MSG *msg = static_cast<MSG *>(message);
    if (msg->message == WM_HOTKEY) {
        const quint32 keycode = HIWORD(msg->lParam);
        const quint32 modifiers = LOWORD(msg->lParam);
        if (keycode == key_ && mod_ == modifiers) {
            qDebug() << fmt::format("shortcut triggered") << Qt::endl;
        }
    }

    return false;
}
