
#include<stdio.h>
#include<pthread.h>

int count =0;

void *inc_t(void *arg)
{
    while(1)
    {
    count++;
    printf("inc_t=%d \n",count);
    }

}

void *dec_t(void *arg)
{
    while(1)
    {
    count--;
    printf("dec_t=%d \n",count);
    }

}

int main()
{
    pthread_t i_tid,d_tid;

    pthread_create(&i_tid,NULL,inc_t,NULL);
    pthread_create(&d_tid,NULL,dec_t,NULL);


    pthread_join(i_tid,NULL);
    pthread_join(d_tid,NULL);

    return 0;

}
