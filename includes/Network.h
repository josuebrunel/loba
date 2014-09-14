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
#include <QObject>

class Network : public QObject
{
   Q_OBJECT

/// public methods
public:
   Network();
   ~Network();

   void connectToServer(QString, QString, QString);
   void disconnectFromServer();

   QTcpSocket* getTcpSocket();

/// private properties
private:
   QTcpSocket *m_socket; 
   QString m_user;
   QString m_channel;
   QString m_host;
};

#endif // NETWORK_H
