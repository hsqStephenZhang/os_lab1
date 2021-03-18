#ifndef PROVIDERWORKER_H
#define PROVIDERWORKER_H

#include <QObject>
#include "header.h"

class ProviderWorker : public QObject
{
    Q_OBJECT
public:
    explicit ProviderWorker(QObject *parent = nullptr);
    explicit ProviderWorker(QObject *parent,int id,int semid,int shmid);

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

#endif // PROVIDERWORKER_H
