#include "clipboardmainwindow.h"
#include "platforms/NativeEventFilter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClipboardMainWindow w;
    w.show();
    return a.exec();
}
