

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int buf[10],f,r;
sem_t mutex,full,empty;

void* producer(void* param)
{
    int num;
    for(int i=1;i<=10;i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("produced item is %d\n",i);
        buf[(r++)%10]=i;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
        sem_getvalue(&full,&num);
        printf("Full %d\n",num);
    }
    
}

void* consumer(void* param)
{
    int item,num;
    for(int i=1;i<=10;i++)
    {
        sem_wait(&full);
        sem_getvalue(&full,&num);
        printf("\nFull %d\n",num);

        sem_wait(&mutex);
        item=buf[(f++)%10];

        printf("consumed item is %d\n",item);
        sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
        
    }
    
}

int main()
{
    pthread_t tid1,tid2;
    sem_init(&mutex,0,1);
    sem_init(&empty,0,10);
    sem_init(&full,0,1);
    pthread_create(&tid1,0,producer,0);
    pthread_create(&tid1,0,consumer,0);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}
