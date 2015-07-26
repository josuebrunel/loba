//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : Message.cpp
/// Date   : 2014 Aug 25
/// Brief  : Message implementation file
///
//////////////////////////////////////////

#include "Message.h"

Message::Message(const QString &name, const int id) : m_name(name), m_id(id)
{
}

Message::~Message() 
{ 
}

QString Message::name() const 
{ 
   return m_name; 
}

int Message::id() const
{
   return m_id;
}
