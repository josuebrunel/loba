//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : main.h
/// Date   : 2014 Aug 25
/// Brief  : main program file
///
//////////////////////////////////////////

#include <QApplication>
#include "QmlManager.h"

///-----------------------------
int main (int argc, char **argv)
///-----------------------------
{   
    QApplication app(argc, argv);

    QmlManager *qmlMan = new QmlManager();
    qmlMan->startLogin();

    return app.exec();
}
