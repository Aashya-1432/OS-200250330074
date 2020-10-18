#include<stdio.h>
//#include <sys/types.h>
//#include <unistd.h>

#include"fork.h"

int main()
{
     pid_t id;
     //pit_t parent_id;

     printf("Befor fork :  \n"); //incoming coonection web serve lisining 

     id=fork();
     printf("After id\tPID\tPPID:%d %d %d \n",id,getpid(),getppid());
        //in fork child process[0]=clent handling
        //in fork parent process[12623(some id defind)]=list of incomming

     return 0;


}