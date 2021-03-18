#include "header.h"

void P(int semid,int index){
    struct sembuf sem{};
    sem.sem_num=index;
    sem.sem_op=-1;
    sem.sem_flg=0;
    semop(semid,&sem,1);
}

void V(int semid,int index){
    struct sembuf sem{};
    sem.sem_num=index;
    sem.sem_op=1;
    sem.sem_flg=0;
    semop(semid,&sem,1);
}
