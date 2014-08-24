#include "Message.h"

Message::Message(const QString &name) : m_name(name)
{
}

Message::~Message() 
{ 
}

QString Message::name() const 
{ 
   return m_name; 
}
