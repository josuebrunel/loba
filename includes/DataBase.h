//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : DataBase.h
/// Date   : 2014 Aug 25
/// Brief  : DataBase class file
///
//////////////////////////////////////////

#ifndef DATABASE_H
#define DATABASE_H

#include "MessageModel.h"

/// DataBase class

class DataBase
{
public:
    /// constructor
    DataBase();

    /// destructor
    ~DataBase();

    /// DataBase loader
    MessageModel* LoadDataBase(MessageModel *);
};

#endif // DATABASE_H
