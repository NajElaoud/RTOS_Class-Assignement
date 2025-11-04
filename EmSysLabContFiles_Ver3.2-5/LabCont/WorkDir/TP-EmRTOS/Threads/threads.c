#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "libThAttr.h"

#define         C    100000000ul
#define         MSG_Nbr    10
#define         TH_Nbr     10
pthread_t       ThList[TH_Nbr];
pthread_attr_t  ThAttr;

static void display_pthread_attr(pthread_attr_t* , char*);
void * tsr(void *);

int main() {
  int err;
  void *ThStatus[TH_Nbr];

  //display_pthread_attr(&ThAttr, "Void-Attr :");
  err = pthread_attr_init(&ThAttr);
  if (err) {
    printf("!! pthread_attr_init error !!\n");
    exit(EXIT_FAILURE);
  }
  display_pthread_attr(&ThAttr, "Default-Attr :");
  
  unsigned char i;
  for(i=0;i<TH_Nbr;i++){
    err = pthread_create(&ThList[i], &ThAttr, (void *)tsr,(void *)(long)i+1);
    if (err) {
      printf("!! pthread_create error !! \n");
      exit (EXIT_FAILURE);
    }
  }

  printf("MAIN : PID= %d, TID= %lu\n", getpid(), pthread_self());
  printf("MAIN : J'ai cree les threads de TID [%lu ..%lu]\n", ThList[0], ThList[TH_Nbr-1]);

  // Make thread 5 (index 4) DETACHED
  err = pthread_detach(ThList[4]);
  if (err) {
    printf("!! pthread_detach error for thread 5 !!\n");
    exit(EXIT_FAILURE);
  }
  
  // Get and display attributes of thread 5 
  pthread_attr_t Tattr;
  err = pthread_attr_init(&Tattr);
  if (err) {
    printf("!! pthread_attr_init error for Tattr !!\n");
    exit(EXIT_FAILURE);
  }

  err = pthread_getattr_np(ThList[4], &Tattr);
  if (err) {
    printf("!! pthread_getattr_np error for thread 5 !!\n");
    exit(EXIT_FAILURE);
  }
  
  display_pthread_attr(&Tattr, "Thr N°5 Attr :");
  pthread_attr_destroy(&Tattr);

  for(i=0;i<MSG_Nbr;i++){
    printf("%d-MAIN process\n",i);
    int j,k; for(j=0;j<C;j++){;} 
  }

   for(i=0;i<TH_Nbr;i++){
     printf("MAIN : synchronisation sur la fin du Thread N°:%u (TID %lu) \n",\
            i+1, ThList[i]);
     err = pthread_join(ThList[i], &ThStatus[i]);
     if (err) {
       //printf("\t !! thread N°%u : pthread_join error !!\n", i+1);
       printf("\t !! pthread_join error <== Thread N°%u !!\n", i+1);
        //exit (EXIT_FAILURE);
       continue;
     }
     printf("\t==> status : %lu\n",(unsigned long) ThStatus[i]);
   }
  return 0;
}

void * tsr(void * Arg) {
  uint My_Nbr= (uint)(long) Arg;

  printf("je suis le thread N°%u. \n\tMon pid est %u. \n\tMon tid est %lu\n", \
         My_Nbr, getpid(), pthread_self());
  int i;  for(i=0;i<MSG_Nbr;i++){
    printf("\t%d-Thread N°%u\n", i, My_Nbr);
    for(unsigned long j=0;j<C;j++){;}
  }
  pthread_exit((void *)(long)(My_Nbr+100));
}
