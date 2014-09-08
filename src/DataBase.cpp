//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : DataBase.h
/// Date   : 2014 Aug 25
/// Brief  : DataBase implementation file
///
//////////////////////////////////////////

#include "DataBase.h"

///------------------
DataBase::DataBase()
///------------------
{
}

///--------------------------------------------------------
MessageModel* DataBase::LoadDataBase(MessageModel *model)
///--------------------------------------------------------
{
    /// get the model
    model = new MessageModel();
    model->addMessage(Message("Welcome on loba"));

    return model;
}
