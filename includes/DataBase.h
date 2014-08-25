/**
 * author : godbod
 * file   : Database.h
 * date   : 2014-08-25
 * brief  : the database header file
 */

#ifndef DATABASE_H
#define DATABASE_H

#include "MessageModelsps.h"

class DataBase
{
public:
    DataBase();

    MessageModelSPS* LoadDataBaseSPS(MessageModelSPS *);
};

#endif // DATABASE_H
