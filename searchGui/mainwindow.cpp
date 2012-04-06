#include "mainwindow.h"
#include "ui_mainwindow.h"

 QString strIIndexFile ="/home/tamil/index/iidex.txt";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(LoadFileListToList()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::LoadFileListToList()
{
    QFile fil(strIIndexFile);
    QString sWord = ui->lineEdit->text();
    ui->listWidget->clear();
    if(fil.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       while(!fil.atEnd())
        {
           QString strLine = fil.readLine();
           //Check if it contains the Word
           if(strLine.contains(sWord))
           {
               QStringList strlst = strLine.split(":");
             //  qDebug()<<strlst.at(0);
               QStringList strFList = strlst.at(1).split(";");

               int i = 0;
               foreach(QString tmp,strFList)
               {
                  ui->listWidget->insertItem(i,tmp);
                  i++;

               }
               return true;
           }
       }
    }
    qDebug()<<"Not able to find word";
    return false;
}
