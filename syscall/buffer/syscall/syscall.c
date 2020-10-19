
#include<stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
#include <fcntl.h>
 #include <unistd.h>



int main()
{
    int fd;

    fd=open("asp.text",O_WRONLY | O_CREAT); //(you can also creat backgrd side not using O_CREAT flag)
///*
    if(-1== fd)
    {
        perror("Error Occurs:::");
        return -1;
    }
  //*/
    write(fd,"ASHUTOSH",8);
    close(fd);
    return 0 ;
}