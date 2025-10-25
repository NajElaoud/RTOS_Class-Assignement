#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libPIDStatus.h"

void PrintPIDStatus(pid_t pid);
int main(void)
{
  pid_t pid;
  char chaine[5];
  printf("MAIN: PID(%d):", getpid()); PrintPIDStatus(getpid());

  if ((pid = fork()) == -1)
  {
    perror("fork () problem !!!");
    exit(EXIT_FAILURE);
  }if (  ) { //père
    sleep(5);

    // ...
    scanf("%s", chaine)
  }else { //fils
    printf("\nFils : Etat du père :");
   

  //  ...
  }
  exit(EXIT_SUCCESS);
}
