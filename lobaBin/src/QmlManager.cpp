//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : QmlManager.cpp
/// Date   : 2014 Aug 25
/// Brief  : QmlManager implementation file
///
//////////////////////////////////////////

#include "QmlManager.h"
#include <iostream>

using namespace std;

///-------------------------------------------
QmlManager::QmlManager()
///-------------------------------------------
{
    this->height  = 550;
    this->width   = 300;
    this->qmlPath = "";
}

///-------------------------------------------
void QmlManager::slotStartChat()
///-------------------------------------------
{
    DataBase *dbLoad = new DataBase();
    ///MessageModel *model;
    model = dbLoad->LoadDataBase(model);
    this->showQMLInterface(model);
}

///-------------------------------------------
void QmlManager::startLogin()
///-------------------------------------------
{
    viewLogin = configureLogin();
    viewLogin->show();
}

///-------------------------------------------
void QmlManager::slotStopLogin()
///-------------------------------------------
{
    viewLogin->close();
}

///-------------------------------------------
void QmlManager::slotSendLogin(QString user, QString channel, QString host)
///-------------------------------------------
{
   /// cout <<"in QmlManager::slotSendLogin()"<<endl;

   /// cout<<"user   :"<<user.toStdString()<<endl;
   /// cout<<"channel:"<<channel.toStdString()<<endl;
   /// cout<<"host   :"<<host.toStdString()<<endl;

   model = new MessageModel(user, channel, host);   
   ///model = new MessageModel("Timoty", "ubuntu", "irc.freenode.net");   
}

///-------------------------------------------
void QmlManager::showQMLInterface(MessageModel *model)
///-------------------------------------------
{
    QDeclarativeView *view = configureQMLInterface(model);
    view->show();
}

///-------------------------------------------
QDeclarativeView* QmlManager::configureLogin()
///-------------------------------------------
{
    QDeclarativeView *view = new QDeclarativeView();
    view->setSource(QUrl::fromLocalFile("../resources/login.qml"));
    QObject *item;
    item = view->rootObject();
    view->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    view->setMinimumSize(this->width, this->height);
    view->setMaximumSize(this->width + 200, this->height - 200);
    
    QObject::connect((QObject *)item, SIGNAL(quitLogin()),  this, SLOT(slotStartChat()));
    QObject::connect((QObject *)item, SIGNAL(quitLogin()),  this, SLOT(slotStopLogin()));
    QObject::connect((QObject *)item, SIGNAL(sendLogin(QString, QString, QString)),  this, SLOT(slotSendLogin(QString, QString, QString)));

    return view;
}

///-------------------------------------------
QDeclarativeView* QmlManager::configureQMLInterface(MessageModel *md)
///-------------------------------------------
{
    QDeclarativeView    *view = new QDeclarativeView();
    QDeclarativeContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModelsps", md);
    view->setSource(QUrl::fromLocalFile("../resources/main.qml"));
    QObject *item;
    item = view->rootObject();
    view->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    view->setMinimumSize(this->width, this->height);
    view->setMaximumSize(this->width + 200, this->height - 200);

    QObject::connect((QObject *)item, SIGNAL(sendMessage(QString)),  md,  SLOT(slotAddMessage(QString)));

    return view;
}

///-------------------------------------------
QmlManager::~QmlManager()
///-------------------------------------------
{
}
