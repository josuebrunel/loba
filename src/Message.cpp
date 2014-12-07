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
