#include "cforwardindex.h"
#include <QMap>
#include <QStringList>
#include <QString>
#include <QDataStream>
#include <QTextStream>
#include <QIODevice>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QRegExp>
#include <iostream>

using namespace std;

//Global declaration
FIndexLst g_FIndexlst;
QMap<QString,QStringList> g_ForwardIndex;


CForwardIndex::CForwardIndex(QString strDirName)
{
    m_dRootDir.setPath(strDirName);
}
QStringList CForwardIndex::GetCurrentFileList()
{
    return m_dRootDir.entryList();
}

QStringList CForwardIndex::GetWordList(QString strFileName)
{
    QStringList wrdlst;
    QFile fil(strFileName);
    if(fil.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        while(!fil.atEnd())
        {
            QString str;
            str = fil.readLine();
            str = str.remove("\n");
            //Split line int words
            QStringList lst =  str.split(QRegExp("\\W+"), QString::SkipEmptyParts);
            for(int i=0; i< lst.size(); i++)
            {
                //check the word is already there and add only if its not there
                if(wrdlst.indexOf(lst.at(i)) == -1)
                {
                    wrdlst.append(lst.at(i));
                }
            }
        }
    }

    return wrdlst;
}

void CForwardIndex::constructIndex()
{
    m_fileList = GetCurrentFileList();

    QString str;
    foreach(str,m_fileList)
    {
        if(str == "." || str == "..")
        {
            ;
        }
        else
        {
            QString fpath = m_dRootDir.absoluteFilePath(str);
            QStringList wrdlst = GetWordList(fpath);
            //Fill into Struct
            ForwardIndex idx;
            idx.sFileName = fpath;
            idx.wordList = wrdlst;
            g_FIndexlst.append(idx);
        }
    }

}

