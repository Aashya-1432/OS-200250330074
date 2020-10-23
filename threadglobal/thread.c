
#include<stdio.h>
#include<pthread.h>

int a=10;
int b;

int add(int a,int b)
{
    return (a+b);
}

void *thread(void *arg){
    //add(30,100);   //in that show error bcoz stack  is not shared bet thread

    // Every process will get own stack . 
    printf("a=%d",a);
    b=4;
    printf("b=%d",b);
    printf("Thread\n");
}

int main()
{
    printf("a=%d",a);
    b=4;
    printf("b=%d",b);
//    add(40,50); //in that show error bcoz stack  is not shared bet thread

    pthread_t tid;

    pthread_create(&tid,NULL,thread,NULL);

    sleep(1);

    return 0;

}