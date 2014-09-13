//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : Network.h
/// Date   : 2014 Aug 25
/// Brief  : Network class file
///
//////////////////////////////////////////

#ifndef NETWORK_H
#define NETWORK_H

#include <QtNetwork/QTcpSocket>

class Network
{
/// public methods
public:
   void connectToServer();
   void disconnectFromServer();

/// private properties
private:
   QTcpSocket *socket; 
};

#endif // NETWORK_H
