#ifndef CONTENT_LIST_WIDGET_H
#define CONTENT_LIST_WIDGET_H
#include "data_structure.h"
#include "pch.hpp"
class ContentListWidget : public QListWidget {
    Q_OBJECT
    Deque<String> contents_;

public:
    void addContent(const String &content);
    void clearAll();
    void updateContentListWidget();
    ContentListWidget(QWidget *parent = nullptr) : QListWidget(parent) {
    }


    void mouseDoubleClickEvent(QMouseEvent *event) override;
    Deque<String> &contents();

signals:
    void leftDoubleClicked(QListWidgetItem *item);
};

#endif // CONTENT_LIST_WIDGET_H
