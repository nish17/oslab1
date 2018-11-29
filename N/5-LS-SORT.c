#include <stdio.h>
#include <unistd.h>
int main()
{

  int a[2];
  pipe(a);

  if (!fork())
  {
    close(1);
    dup(a[1]);
    close(a[0]);
    execlp("ls", "ls", NULL);
  }
  else
  {
    close(0);
    dup(a[0]);
    close(a[1]);
    execlp("sort", "sort", NULL);
  }
}
