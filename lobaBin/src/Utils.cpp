//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : Utils.cpp
/// Date   : 2014 Aug 25
/// Brief  : Utils implementation file
///
//////////////////////////////////////////


#include "Utils.h"
#include <iostream>

using namespace std;

///-----------------------------------
Utils::Utils()
///-----------------------------------
{
}

///-----------------------------------
Utils::~Utils()
///-----------------------------------
{
}

///-----------------------------------
QTime Utils::getCurrentTime() const
///-----------------------------------
{ 
   return QTime::currentTime();
}

///----------------------------------------------------------------------------
QString Utils::processMessage(QString message)
///----------------------------------------------------------------------------
{
    bool flag = false;

    /// cout << message.toStdString() << endl;

    QString processedMessage = "";

    for (int i = 0; i < message.size(); i++) {
       if ((message.at(i) == QChar('!')) && (flag == false)) {
          flag = true;
          processedMessage.append(message.at(i));
          processedMessage.append(" : ");
       } if (message.at(i) == QChar('#')) {
          flag = false;
       } else if (flag == false) {
          processedMessage.append(message.at(i));
       }
    }

    return processedMessage;
}
