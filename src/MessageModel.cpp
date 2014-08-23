
#include "MessageModel.h"

MessageModel::MessageModel(MessageModel *message, QObject *parent) : QAbstractListModel(parent)
{
   QHash<int, QByteArray> roles;
   roles[messageRole] = "message";

   setRoleNames(roles);
}

void addMessage(const Message& message)
{
   beginInsertRows(QModelIndex(), rowCount(), rowCount());
   m_messages << message;
   endRemoveRows();
}

unsigned int MessageModel::rowCount(const QModelIndex&) const
{
   return m_messages.count();
}

QVariant MessageModel::data(const QModelIndex& index, int role) const
{
   const Message &message = m_messages[index.row()];

   if (index.row() < 0 || index.row() > m_messages.count()) {
      return QVariant();
   }

   if (role == MessageRole) {
      return Message.message();
   }

   return QVariant();
}
