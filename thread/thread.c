
#include<stdio.h>
#include<pthread.h>

void *thread(void *arg)
{
    printf("thread\n");
}


int main()
{   
    pthread_t tid;
    printf("Before creation\n");
    pthread_create(&tid,NULL,thread,NULL);
   // printf("After a creation \n");

    //sleep(1);
   // printf("After a sleep creation \n");

    return 0;
}