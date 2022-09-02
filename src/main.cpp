#include "mainwindow.h"

#include <QApplication>
#include <QScreen>
#include <iostream>

int main(int argc, char *argv[])
{
    QSurfaceFormat fmt;
    fmt.setVersion(4, 1);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(fmt);
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("lab04");
    QCoreApplication::setOrganizationName("BrownCSCI1230");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    MainWindow w;
    // w.resize(w.sizeHint());
    w.resize(600, 400);
    int desktopArea = QGuiApplication::primaryScreen()->size().width() *
                      QGuiApplication::primaryScreen()->size().height();
    int widgetArea = w.width() * w.height();
    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        w.show();
    else
        w.showMaximized();

    return a.exec();
}
