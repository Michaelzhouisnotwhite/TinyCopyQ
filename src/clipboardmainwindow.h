#ifndef CLIPBOARDMAINWINDOW_H
#define CLIPBOARDMAINWINDOW_H

#include "clipboard_listener.h"
#include "content_list_widget.h"
#include "data_structure.h"
#include "pch.hpp"
#include "ui_clipboardmainwindow.h"
#include "window_listener.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClipboardMainWindow; }
QT_END_NAMESPACE

class ClipboardMainWindow : public QMainWindow
{
    Q_OBJECT
    ClipboardListener *clipboard_listener_;
    WindowListener *window_listener_;
    GuiUtils::WINID paste_target_ = 0;

public:
    ClipboardMainWindow(QWidget *parent = nullptr);
    ~ClipboardMainWindow();
    ContentListWidget *getContentListWidget();

private:
    Ui::ClipboardMainWindow *ui;
public slots:
    void onItemLeftBtnDoubleClicked(QListWidgetItem *item);
    void onCapturedNewContent(const String &content);
    void onLossWindowFocus(const GuiUtils::WINID &winid);
    void onGetWindowFocus(const GuiUtils::WINID &winid);
};
#endif // CLIPBOARDMAINWINDOW_H
