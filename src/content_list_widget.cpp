#include "content_list_widget.h"

Deque<String> &ContentListWidget::contents() {
    return contents_;
}

void ContentListWidget::addContent(const String &content) {
    if (content == "") {
        return;
    }
    auto it = contents_.find(content);
    if (it != contents_.end()) {
        contents_.erase(it);
    }
    contents_.push_front(content);
}

void ContentListWidget::clearAll() {
    while (this->count()) {
        auto item = this->takeItem(0);
        delete item;
    }
    contents_.clear();
}

void ContentListWidget::updateContentListWidget() {
    auto item_cout = this->count();
    toy::enumerate(
        contents_,
        [this, &item_cout](const auto &i, const auto &value) {
            if (i < item_cout) {
                auto item = this->item(i);
                item->setText(value.c_str());
            } else {
                auto item = new QListWidgetItem(value.c_str());
                item->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
                item->setSizeHint(QSize(0, 130));
                this->addItem(item);
            }
            return false;
        });
}

void ContentListWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit leftDoubleClicked(this->currentItem());
    }
}
