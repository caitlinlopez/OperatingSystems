# Name: Caitlin Lopez
# Date: October 13, 2022 (Thursday 2:15)
# Title: Lab3 – task 5
# Description: This program implements the producer-consumer message
# communication using pipes.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void producer(FILE *pipe_write_end){
  int i;
  for(i=0; i<10; i++){
    fprintf(pipe_write_end, "%d ", i);
    printf("producer: %d\n", i);
  }
  fclose(pipe_write_end);
  exit(0);
}

void consumer(FILE *pipe_read_end){
  int i;

  while(1){
    int j = fscanf(pipe_read_end, "%d", &i);
    if(j == 1){
      printf("consumer: %d\n", i);
    }
    else{
      break;
    }
  }
  fclose(pipe_read_end);
  exit(0);
}

int main(int argc, char *argv[]){
  int fds[2];
  FILE *pipe_write_end, *pipe_read_end;
  int i;
  pipe(fds);

  pipe_read_end = fdopen(fds[0], "r");
  pipe_write_end = fdopen(fds[1]), "w");

  /* producer, child 1 */
  if(fork() == 0){
    close(fds[0]);
    producer(pipe_write_end);
  }

  /* consumer, child 2 */
  else if(fork() == 0){
    close(fds[1]);
    consumer(pipe_read_end);
  }

  /* ends closed by parent and wait for children */
  else{
    fclose(pipe_read_end);
    fclose(pipe_write_end);
    wait(0);
    wait(0);
  }
  return 0;
}
