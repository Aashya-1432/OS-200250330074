
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int a,b,sum=0;
sem_t s1,s2;

void *ip_thread(void *data)
{
    while(1)
    {

        sem_wait(&s1);
    printf("T1: newly created \n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf(" \n T1:completed");
        sem_post(&s2);
    }
}

void *processign_thread(void *data)
{
    while(1)
    {
        printf("T@:waiting \n ");
        sem_wait(&s2);
    printf("\n T2:START PROCESSING \n");
    sum=a+b;
    printf("T2 : processing ans =%d",sum);
    printf("\n T2:will be done \n");
        sem_post(&s1);
    }
}


int main()
{
    pthread_t ip_tid,pro_tid;

    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);

    pthread_create(&ip_tid,NULL,ip_thread,NULL);
    pthread_create(&pro_tid,NULL,processign_thread,NULL);

    pthread_join(ip_tid,NULL);
    pthread_join(pro_tid,NULL);
        
    return 0;

}