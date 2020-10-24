
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int a,b,c;

    printf("Enter value1:");
    scanf("%d",&a);
     printf("Enter value2:");
    scanf("%d",&b);

    int fd;
    fd=open("shub",O_WRONLY);
    write(fd,&a,sizeof(a));
    write(fd,&b,sizeof(b));
    close(fd);


    int fd1;
    fd=open("shub",O_RDONLY);
    read(fd,&c,sizeof(c));
    printf("Access 2nd process to 1st process:=%d \n",c);
    close(fd);

    return 0;

}