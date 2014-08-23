
#include "../includes/ViewModel.h"

ViewModel::ViewModel()
{
   m_temperature = 0; 
}

QTime ViewModel::getCurrentTime() const
{
   return QTime::currentTime();
}

int ViewModel::getTemperature()
{
  return m_temperature;
}

void ViewModel::setTemperature(int c)
{
   if(c!=m_temperature)
   {
      m_temperature = c;
      emit temperatureChanged();
   }
}
