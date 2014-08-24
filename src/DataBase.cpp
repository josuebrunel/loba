#include "DataBase.h"

DataBase::DataBase()
{
}

MessageModelSPS* DataBase::LoadDataBaseSPS(MessageModelSPS *modelsps)
{
    modelsps = new MessageModelSPS();

    modelsps->addMessage(Message(""));

    return modelsps;
}
