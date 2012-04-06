#ifndef GLOBALDATA_H
#define GLOBALDATA_H
//Forward Index Structure
#include <QString>
#include <QStringList>
#include <QList>

//Global Config
extern QString strFIndexFile;
extern QString strIIndexFile;

struct ForwardIndex
{
    QString sFileName;
    QStringList wordList;
};
typedef QList<ForwardIndex> FIndexLst;

//Global Index
extern FIndexLst g_FIndexlst;

struct InvertedIndex
{
    QString sWord;
    QStringList fileList;
};

typedef QList<InvertedIndex> IIndexLst;

extern IIndexLst g_IIndexlst;

//Global Functions
void g_WriteForwardIndexToFile();
void g_WriteInvertedIndexToFile();
#endif // GLOBALDATA_H


