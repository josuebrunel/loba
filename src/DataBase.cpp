#include "DataBase.h"

DataBase::DataBase()
{
}

MessageModelSPS* DataBase::LoadDataBaseSPS(MessageModelSPS *modelsps)
{
    modelsps = new MessageModelSPS();

    modelsps->addMessage(Message("Welcome on NetCom 2014"));

    return modelsps;
}
