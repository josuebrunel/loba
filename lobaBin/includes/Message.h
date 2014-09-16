//  Copyright (c) 2014 godbod
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
    Message(const QString &name);

    /// destructor
    ~Message();

    /// properties methods
    QString name() const;

/// private properties 
private:
    QString m_name;
};

#endif // MESSAGE_H
