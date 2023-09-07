#ifndef NATIVEEVENTFILTER_H
#define NATIVEEVENTFILTER_H
#include "pch.hpp"
class GlobalKeyEventFilter : public QAbstractNativeEventFilter {
    Q_OBJECT
public:
    uint32_t mod_, key_;
    QApplication &app_handler_;
    GlobalKeyEventFilter(
        QApplication &app_handler, const uint32_t &mod, const uint32_t &key);
    bool nativeEventFilter(
        const QByteArray &eventType, void *message, int64_t *result) override;

signals:
    void hotkeyTriggered();
};

class ShortCutConfig {
public:
};


//class ShortcutTest
//{
//public:
//    ShortcutTest(){};
//    ~ShortcutTest(){};

//public:
//    void registerShortcut(const NativeEventFilter &filter);
//};
#endif // NATIVEEVENTFILTER_H
