#ifndef CINVERTEDINDEX_H
#define CINVERTEDINDEX_H

#include "globalData.h"


class CInvertedIndex
{
public:
    CInvertedIndex();
    void PrintForwardIndex();
    void PrintInvertedIndex();
    void ConstructInvertedIndex();
    QStringList searchWordinFiles(QString word);
    bool checkWordinInvertedList(QString word);

};

#endif // CINVERTEDINDEX_H
