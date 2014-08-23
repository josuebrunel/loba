
#include "../includes/Temperature.h"

Temperature::Temperature(Interface *viewModel_instance)
{
   therm = 0;
   temporary_temperature = 0;
   this->viewModel = viewModel_instance;

   QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(temperature_sensor()));
   timer.start(500);
}

void Temperature::temperature_sensor(void)
{
   // temperature du processeur
   ifstream inFile("/sys/class/thermal/thermal_zone0/temp");
   inFile >> therm;
   inFile.close();

   // therm = rand()%10;
   if(therm != temporary_temperature)
   {
      temporary_temperature = therm;
      viewModel->setTemperature(therm/1000);
      // viewModel->setTemperature(therm);
   }
}
