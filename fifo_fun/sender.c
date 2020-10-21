///SENDER
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    mkfifo("ipcfifo", S_IRUSR |  S_IWUSR );

    fd=open("ipcfifo", O_WRONLY);
    write(fd,"hyd\n",4);
    close(fd);

    return 0;

}

