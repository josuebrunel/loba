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

    const Message &Message = m_Messages[index.row()];

    if (role == NameRole)
        return Message.name();
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
    cout<<"***" << (m_Messages[0].name()).toStdString() << endl;
}

void MessageModelSPS::slotAddMessage(QString message)
{
    Message m(message);
    cout << m.name().toStdString() << endl;
    this->addMessage(m);
}
