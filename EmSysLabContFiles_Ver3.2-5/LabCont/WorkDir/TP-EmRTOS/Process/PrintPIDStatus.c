#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "libPIDStatus.h"

int main(int argc, char** argv)
{
  pid_t pid;
  char* str;

  if(argc<2)
  {
    printf("Missing PID !!");
    exit(-2);
  }

  if(!(isNum(argv[1])))
  {
    printf("Wrong PID !!");
    exit(-1);
  } else {
   pid = strtol(argv[1], &str, 10);
   PrintPIDStatus(pid);
 }
  exit(EXIT_SUCCESS);
}

