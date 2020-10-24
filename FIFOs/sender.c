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


//in FIFOs u can 1st create file .txt using cmd ---- [ mkfifo -m0600 <name of file>]
