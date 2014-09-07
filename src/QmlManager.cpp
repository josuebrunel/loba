#include "QmlManager.h"

QmlManager::QmlManager()
{
    this->height  = 550;
    this->width   = 300;
    this->qmlPath = "";
}

void QmlManager::slotStartChat()
{
    DataBase *dbLoad = new DataBase();
    MessageModelSPS *modelsps;
    modelsps = dbLoad->LoadDataBaseSPS(modelsps);
    this->showQMLInterface(modelsps);
}

void QmlManager::startLogin()
{
    viewLogin = configureLogin();
    viewLogin->show();
}

void QmlManager::slotStopLogin()
{
    viewLogin->close();
}

void QmlManager::showQMLInterface(MessageModelSPS *modelsps)
{
    QDeclarativeView *view = configureQMLInterface(modelsps);
    view->show();
}

QDeclarativeView* QmlManager::configureLogin()
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

    return view;
}

QDeclarativeView* QmlManager::configureQMLInterface(MessageModelSPS *mdsps)
{
    QDeclarativeView    *view = new QDeclarativeView();
    QDeclarativeContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModelsps", mdsps);
    view->setSource(QUrl::fromLocalFile("../resources/main.qml"));
    QObject *item;
    item = view->rootObject();
    view->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    view->setMinimumSize(this->width, this->height);
    view->setMaximumSize(this->width + 200, this->height - 200);

    QObject::connect((QObject *)item, SIGNAL(sendMessage(QString)),  mdsps,  SLOT(slotAddMessage(QString)));

    return view;
}

QmlManager::~QmlManager()
{
}
