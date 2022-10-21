// Name: Caitlin Lopez
// Date: October 6, 2022 (Thursday 2:15)
// Title: Lab2 - Step 6
// Description: This program creates children using two threads.

#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <pthread.h>

void *printThread(void *threadID){
  int i;
  for(i = 0; i < 100; i++){
    printf("thread %d \n", i);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  pthread_t threads[2];

  int thread;
  int i;

  for(i = 0; i < 2; i++){
    pthread_create(&threads[i], NULL, printThread, NULL);
  }
  for(i = 0; i < 2; i++){
    pthread_join(threads[i], NULL);
  }

  pthread_exit(NULL);
  return 0;
}
