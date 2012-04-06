#include <QtCore/QCoreApplication>
#include <QDebug>
#include "cforwardindex.h"
#include "cinvertedindex.h"
#include "globalData.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   CForwardIndex idx("/home/tamil/text/txt");
    idx.constructIndex();
    CForwardIndex idx2("/home/tamil/text/txt2");
    idx2.constructIndex();
    qDebug()<<"Constructed Forward Index";
    g_WriteForwardIndexToFile();
    qDebug()<<"Written Forward Index to File";
    CInvertedIndex iidx;
   // iidx.PrintForwardIndex();
    qDebug()<<"Constructing InvertedIndex ";
    iidx.ConstructInvertedIndex();
    //iidx.PrintInvertedIndex();
    g_WriteInvertedIndexToFile();
    qDebug()<<"WrittenInvertedIndex to File";

    return a.exec();
}
