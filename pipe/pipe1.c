
#include<stdio.h>
 #include <unistd.h>


int main()
{
    unsigned char rbuff[143];
    pid_t id;
    int pfd[2];
    pipe(pfd);

    id=fork();


    if(0==id)
    {
        read(pfd[0],rbuff,143);
        printf("Child = %s \n",rbuff);
        close(pfd[0]);

    }
    else
    {
        write(pfd[1],"Shubhi",6);
        close(pfd[1]);

    }

    return 0;

}