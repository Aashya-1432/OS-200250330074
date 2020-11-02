
#include<stdio.h>
#include<pthread.h>

int a,b,sum=0;

void *ip_thread(void *data)
{
    while(1)
    {
    printf("T1: 1st created");
    scanf("%d ",&a);
    scanf("%d ",&b);
    printf("T1:completed");
    }
}

void *processign_thread(void *data)
{
    while(1)
    {
    sum=a+b;
    printf("T2:START PROCESSING");
    printf("T2 : processing ans =%d \n",sum);
    printf("T2:will be done ");
    }
}


int main()
{
    pthread_t ip_tid,pro_tid;

    pthread_create(&ip_tid,NULL,ip_thread,NULL);
    pthread_create(&pro_tid,NULL,processign_thread,NULL);

    pthread_join(ip_tid,NULL);
    pthread_join(pro_tid,NULL);
        
    return 0;

}