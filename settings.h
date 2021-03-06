#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QVariant>
#include <QProcess>
#include "systemdefs.h"

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);
    ~Settings();
    
signals:
    
public slots:
    QVariant getValue(const QString & key, const QVariant & defaultValue = QVariant()) const;
    void setValue(const QString & key, const QVariant & value);
    void remove(const QString & key );
    void sync();
};

#endif // SETTINGS_H
