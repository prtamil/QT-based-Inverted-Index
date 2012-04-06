#include <QFile>
#include <QTextStream>
#include "globalData.h"
#include <iostream>
#include <QDebug>

using namespace std;
// /home/tamil/ProgramsWritten/searchEngine

 QString strFIndexFile="/home/tamil/ProgramsWritten/searchEngine/index.txt";
 QString strIIndexFile ="/home/tamil/ProgramsWritten/searchEngine/iidex.txt";

//Global Functions
void g_WriteForwardIndexToFile()
{
    QFile fil(strFIndexFile);
    QTextStream txt(&fil);
    if(fil.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        ForwardIndex idx;
        foreach(idx,g_FIndexlst)
        {
            txt<<idx.sFileName<<":";
            for(int i =0; i<idx.wordList.size(); i++)
            {
                txt<<idx.wordList.at(i)<<";";
            }
            txt<<"\n";
        }
        txt.flush();
    }
}

void g_WriteInvertedIndexToFile()
{
    QFile fil(strIIndexFile);
    QTextStream txt(&fil);
    if(fil.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        InvertedIndex idx;
        foreach(idx,g_IIndexlst)
        {
            txt<<idx.sWord<<":";
            for(int i =0; i<idx.fileList.size(); i++)
            {
                txt<<idx.fileList.at(i)<<";";
            }
            txt<<"\n";
        }
        txt.flush();
    }
}


