///SENDER
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd=open("ipcfifo", O_WRONLY);
    write(fd,"hyd\n",4);
    close(fd);

    return 0;

}

