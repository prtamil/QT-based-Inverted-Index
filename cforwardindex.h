#ifndef CFORWARDINDEX_H
#define CFORWARDINDEX_H

#include <QDir>
#include <QFile>
#include <QStringList>
#include <QList>
#include "globalData.h"



class CForwardIndex
{
public:
    CForwardIndex(QString strDirName);
    QStringList GetCurrentFileList();
    QStringList GetWordList(QString strFileName);
    void constructIndex();
public:
    QDir m_dRootDir;
    QStringList m_fileList;

};


#endif // CFORWARDINDEX_H
