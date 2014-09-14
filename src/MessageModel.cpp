//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : MessageModdel.cpp
/// Date   : 2014 Aug 25
/// Brief  : MessageModdel implementation file
///
//////////////////////////////////////////

#include "MessageModel.h"
#include "DataBase.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

///----------------------------------------------------------------------------
MessageModel::MessageModel(QObject *parent) : QAbstractListModel(parent)
///----------------------------------------------------------------------------
{
    m_utils = new Utils();
    socket = new QTcpSocket(this);
    connectToServer();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

///----------------------------------------------------------------------------
QHash<int, QByteArray> MessageModel::roleNames() const 
///----------------------------------------------------------------------------
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";

    return roles;
}

///----------------------------------------------------------------------------
QVariant MessageModel::data(const QModelIndex &index, int role) const
///----------------------------------------------------------------------------
{
    const Message &message = m_Messages[index.row()];

    if (index.row() < 0 || index.row() > m_Messages.count()) {
        return QVariant();
    }

    if (role == NameRole) {
        return message.name();
    }

    return QVariant();
}

///----------------------------------------------------------------------------
int MessageModel::rowCount(const QModelIndex &) const
///----------------------------------------------------------------------------
{
    return m_Messages.count();
}

///----------------------------------------------------------------------------
void MessageModel::addMessage(const Message& message)
///----------------------------------------------------------------------------
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_Messages << message;
    endInsertRows();

    /*    
    for (int i = 0; i < m_Messages.size(); i++) {
       cout<<"*r*" << (m_Messages[i].name()).toStdString() << endl;
    }
    */
}

///----------------------------------------------------------------------------
void MessageModel::slotAddMessage(QString message)
///----------------------------------------------------------------------------
{
       char *str1       = (char *)"PRIVMSG #ubuntu :";
       const char *str2 = message.toStdString().c_str();
       char *str3       = (char *)" \r\n";
       char *str4       = (char *)malloc(1 + strlen(str1) + strlen(str2) + strlen(str3));
       strcpy(str4, str1);
       strcat(str4, str2);
       strcat(str4, str3); 

       socket->write(str4);

    if (!message.isEmpty()) {
       message = message + m_utils->getCurrentTime().toString(" ~ hh:mm"); 
       Message m(message);
       this->addMessage(m);
    }
}

///----------------------------------------------------------------------------
void MessageModel::connectToServer() 
///----------------------------------------------------------------------------
{
    socket->connectToHost(QString("irc.freenode.net"), 6667);

    socket->write("NICK Timoty \r\n");
    socket->write("USER guest tolmoon tolsun :Ronnie Reagan\r\n");
    socket->write("JOIN #ubuntu\r\n");
}
 
///----------------------------------------------------------------------------
void MessageModel::readData() 
///----------------------------------------------------------------------------
{
    QString readLine = socket->readLine();

    if (readLine.contains("PRIVMSG")) {
       readLine = readLine + m_utils->getCurrentTime().toString(" ~ hh:mm");
       Message m(readLine);
       this->addMessage(m);
       // std::cout << readLine.toStdString() << std::endl;
    } else if (readLine.contains("PING")) {
       socket->write("TIME weber.freenode.net\r\n");
    }
    
    //std::cout << readLine.toStdString() << std::endl;

    if(socket->canReadLine()) {
       readData();
    }
}
 
///----------------------------------------------------------------------------
void MessageModel::disconnectFromServer() 
///----------------------------------------------------------------------------
{
    socket->write("QUIT Good bye \r\n");
    socket->flush();
    socket->disconnect();
}
