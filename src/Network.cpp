//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : Network.cpp
/// Date   : 2014 Aug 25
/// Brief  : Network implementation file
///
//////////////////////////////////////////

#include "Network.h"

///----------------------------------------------------------------------------
Network::Network()
///----------------------------------------------------------------------------
{
    m_socket = new QTcpSocket(this);
}

///----------------------------------------------------------------------------
Network::~Network()
///----------------------------------------------------------------------------
{
   delete m_socket;
}

///----------------------------------------------------------------------------
void Network::connectToServer(QString user, QString channel, QString host)
///----------------------------------------------------------------------------
{
    m_user = "NICK " + user + "\r\n";
    m_channel = "JOIN #" + channel + "\r\n";
    m_host = host;

    m_socket->connectToHost(m_host, 6667);
    m_socket->write(m_user.toStdString().c_str());
    m_socket->write("USER guest tolmoon tolsun :Ronnie Reagan\r\n");
    m_socket->write(m_channel.toStdString().c_str());
}

///----------------------------------------------------------------------------
void Network::disconnectFromServer()
///----------------------------------------------------------------------------
{
    m_socket->write("QUIT Good bye \r\n");
    m_socket->flush();
    m_socket->disconnect();
}

///----------------------------------------------------------------------------
QTcpSocket* Network::getTcpSocket()
///----------------------------------------------------------------------------
{
   return m_socket;
}
