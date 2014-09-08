//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : QmlManager.h
/// Date   : 2014 Aug 25
/// Brief  : QmlManager class file
///
//////////////////////////////////////////

#ifndef QMLMANAGER_H
#define QMLMANAGER_H

#include <QtDeclarative>
#include "MessageModel.h"
#include "DataBase.h"

class QmlManager : public QObject
{
    Q_OBJECT

/// private methods
private:
    QDeclarativeView* configureQMLInterface(MessageModel *);
    QDeclarativeView* configureLogin();

/// public methods
public:
    QmlManager();
    ~QmlManager();
    void showQMLInterface(MessageModel *);
    void startLogin();

/// public slots
public slots:
    void slotStartChat();
    void slotStopLogin();

/// private properties
private:
    int height;
    int width;
    QString qmlPath;
    QDeclarativeView *viewLogin;
};

#endif // QMLMANAGER_H
