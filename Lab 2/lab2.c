// Name: Caitlin Lopez
// Date: October 6, 2022 (Thursday 2:15)
// Title: Lab2 - Steps 1-4
// Description: This program creates children using two processes.

#include <stdio.h>      /*printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]){
    pid_t pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n before forking. \n");
    pid = fork();
    if (pid == -1){
        //parent process
        for (i = 0; i < 100; i++){
            print("\t \t \t parent process %d \n", i);
            usleep(n);
        }
    }
    else {
        //child process
        for (i = 0; i < 100; i++){
            printf("child process %d\n", i);
            usleep(n);
        }
    }
    return 0;
}
