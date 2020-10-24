
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int a,b,c;
    int fd;
    fd=open("shub",O_RDONLY);
        read(fd,&a,sizeof(a));
        read(fd,&b,sizeof(b));
        printf("receving sender msg accepted 1:%d \n",a);
        printf("receving sender msg accepted 2:%d \n",b);
        close(fd);

    c=a+b;
    printf("2nd procee: %d \n",c);

    int fd1;
    fd1=open("shub",O_WRONLY);
        write(fd,&c,sizeof(c));
        close(fd);




        return 0;





}