#include "headerFiles.h"

#define MAX_SIZE 120

int main()
{
    int fd[2];
    char message[MAX_SIZE];

    pipe(fd);

    if(fork() == 0)
    {
      //Child process
      printf("In child process\n");
      close(fd[0]);
      printf("Enter a message: ");
      gets(message);
      write(fd[1], message, strlen(message));
    }
    else
    {
      //Parent Process
      printf("In parent process\n");
      close(fd[1]);
      read(fd[0], message, sizeof(message));
      printf("Message entered - %s\n", message);
   }
   return 0;
}
