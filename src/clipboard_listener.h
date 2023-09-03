#ifndef CLIPBOARDLISTENER_H
#define CLIPBOARDLISTENER_H

#include "pch.hpp"

class ClipboardListener : public QThread
{
    Q_OBJECT
public:
    cpperclip::CpperClip *cpper_clip_;
    explicit ClipboardListener(QObject *parent = nullptr);


    // QThread interface
    void run() override;
    void cpperclipCallBack(const String &content);
    void stop();
signals:
    void captureNewContent(const String &content);
};

#endif // CLIPBOARDLISTENER_H
