
#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>

sem_t count_sem;
int count =0;

void *inc_t(void *arg)
{
    while(1)
    {
    sem_wait(&count_sem);
    count++;
    printf("inc_t=%d \n",count);
    sem_post(&count_sem);
    }

}

void *dec_t(void *arg)
{
    while(1)
    {
    sem_wait(&count_sem);
    count--;
    printf("dec_t=%d \n",count);
    sem_post(&count_sem);
    }

}

int main()
{
    pthread_t i_tid,d_tid;
sem_init(&count_sem,0,1);
    pthread_create(&i_tid,NULL,inc_t,NULL);
    pthread_create(&d_tid,NULL,dec_t,NULL);


    pthread_join(i_tid,NULL);
    pthread_join(d_tid,NULL);
sem_destroy(&count_sem);
    return 0;

}
