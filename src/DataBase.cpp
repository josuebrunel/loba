#include "DataBase.h"

DataBase::DataBase()
{
}

MessageModelSPS* DataBase::LoadDataBaseSPS(MessageModelSPS *modelsps)
{
    modelsps = new MessageModelSPS();

    modelsps->addMessage(Message("Welcome on NetCOM¹ 2014"));

    return modelsps;
}
