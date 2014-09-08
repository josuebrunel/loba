//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : MessageModel.h
/// Date   : 2014 Aug 25
/// Brief  : MessageModel class file
///
//////////////////////////////////////////

#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QAbstractListModel>
#include "Message.h"
#include <QTime>
#include <QtNetwork/QTcpSocket>
#include <QObject>

class MessageModel : public QAbstractListModel
{
    Q_OBJECT

/// private slots
private slots:
    void readData();
    void disconnectFromServer();

/// public slots
public slots:
    void slotAddMessage(QString);

/// public Methods
public:
    enum MessageRoles
    {
        NameRole = Qt::UserRole + 1
    };

    void connectToServer();
    MessageModel(QObject *parent = 0);
    static MessageModel *getInstance();

    void loadDataBase(void);
    void addMessage(const Message&);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    QTime getCurrentTime() const;

/// inherited properties
protected:
    QHash<int, QByteArray> roleNames() const;

/// private properties
private:
    QList<Message> m_Messages;
    QTcpSocket *socket;

    static MessageModel *m_pInstance;
};

#endif // MESSAGEMODELSPS_H
