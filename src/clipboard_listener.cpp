#include "clipboard_listener.h"

ClipboardListener::ClipboardListener(QObject *parent) : QThread{parent} {
    cpper_clip_ = new cpperclip::CpperClip([this](const String &content) {
        this->cpperclipCallBack(content);
    });
}

void ClipboardListener::run() {
    cpper_clip_->start();
}

void ClipboardListener::cpperclipCallBack(const String &content) {
    emit captureNewContent(content);
}

void ClipboardListener::stop() {
    cpper_clip_->stop();
    this->wait();
}
