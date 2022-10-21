# Name: Caitlin Lopez
# Date: October 13, 2022 (Thursday 2:15)
# Title: Lab3 – task 3
# Description: This program has the writer process pass the output of the “ls”
# command to the upstream end of the pipe

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  int fds[2];
  char buff[60];
  int count;
  int i;
  pipe(fds);

  if (fork() == 0){
    printf("\nwriter on the upstream end of the pipe -> %d arguments \n",argc);
    close(fds[0]);
    for(i=0; i<argc; i++){
      dup2(fds[1], 1);
      execlp("ls", "ls", 0);
    }
    exit(0);
  }
  else if(fork() == 0){
    printf("\nreader on the downstream end of the pipe \n");
    close(fds[1]);
    while((count=read(fds[0],buff,60))>0){
      for(i=0;i<count;i++){
        write(1,buff+i,1);
        write(1," ",1);
      }
      printf("\n");
    }
    exit(0);
  }
  else{
    close(fds[0]);
    close(fds[1]);
    wait(0);
    wait(0);
  }
  return 0;
}
