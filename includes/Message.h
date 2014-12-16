//  Copyright © 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : Message.h
/// Date   : 2014 Aug 25
/// Brief  : Message class file
///
//////////////////////////////////////////

#ifndef MESSAGE_H
#define MESSAGE_H

#include <QAbstractListModel>
#include <QStringList>

class Message
{
public:
    /// constructor
    Message(const QString &name, int id);

    /// destructor
    ~Message();

    /// properties methods
    QString name() const;
    int id() const;

/// private properties 
private:
    QString m_name;
    int m_id;
};

#endif // MESSAGE_H
