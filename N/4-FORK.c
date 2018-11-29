#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int pid, pid1, pid2;

  pid = fork();

  if (pid == 0)
  {

    sleep(3);

    printf("child[1] --> pid = %d and ppid = %d\n", getpid(), getppid());
    execlp("./2.o", "./2.o", "NULL");
  }

  else
  {
    pid1 = fork();
    if (pid1 == 0)
    {
      sleep(2);
      printf("child[2] --> pid = %d and ppid = %d\n", getpid(), getppid());
      execlp("./3.o", "./3.o", "NULL");
    }
    else
    {
      pid2 = fork();
      if (pid2 == 0)
      {

        printf("child[3] --> pid = %d and ppid = %d\n", getpid(), getppid());
        execlp("./4.o", "./4.o", "NULL");
      }

      else
      {

        sleep(3);
        printf("parent --> pid = %d\n", getpid());
      }
    }
  }

  return 0;
}