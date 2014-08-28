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
    char *str1       = "PRIVMSG #ubuntu :";
    const char *str2 = message.toStdString().c_str();
    char *str3       = " \r\n";
    char * str4      = (char *)malloc(1 + strlen(str1) + strlen(str2) + strlen(str3));
    strcpy(str4, str1);
    strcat(str4, str2);
    strcat(str4, str3); 

    cout << str4 << endl;

    socket->write(str4);
    // socket->write("PRIVMSG #ubuntu :hello world \r\n");

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
    socket->connectToHost(QString("irc.ubuntu.com"), 6667);
    // USER, NICK and JOIN commands
    socket->write("NICK godbod \r\n");
    socket->write("USER guest tolmoon tolsun :Ronnie Reagan\r\n");
    socket->write("JOIN #ubuntu\r\n");
    // Now we are successfully connected to IRC SERVER...
}
 
void MessageModelSPS::readData() 
{
    QString readLine = socket->readLine();

    // std::cout << readLine.toStdString() << std::endl;
    // Something with readLine (for example: If someone write "hello" bot respond will be "hello world!")
    // Message m(readLine);
    // this->addMessage(m);

    if(readLine.contains("PRIVMSG")) {
       // socket->write("PRIVMSG #test_room :hello world \r\n");
       // std::cout << readLine.toStdString() << std::endl;

       Message m(readLine);
       this->addMessage(m);
       std::cout << readLine.toStdString() << std::endl;
    }
    // Next data??
    if(socket->canReadLine()) readData();
}
 
void MessageModelSPS::disconnectFromServer() {
    // Disconnect from IRC server
    socket->write("QUIT Good bye \r\n"); // Good bye is optional message
    socket->flush();
    socket->disconnect(); // Now we can try it :-)
}
