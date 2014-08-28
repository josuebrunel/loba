#ifndef MESSAGEMODELSPS_H
#define MESSAGEMODELSPS_H

#include <QAbstractListModel>
#include "Message.h"
#include <QTime>
#include <QtNetwork/QTcpSocket>
#include <QObject>

class MessageModelSPS : public QAbstractListModel
{
    Q_OBJECT

public:
    void connectToServer();
   
private:
    QTcpSocket * socket;
 
private slots:
    void readData();
    void disconnectFromServer();

public:
    enum MessageRoles
    {
        NameRole = Qt::UserRole + 1
    };

    MessageModelSPS(QObject *parent = 0);
    static MessageModelSPS *getInstance();

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
    static MessageModelSPS *m_pInstance;
};

#endif // MESSAGEMODELSPS_H
