// Class MessageModel

#ifndef MESSAGEMODEL_H_
#define MESSAGEMODEL_H_

#include <QAbstractListModel>

typedef struct {
   unsigned int index;
   QString message;
}MessageInfo;

class MessageModel : public QAbstractListModel
{

   enum MessageRoles
   {
      NameRole = Qt::UserRole + 1,
      MessageRole
   };

   Q_OBJECT

public:
   MessageModel(MessageModel *, QObject *parent = 0);

   void           addMessage(const Message&);
   unsigned int   rowCount(const QModelIndex& parent = QModelIndex()) const;
   QVariant       data(const QModelIndex& index, int role = Qt::DisplayRole) const;

private:
   QList<Message> m_messages;
   MessageInfo    mInfo;
};

#endif // MESSAGEMODEL_H_ 
