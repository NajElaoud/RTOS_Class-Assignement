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
  int status;
  
  // 1. Le père consulte son propre état
  printf("MAIN: PID(%d) : ", getpid()); 
  PrintPIDStatus(getpid());

  // Le père se clone
  if ((pid = fork()) == -1)
  {
    perror("fork () problem !!!");
    exit(EXIT_FAILURE);
  }
  
  if (pid > 0) { 
    /* ========== PROCESSUS PÈRE ========== */
    // 1. Le père s'endort pendant 5 secondes
    printf("\nPère : sleeping !!\n");
    sleep(5);

    // 3. À son réveil, le père examine l'état du fils AVANT wait
    printf("Père : Etat du fils avant wait(...) : ");
    PrintPIDStatus(pid);
    
    // Le père lit le status de retour du fils
    waitpid(pid, &status, 0);
    
    // 3. Le père examine l'état du fils APRÈS wait
    printf("Père : Etat du fils après wait(...) : ");
    PrintPIDStatus(pid);
    
    printf("\nPère : Je me termine.\n");
    
  } else { 
    /* ========== PROCESSUS FILS ========== */
    // 2. Le fils examine l'état du père (qui dort)
    printf("Fils : Etat du père : ");
    PrintPIDStatus(getppid());
    
    // 2. Le fils se termine immédiatement
    printf("Fils : Je me termine.\n");
    exit(EXIT_SUCCESS);
  }
  
  exit(EXIT_SUCCESS);
}
