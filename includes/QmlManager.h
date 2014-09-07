/**
 * author : godbod
 * file   : MessageModel.h
 * date   : 2014-08-25
 * brief  : the messagemodel header file
 */

#ifndef QMLMANAGER_H
#define QMLMANAGER_H

#include <QtDeclarative>
#include "MessageModelsps.h"
#include "DataBase.h"

class QmlManager : public QObject
{
    Q_OBJECT

private:
    QDeclarativeView* configureQMLInterface(MessageModelSPS *);
    QDeclarativeView* configureLogin();

public:
    QmlManager();
    ~QmlManager();
    void showQMLInterface(MessageModelSPS *);
    void startLogin();

public slots:
    void slotStartChat();
    void slotStopLogin();

private:
    int height;
    int width;
    QString qmlPath;

    QDeclarativeView *viewLogin;
};

#endif // QMLMANAGER_H
