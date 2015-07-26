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

DataBase::DataBase()
{
}

DataBase::~DataBase()
{
}

MessageModel* DataBase::LoadDataBase(MessageModel *model)
{
    /// defining the welcome message
    /// Message greeting("- Copyright (c) 2014 godbod -");

    /// get the model
    model = new MessageModel();
    /// model->addMessage(greeting);

    return model;
}
