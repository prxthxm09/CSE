 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex,write1;
int readcount=0;

void* writer(void* param)
{
    for(int i=0;i<10;i++)
    {
        sem_wait(&write1);

        printf("----WRITING----\n");
        sleep(1);

        sem_post(&write1);
    }
}

void* reader(void* param)
{
    for(int i=0;i<10;i++)
    {
        sem_wait(&mutex);
        readcount++;

        if(readcount==1)
            sem_wait(&write1);
        sem_post(&mutex);

        printf("----READING----\n");

        sem_wait(&mutex);
        readcount--;

        if(readcount==0)
            sem_post(&write1);
        sem_post(&mutex);

    }
}

int main()
{
    pthread_t tid1,tid2;
    sem_init(&mutex,0,1);
    sem_init(&write1,0,1);
    pthread_create(&tid1,0,reader,0);
    pthread_create(&tid1,0,writer,0);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}