
#ifndef _VIEWMODEL_H_
#define _VIEWMODEL_H_

#include <QObject>
#include <stdlib.h>
#include <QTime>
#include <iostream>

#include "Interface.h"

using namespace std;

class ViewModel : public QObject, public Interface
{
   Q_OBJECT

   // properties binding
   Q_PROPERTY(int temperature READ getTemperature WRITE setTemperature NOTIFY temperatureChanged)   

// getters && setters
public:
   ViewModel();

   Q_INVOKABLE QTime getCurrentTime() const;

   int  getTemperature();
   void setTemperature(int);

// signals
signals:
   void temperatureChanged();

// variables
private:
   int m_temperature; 
};

#endif
