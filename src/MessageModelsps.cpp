#include "MessageModelsps.h"
#include "DataBase.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

MessageModelSPS::MessageModelSPS(QObject *parent) : QAbstractListModel(parent)
{
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
       cout<<"***" << (m_Messages[i].name()).toStdString() << endl;
    }
    */
}

void MessageModelSPS::slotAddMessage(QString message)
{
    if (!message.isEmpty()) {
       if (message.size() >= 25) {
          message.insert(12, QString("\n"));
          message = message + getCurrentTime().toString(" -- hh:mm"); 
          Message m(message);
          this->addMessage(m);
       }
       else {
          message = message + getCurrentTime().toString(" -- hh:mm"); 
          Message m(message);
          this->addMessage(m);
       }
    }
}

QTime MessageModelSPS::getCurrentTime() const
{
   return QTime::currentTime();
}
