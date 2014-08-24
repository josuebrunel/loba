#ifndef MESSAGEMODELSPS_H
#define MESSAGEMODELSPS_H

#include <QAbstractListModel>
#include "Message.h"
#include <QTime>

class MessageModelSPS : public QAbstractListModel
{
    Q_OBJECT

public:
    enum MessageRoles
    {
        NameRole = Qt::UserRole + 1
    };

    MessageModelSPS(QObject *parent = 0);

    void        loadDataBase(void);
    void        addMessage(const Message&);
    int         rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant    data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    QTime getCurrentTime() const;

public slots:
    void        slotAddMessage(QString);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Message> m_Messages;
};

#endif // MESSAGEMODELSPS_H
