// Name: Caitlin Lopez
// Date: October 6, 2022 (Thursday 2:15)
// Title: Lab2 - Step 7
// Description: This program has the child process run the ls command and the
// parent process waits until the child process terminates before exiting

#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */

int main(int argc, char *argv[]){
  pid_t pid;
  int i, n = atoi(argv[1]); //n microseconds to input from keyboard for delay
  printf("\n before forking.\n");
  pid = fork();
  if (pid == -1){
    fprintf(stderr, "forking error %d\n", errno);
  }
  else if (pid == 0){
    execlp("/bin/ls", "ls", NULL);
  }
  else {
    wait(NULL);
    printf("child complete \n");
    exit(0);
  }
  return 0;
}
