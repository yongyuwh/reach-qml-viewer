/*************************************************************************
**
**    (C) Copyright 2013 Reach Technology Inc.
**
**    This code is protected by international copyright laws. This file may
**    only be used in accordance with a license and cannot be used on
**    hardware other than supplied by Reach Technology Inc. We appreciate
**    your understanding and fairness.
**
*************************************************************************/
#include <QApplication>
#include <QSettings>

#include "mainview.h"
#include "systemdefs.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QApplication::setOrganizationName("Reach Technology");
    QApplication::setOrganizationDomain("reachtech.com");
    QApplication::setApplicationName("Qml Viewer");
    QApplication::setApplicationVersion(APP_VERSION);

    QStringList args = app.arguments();

    foreach (QString item, args) {
        if(item == "--version" || item == "-v") {
            qDebug() << "QML Viewer " << APP_VERSION;
            return 0;
        }
    }

    QSettings settings(SYSTEM_SETTINGS_FILE,QSettings::NativeFormat);
    settings.beginGroup(SYSTEM_SETTINGS_SECTION);

    MainView w;
    w.setSource(QUrl::fromLocalFile(settings.value("main_view").toString()));
    w.enableLookupAck(settings.value("enable_ack",false).toBool());
    w.enableHeartbeat(settings.value("enable_heartbeat",false).toBool());
    w.setResizeMode(QDeclarativeView::SizeRootObjectToView);

    if (settings.value("full_screen",false).toBool()) {
        w.showFullScreen();
    }

    if (settings.value("hide_curosr",false).toBool()) {
        w.setCursor(QCursor( Qt::BlankCursor ));
    }

    settings.endGroup();

    w.show();
    
    return app.exec();
}
