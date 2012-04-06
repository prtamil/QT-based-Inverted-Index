#include "cinvertedindex.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
using namespace std;

IIndexLst g_IIndexlst;

CInvertedIndex::CInvertedIndex()
{
}

void CInvertedIndex::PrintForwardIndex()
{
    for(int i =0; i< g_FIndexlst.size();i++)
    {
        QString st = g_FIndexlst.at(i).sFileName;
        cout<<st.toStdString();
        for(int j = 0; j<g_FIndexlst.at(i).wordList.size(); j++)
        {
            QString wrd = g_FIndexlst.at(i).wordList.at(j);
            cout<<wrd.toStdString();
        }
        cout<<endl;
    }

    cout.flush();
}

void CInvertedIndex::ConstructInvertedIndex()
{
    FIndexLst tmpRef = g_FIndexlst;
    for(int i=0; i<tmpRef.size(); i++)
    {
        ForwardIndex idx = tmpRef.at(i);
        for(int j = 0; j < idx.wordList.size();j++)
        {
            QString wrd = idx.wordList.at(j);
            QStringList filList = searchWordinFiles(wrd);
            InvertedIndex idx;
            idx.fileList = filList;
            idx.sWord = wrd;
            if(!checkWordinInvertedList(wrd))
            {
                g_IIndexlst.append(idx);
            }
        }
    }
}

bool CInvertedIndex::checkWordinInvertedList(QString word)
{
    for(int i =0; i < g_IIndexlst.size();i++)
    {
        if(g_IIndexlst.at(i).sWord == word)
        {
            return true;
        }
    }
    return false;
}

QStringList CInvertedIndex::searchWordinFiles(QString word)
{
    QStringList fileList;
    for(int i =0; i< g_FIndexlst.size(); i++)
    {
        if(g_FIndexlst.at(i).wordList.indexOf(word)!= -1)
        {
            if(fileList.indexOf(g_FIndexlst.at(i).sFileName) == -1)
            {
                fileList.append(g_FIndexlst.at(i).sFileName);
            }
        }
    }
    return fileList;
}


void CInvertedIndex::PrintInvertedIndex()
{
    for(int i =0; i< g_IIndexlst.size();i++)
    {
        QString st = g_IIndexlst.at(i).sWord;
        cout<<st.toStdString();
        for(int j = 0; j<g_IIndexlst.at(i).fileList.size(); j++)
        {
            QString wrd = g_IIndexlst.at(i).fileList.at(j);
            cout<<wrd.toStdString();
        }
        cout<<endl;
    }

    cout.flush();

}

