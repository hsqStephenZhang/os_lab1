#include "providerworker.h"
#include "header.h"
#include <QDebug>

ProviderWorker::ProviderWorker(QObject *parent):QObject(parent){

}

ProviderWorker::ProviderWorker(QObject *parent,int id,int semid,int shmid) : QObject(parent),id(id),semid(semid),shmid(shmid)
{

}


void ProviderWorker::run()
{
    emit workStart();
    doWork();
}
void ProviderWorker::doWork()
{

    char* s=(char*)shmat(this->shmid,0,0);
    int in=0;
    while(1){
        fflush(stdout);
        P(semid,0);
        *(s+in)='0'+in;
        qDebug()<<"write---->"<<*(s+in)<<"\n";
        in=(in+1)%BUFFERNUM;
        V(semid,1);
        sleep(1);
    }
    if (shmdt(shmat(shmid, 0, 0))==-1){
        qDebug()<<"delete failed";
    }
    emit workFinished();
}
