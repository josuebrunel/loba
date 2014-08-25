#include "QmlManager.h"

QmlManager::QmlManager()
{
    this->height  = 550;
    this->width   = 300;
    this->qmlPath = "../resources/main.qml";
}

void QmlManager::showQMLInterface(MessageModelSPS *modelsps)
{
    QDeclarativeView *view = configureQMLInterface(modelsps);
    view->show();
}

QDeclarativeView* QmlManager::configureQMLInterface(MessageModelSPS *mdsps)
{
    QDeclarativeView *view = new QDeclarativeView();
    QDeclarativeContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModelsps", mdsps);
    view->setSource(QUrl::fromLocalFile(qmlPath));
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
