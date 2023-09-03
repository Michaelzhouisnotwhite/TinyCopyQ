#include "window_listener.h"

WindowListener::WindowListener(QObject *parent)
    : QThread{parent}
{
    auto parent_widget = dynamic_cast<QWidget *>(parent);
    if (!parent_widget) {
        throw std::runtime_error("no parent widget");
    }
    main_win_id_ = parent_widget->winId();
}

void WindowListener::run() {
    GuiUtils::WINID last_win_id
        = GuiUtils::GetForegroundWinId(GuiUtils::status_code_);
    while (!stop_flag_) {
        auto cur_win_id = GuiUtils::GetForegroundWinId(GuiUtils::status_code_);
        if (cur_win_id == last_win_id || GuiUtils::IsAltTabWindow(cur_win_id)) {
            this->msleep(200);
            continue;
        }
        if (last_win_id == main_win_id_) {
            emit lossWindowFocus(cur_win_id);
        } else if (cur_win_id == main_win_id_) {
            emit getWindowFocus(last_win_id);
        }
        last_win_id = cur_win_id;
    }
}

void WindowListener::stop() {
    stop_flag_ = true;
    this->wait();
}
