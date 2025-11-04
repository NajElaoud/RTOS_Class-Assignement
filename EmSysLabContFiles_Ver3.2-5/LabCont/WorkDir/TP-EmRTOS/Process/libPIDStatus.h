#include <ctype.h>
#include <string.h>

void PrintPIDStatus (pid_t pid)
{
  FILE * fp;
  char   StatFilePath[20];
  char   StatMsg[20];
  sprintf(StatFilePath, "/proc/%ld/status", (long) pid);
  if ((fp = fopen(StatFilePath, "r")) == NULL) {
    printf("\t==>Process(%d) Does not exist !", pid);
    return;
  }
  while (fgets(StatMsg, 20, fp) != NULL)
    if (strncmp(StatMsg, "State:", 6) == 0) {
      printf("\t==>Process(%d) : %s\n",pid, StatMsg+7);
      break;
    }
  fclose(fp);
}

int isNum(char* str)
{
    for (int i = 0; str[i]!= '\0'; i++)
        if (isdigit(str[i]) == 0) return 0;
    return 1;
}
