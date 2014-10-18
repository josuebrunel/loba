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

QString MessageModel::m_user = "";
QString MessageModel::m_channel = "";
QString MessageModel::m_host = "";

///----------------------------------------------------------------------------
MessageModel::~MessageModel()
///----------------------------------------------------------------------------
{
    delete m_utils;
    delete m_network;
    delete m_socket;
}

///----------------------------------------------------------------------------
MessageModel::MessageModel(QObject *parent) : QAbstractListModel(parent)
///----------------------------------------------------------------------------
{
    ///cout <<"in MessageModel::MessageModel()"<<endl;

    m_utils = new Utils();
    m_network = new Network();
    m_socket = m_network->getTcpSocket();

    /// cout<<"user   :"<<MessageModel::m_user.toStdString()<<endl;
    /// cout<<"channel:"<<MessageModel::m_channel.toStdString()<<endl;
    /// cout<<"host   :"<<MessageModel::m_host.toStdString()<<endl;

    m_network->connectToServer(m_user, m_channel, m_host);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

///----------------------------------------------------------------------------
MessageModel::MessageModel(QString user, QString channel, QString host)
///----------------------------------------------------------------------------
{
    /// cout <<"in MessageModel::MessageModel(QString, QString, QString)"<<endl;

    MessageModel::m_user = user;
    MessageModel::m_channel = channel;
    MessageModel::m_host = host;

    /// cout<<"user   :"<<MessageModel::m_user.toStdString()<<endl;
    /// cout<<"channel:"<<MessageModel::m_channel.toStdString()<<endl;
    /// cout<<"host   :"<<MessageModel::m_host.toStdString()<<endl;
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
    QString canal = "PRIVMSG #" + m_channel + " : ";

    ///char *str1 = (char *)"PRIVMSG #ubuntu :";
    char *str1 = (char *)canal.toStdString().c_str();
    const char *str2 = message.toStdString().c_str();
    char *str3 = (char *)" \r\n";
    char *str4 = (char *)malloc(strlen(str1) + strlen(str2) + strlen(str3));
    strcpy(str4, str1);
    strcat(str4, str2);
    strcat(str4, str3);

    m_socket->write(str4);
    ///m_socket->write(message.toStdString().c_str());

    if (!message.isEmpty()) {
       message = message + m_utils->getCurrentTime().toString(" ~ hh:mm"); 
       Message m(message);
       this->addMessage(m);
    }
}

///----------------------------------------------------------------------------
void MessageModel::readData() 
///----------------------------------------------------------------------------
{
    QString readLine = m_socket->readLine();

    if (readLine.contains("PRIVMSG")) {
       readLine = m_utils->processMessage(readLine);
       readLine = readLine + m_utils->getCurrentTime().toString(" ~ hh:mm");
       Message m(readLine);
       this->addMessage(m);
       /// std::cout << readLine.toStdString() << std::endl;
    } else if (readLine.contains("PING")) {
       m_socket->write("TIME weber.freenode.net\r\n");
    }
    
    /// std::cout << readLine.toStdString() << std::endl;
    if(m_socket->canReadLine()) {
       readData();
    }
}


