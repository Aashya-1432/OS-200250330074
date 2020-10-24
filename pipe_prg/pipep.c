

#include<stdio.h>
#include <unistd.h>


int main()
{
    int a;
    int b;
    int c;

    unsigned char rbuff[143];
   pid_t id;
   int pfd[2];
   int pfd1[2];

   pipe(pfd);
   pipe(pfd1);

      printf("Enter the value 1:");
       scanf("%d",&a);
       printf("Enter the value 2:");
       scanf("%d",&b);

   id = fork();

   if(0==id)
   {
       read(pfd[0],&a,sizeof(a));
       printf("A= %d \n",a);

       read(pfd[0],&b,sizeof(b));
       printf("B= %d \n",b);

       c=a+b;
       printf("Child sum of val=%d \n",c);

        close(pfd[0]);

        write(pfd1[1],&c,sizeof(c));

        close(pfd1[1]);

   }
   else
   {
     
       write(pfd[1],&a,sizeof(a));
        write(pfd[1],&b,sizeof(b));
       close(pfd[1]);

        read(pfd1[0],&c,sizeof(c));
        printf("ACCESS Child to Parent sum:%d \n",c);

        close(pfd1[0]);
   }


    return 0;
}