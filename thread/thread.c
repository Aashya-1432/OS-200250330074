

#include<stdio.h>
#include<pthread.h>

void *thread(void *arg)
{

    printf("Thread\n");
}

int main()
    {
        pthread_t tid;

        pthread_create(&tid,NULL,thread,NULL);

        sleep(1);
        //pthread_join(thread);

        return 0;
    }
