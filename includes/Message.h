#ifndef MESSAGE_H
#define MESSAGE_H

#include <QAbstractListModel>
#include <QStringList>

class Message
{
public:
    Message(const QString &name);
    ~Message();

    QString name() const;

private:
    QString m_name;
};

#endif // MESSAGE_H
