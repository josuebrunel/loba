
#include <QApplication>
#include "QmlManager.h"

int main (int argc, char **argv)
{   
    QApplication app(argc, argv);

    QmlManager *qmlMan = new QmlManager();
    qmlMan->startLogin();

    return app.exec();
}
