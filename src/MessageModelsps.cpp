#include "MessageModelsps.h"
#include "DataBase.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

MessageModelSPS *MessageModelSPS::m_pInstance = NULL;

MessageModelSPS *MessageModelSPS::getInstance()
{
   if (!m_pInstance) {
      m_pInstance = new MessageModelSPS;
   }
   return m_pInstance;
}

MessageModelSPS::MessageModelSPS(QObject *parent) : QAbstractListModel(parent)
{
    socket = new QTcpSocket(this);
    connectToServer();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
    //connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    //connect(ui->disconnectButton, SIGNAL(clicked()), this, SLOT(disconnectFromServer()));
}

QHash<int, QByteArray> MessageModelSPS::roleNames() const 
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    return roles;
}

QVariant MessageModelSPS::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() > m_Messages.count())
        return QVariant();

    const Message &message = m_Messages[index.row()];

    if (role == NameRole)
        return message.name();
    return QVariant();
}

int MessageModelSPS::rowCount(const QModelIndex &) const
{
    return m_Messages.count();
}

void MessageModelSPS::addMessage(const Message& message)
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

void MessageModelSPS::slotAddMessage(QString message)
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
       message = message + getCurrentTime().toString(" ~ hh:mm"); 
       Message m(message);
       this->addMessage(m);
    }
}

QTime MessageModelSPS::getCurrentTime() const
{
   return QTime::currentTime();
}
 
void MessageModelSPS::connectToServer() 
{
    socket->connectToHost(QString("irc.freenode.net"), 6667);
    // USER, NICK and JOIN commands
    socket->write("NICK godbod \r\n");
    socket->write("USER guest tolmoon tolsun :Ronnie Reagan\r\n");
    socket->write("JOIN #ubuntu\r\n");
}
 
void MessageModelSPS::readData() 
{
    QString readLine = socket->readLine();

    if (readLine.contains("PRIVMSG")) {
       readLine = readLine + getCurrentTime().toString(" ~ hh:mm");
       Message m(readLine);
       this->addMessage(m);
       // std::cout << readLine.toStdString() << std::endl;
    } else if (readLine.contains("PING")) {
       socket->write("TIME weber.freenode.net\r\n");
    }
    
    //std::cout << readLine.toStdString() << std::endl;

    if(socket->canReadLine()) readData();
}
 
void MessageModelSPS::disconnectFromServer() 
{
    socket->write("QUIT Good bye \r\n");
    socket->flush();
    socket->disconnect();
}
