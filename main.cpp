#include "mainwindow.h"
#include "consumerworker.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "header.h"
#include <QApplication>
#include <QThread>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_X11InitThreads, true);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int semid;
    semid = semget(IPC_PRIVATE, 3, IPC_CREAT | 0666);//创建三个信号灯.
    union semun wp; // write process's size
    union semun rp;  // read process's size
    union semun mutex;  // read/write mutex signal
    wp.val = BUFFERNUM;
    rp.val = 0;
    mutex.val = 1;
    if (semctl(semid, 0, SETVAL, wp) == -1 ||
        semctl(semid, 1, SETVAL, rp) == -1 ||
        semctl(semid, 2, SETVAL, mutex)  == -1) {
        perror("IPC error 1: semctl");
        exit(1);
    }

    int shmid;
    if((shmid=shmget(SHMKEY, BUFFERNUM, IPC_CREAT | 0666)) < 0){
        return  -1;
    }

    int pid1,pid2,pid3;

    if ((pid1=fork())==0){

        ConsumerWorker *worker=new ConsumerWorker(nullptr,pid1,semid,shmid);
        QTimer *timer=new QTimer(worker);
        QObject::connect(timer,&QTimer::timeout,worker,&ConsumerWorker::doWork);
        timer->start(1000);

//        return a.exec();
    }

    return a.exec();
}
