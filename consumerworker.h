#ifndef CONSUMERWORKER_H
#define CONSUMERWORKER_H

#include <QObject>

class ConsumerWorker : public QObject
{
    Q_OBJECT
public:
    explicit ConsumerWorker(QObject *parent = nullptr);
    explicit ConsumerWorker(QObject *parent,int id,int semid,int shmid);



public:
    void run();
    void doWork();
signals:
    void workStart();
    void workFinished();
private:
    int id;
    int semid;
    int shmid;

};

#endif // CONSUMERWORKER_H
