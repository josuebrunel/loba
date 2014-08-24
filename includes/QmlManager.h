#ifndef QMLMANAGER_H
#define QMLMANAGER_H

#include <QtDeclarative>
#include "MessageModelsps.h"

class QmlManager
{
private:
    QDeclarativeView* configureQMLInterface(MessageModelSPS *);

public:
    QmlManager();
    ~QmlManager();
    void showQMLInterface(MessageModelSPS *);

private:
    int height;
    int width;
    QString qmlPath;
};

#endif // QMLMANAGER_H
