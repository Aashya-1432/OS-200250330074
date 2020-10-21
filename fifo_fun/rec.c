//RECEVER
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
  #include <sys/types.h>
       #include <sys/stat.h>


int main()
{
    unsigned char rbuff[99];
    int fd;
    mkfifo("ipcfifo", S_IRUSR |  S_IWUSR );
    fd=open("ipcfifo",O_RDONLY);
        read(fd,rbuff,99);
        printf("receving sender msg accepted :%s \n",rbuff);
        close(fd);

    return 0;
    
}

