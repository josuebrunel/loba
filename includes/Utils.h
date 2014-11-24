//  Copyright (c) 2014 godbod
//
//////////////////////////////////////////
///
/// Author : G
/// File   : Utils.h
/// Date   : 2014 Aug 25
/// Brief  : Utils class file
///
//////////////////////////////////////////

#ifndef UTILS_H
#define UTILS_H

#include <QTime>

/// Utils class

class Utils
{
public:
    /// Utils constructor
    Utils();

    /// Utils desctructor
    ~Utils();

    /// getCurrent time utilities
    QTime getCurrentTime() const; 
    /// QString extractor
    QString processMessage(QString);
    /// QString formatLink
    QString formatLink(QString);
};

#endif // UTILS_H
