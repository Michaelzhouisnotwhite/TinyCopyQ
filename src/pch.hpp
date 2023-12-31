#ifndef PCH_HPP
#define PCH_HPP
#include <MyGuiUtils/common.hpp>
#include <QAbstractNativeEventFilter>
#include <QAction>
#include <QByteArray>
#include <QDebug>
#include <QIcon>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QThread>
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <array>
#include <chrono>
#include <deque>
#include <fmt/core.h>
#include <fmt/format.h>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <toy/cpperclip.hpp>
#include <toy/include.h>
#include <vector>
using namespace std::literals;
using namespace std::string_literals;
using namespace std::chrono_literals;
using String = std::string;
template<typename T>
using Vec = std::vector<T>;
namespace cpperclip = toy::cpperclip;
#endif // PCH_HPP
