
#include<stdio.h>
#include<pthread.h>

pthread_mutex_t count_mutex;
pthread_mutexattr_t count_mutex_attr; //attribute not compulsory

int count=0;

void *i_t(void *arg)
{
    int i;
    for(i=0;i<20;i++)
    {
    pthread_mutex_lock(&count_mutex);
    count++;
    printf("INC : %d \n",count);
    pthread_mutex_unlock(&count_mutex);
    }

}

void *d_t(void *arg)
{
    for(int i=0;i<20;i++)
    {
    pthread_mutex_lock(&count_mutex);
    // pthread_mutex_lock(&count_mutex); you can take two lock then they will be goes int waiting state
    //i.e deadlock condition [recurcive mutex]
    count--;
    printf("DEC : %d \n",count);
    pthread_mutex_unlock(&count_mutex);
    }
        
}

int main()
{
    pthread_t i_tid,d_tid;
pthread_mutexattr_init(&count_mutex_attr); //attribute not compulsory
pthread_mutex_init(&count_mutex,&count_mutex_attr); //count_muter_attr here u not take attr the change DEfault NULL


    pthread_create(&i_tid,NULL,i_t,NULL);
    pthread_create(&d_tid,NULL,d_t,NULL);

    pthread_join(i_tid,NULL);
    pthread_join(d_tid,NULL);
pthread_mutex_destroy(&count_mutex);

    return 0;
}