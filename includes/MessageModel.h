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
#include <QtNetwork/QTcpSocket>
#include <QObject>
#include "Utils.h"
#include "Network.h"

/// enumeration structure
enum MessageRoles
{
   NameRole = Qt::UserRole + 1,
   IdRole = Qt::UserRole + 2
};

class MessageModel : public QAbstractListModel
{
    Q_OBJECT

/// private slots
private slots:
    void readData();

/// public slots
public slots:
    void slotAddMessage(QString, int);

/// public Methods
public:
    MessageModel(QObject *parent = 0);
    MessageModel(QString, QString, QString);
    ~MessageModel();

    void loadDataBase(void);
    void addMessage(const Message&, int);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;


    static QString m_user;
    static QString m_channel;
    static QString m_host;


/// inherited properties
protected:
    QHash<int, QByteArray> roleNames() const;
    QHash<int, QByteArray> roleIds() const;

/// private properties
private:
    QList<Message> m_Messages;
    Utils *m_utils;
    Network *m_network;
    QTcpSocket *m_socket;
};

#endif // MESSAGEMODELSPS_H
