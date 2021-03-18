#ifndef HEADER_H
#define HEADER_H

#include<sys/sem.h>//信号灯
#include<sys/shm.h>//共享内存
#include<sys/wait.h>

#include<unistd.h>


#define BUFFERNUM 10
#define SHMKEY 0x222

//using namespace std;

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO */
};//信号灯集

void P(int semid,int index);
void V(int semid,int index);

#endif // HEADER_H
