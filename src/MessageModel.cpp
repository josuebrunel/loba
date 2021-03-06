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

QString MessageModel::m_user    = "";
QString MessageModel::m_channel = "";
QString MessageModel::m_host    = "";

MessageModel::~MessageModel()
{
    delete m_utils;
    delete m_network;
    delete m_socket;
}

MessageModel::MessageModel(QObject *parent) : QAbstractListModel(parent)
{
    m_utils   = new Utils();
    m_network = new Network();
    m_socket  = m_network->getTcpSocket();

    m_network->connectToServer(m_user, m_channel, m_host);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

MessageModel::MessageModel(QString user, QString channel, QString host)
{
    MessageModel::m_user = user;
    MessageModel::m_channel = channel;
    MessageModel::m_host = host;
}


QHash<int, QByteArray> MessageModel::roleNames() const 
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[IdRole] = "id";

    return roles;
}

QVariant MessageModel::data(const QModelIndex &index, int role) const
{
    const Message &message = m_Messages[index.row()];

    if (index.row() < 0 || index.row() > m_Messages.count()) {
        return QVariant();
    }

    if (role == NameRole) {
        return message.name();
    }
    if (role == IdRole) {
       return message.id();
    }

    return QVariant();
}

int MessageModel::rowCount(const QModelIndex &) const
{
    return m_Messages.count();
}

void MessageModel::addMessage(const Message& message, int id)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_Messages << message;
    endInsertRows();
}

void MessageModel::slotAddMessage(QString message, int id)
{
    QString canal = "PRIVMSG #" + m_channel + " : ";

    QString str = canal + message + " \r\n";

    m_socket->write(str.toStdString().c_str());

    if (!message.isEmpty()) {
       message = "Me : " + message + m_utils->getCurrentTime().toString(" - hh:mm"); 
       Message m(message, id);
       this->addMessage(m, id);
    }
}

void MessageModel::readData() 
{
    QString readLine = m_socket->readLine();

    if (readLine.contains("PRIVMSG")) {
       readLine = m_utils->processMessage(readLine);
       readLine = readLine + m_utils->getCurrentTime().toString(" - hh:mm");
       Message m(readLine, 2);
       this->addMessage(m, 2);
       /// std::cout << readLine.toStdString() << std::endl;
    } else if (readLine.contains("PING")) {
       m_socket->write("TIME weber.freenode.net\r\n");
    }
    
    /// std::cout << readLine.toStdString() << std::endl;
    if(m_socket->canReadLine()) {
       readData();
    }
}
