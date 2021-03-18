#include "consumerworker.h"
#include <QDebug>
#include "header.h"

ConsumerWorker::ConsumerWorker(QObject *parent) : QObject(parent)
{

}


ConsumerWorker::ConsumerWorker(QObject *parent,int id,int semid,int shmid) : QObject(parent),id(id),semid(semid),shmid(shmid)
{

}


void ConsumerWorker::run()
{
    emit workStart();
    doWork();
}
void ConsumerWorker::doWork()
{
    qDebug()<<"start";
    char* s=(char*)shmat(this->shmid,0,0);
    int out=0;
    while(1){
        qDebug()<<"pid"<<this->id<<" read";
        P(semid,1);
        P(semid,2);
        qDebug()<<"-->"<<*(s+out)<<"\n";
        out=(out+1)%BUFFERNUM;
        V(semid,2);
        V(semid,0);
        sleep(1);
    }
    if (shmdt(shmat(shmid, 0, 0))==-1){
        qDebug()<<"delete failed";
    }
    emit workFinished();
}
