#include "../includes/Launcher.h"

Launcher::Launcher(QObject *parent):QObject(parent)
{
   view  = new QDeclarativeView();
   viewModel = new ViewModel();

   temp  = new Temperature(viewModel);
}

// viewModel will be the name to be used in the QML file
void Launcher::linkQttoQml(void)
{
   ctxt = view->rootContext();
   ctxt->setContextProperty("viewModel", (ViewModel *)viewModel);
   view->setResizeMode(QDeclarativeView::SizeViewToRootObject);
   view->setSource(QUrl("qrc:qml/main.qml"));
   
   view->show();
}
