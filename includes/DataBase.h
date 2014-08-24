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
