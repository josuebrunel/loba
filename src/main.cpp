#include <QApplication>
#include "MessageModelsps.h"
#include "QmlManager.h"
#include "DataBase.h"

int main (int argc, char **argv)
{   
    QApplication app(argc, argv);

    DataBase *dbLoad = new DataBase();
    MessageModelSPS *modelsps;
    modelsps   = dbLoad->LoadDataBaseSPS(modelsps);
    QmlManager *qmlMan = new QmlManager();
    qmlMan->showQMLInterface(modelsps);

    return app.exec();
}
