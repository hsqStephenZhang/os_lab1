#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "consumerworker.h"
#include "header.h"
#include <QThread>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    char buffer[BUFFERNUM]={0};

//    else{
//        if ((pid2=fork())==0){
//            QThread *thread=new QThread();
//            ConsumerWorker *worker=new ConsumerWorker(nullptr,pid2,semid,shmid);
//            worker->moveToThread(thread);

//            connect(thread,&QThread::started,worker,&ConsumerWorker::run);
//            connect(thread,&QThread::finished,&ConsumerWorker::deleteLater);
//            connect(worker,&ConsumerWorker::workFinished,thread,&QThread::quit);
//            connect(worker,&ConsumerWorker::workFinished,thread,&QThread::deleteLater);

//            thread->start();
//            return ;
//        }else{
//            if ((pid3=fork())==0){
//                QThread *thread=new QThread();
//                ConsumerWorker *worker=new ConsumerWorker(nullptr,pid3,semid,shmid);
//                worker->moveToThread(thread);

//                connect(thread,&QThread::started,worker,&ConsumerWorker::run);
//                connect(thread,&QThread::finished,&ConsumerWorker::deleteLater);
//                connect(worker,&ConsumerWorker::workFinished,thread,&QThread::quit);
//                connect(worker,&ConsumerWorker::workFinished,thread,&QThread::deleteLater);

//                thread->start();
//                return ;
//            }
//        }
//    }




//    QThread *thread=new QThread();
//    ConsumerWorker *worker=new ConsumerWorker(nullptr);
//    worker->moveToThread(thread);

//    connect(thread,&QThread::started,worker,&ConsumerWorker::run);
//    connect(thread,&QThread::finished,&ConsumerWorker::deleteLater);
//    connect(worker,&ConsumerWorker::workFinished,thread,&QThread::quit);
//    connect(worker,&ConsumerWorker::workFinished,thread,&QThread::deleteLater);

//    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

