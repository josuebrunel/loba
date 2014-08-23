#ifndef _LAUNCHER_H_
#define _LAUNCHER_H_

#include <QObject>
#include "ViewModel.h"
#include "Temperature.h"
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>

class Launcher : public QObject
{
   Q_OBJECT

public:
   explicit Launcher(QObject *parent=0);
   void linkQttoQml(void);
   
private:
   Interface *viewModel;

   Temperature *temp;

   QDeclarativeView *view;
   QDeclarativeContext *ctxt;
};

#endif
