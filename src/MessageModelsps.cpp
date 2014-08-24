#include "MessageModelsps.h"
#include "DataBase.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

MessageModelSPS::MessageModelSPS(QObject *parent) : QAbstractListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    // setRoleNames(roles);
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

void MessageModelSPS::addMessage(const Message &patient)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_Messages << patient;
    endInsertRows();
}
