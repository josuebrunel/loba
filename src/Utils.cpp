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

Utils::Utils()
{
   /// nothing to delete
}

Utils::~Utils()
{
}

QTime Utils::getCurrentTime() const
{ 
   return QTime::currentTime();
}

QString Utils::formatLink(QString message)
{
   bool flag1 = false;
   bool flag2 = false;

   for (int i = 0; i < message.size(); i++) 
   {
      if (message.at(i) == QChar('h') 
	    && message.at(i+1) == QChar('t') 
	    && message.at(i+2) == QChar('t') 
	    && message.at(i+3) == QChar('p')
	    && flag1           == false)
      {
	 //cout << "link detected" << endl;
	 message.replace("http", "<a href=\"http");
	 flag1 = true;
      }
      if (message.at(i) == ' ' && flag2 == false)
      {
         //cout << "end of link" << endl;
         message.append("\"> not functional link </a>");
	 flag2 = true;
      }
   }

   //cout << message.toStdString() << endl;

   return message;
}

QString Utils::processMessage(QString message)
{
   bool flag = false;
   bool link = false;

   QString linkStart = "http";

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

   if (processedMessage.contains(linkStart, Qt::CaseInsensitive)) {
      //cout << "there's a link here" << endl;
      processedMessage = this->formatLink(processedMessage);
   }

   return processedMessage;
}
