#ifndef WINDOWLISTENER_H
#define WINDOWLISTENER_H

#include "pch.hpp"
class WindowListener : public QThread
{
    Q_OBJECT
    bool stop_flag_ = false;

public:
    GuiUtils::WINID main_win_id_;
    explicit WindowListener(QObject *parent = nullptr);
    void run() override;
    void stop();
signals:
    void lossWindowFocus(const GuiUtils::WINID &winid);
    void getWindowFocus(const GuiUtils::WINID &winid);
};

#endif // WINDOWLISTENER_H
