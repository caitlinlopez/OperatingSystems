// Name: Caitlin Lopez
// Date: October 6, 2022 (Thursday 2:15)
// Title: Lab2 - Step 5
// Description: This program creates 7 processes (including the initial program/parent)
// and single processes cannot create more or less than 2 children. Processes can have
// two children or no children at all.

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();  //child 1
    pid2 = fork();  //child 2 & grandchild 1

    if (pid1 > 0 && pid2 > 0){
        printf("parent id: %d\n", getpid());
    }
    if (pid1 == 0 && pid2 > 0){ //child 1
        printf("child id: %d ; parent id: %d\n", getpid(), getppid());
        pid2 = fork();  //grandchild 2
    }
    if (pid1 > 0 && pid2 == 0){ //child 2
        printf("child id: %d ; parent id: %d\n", getpid(), getppid());
        pid1 = fork();  //grandchild 1
        if (pid1 > 0){  //child 2
            pid2 = fork();  //grandchild 2
            pid1 = 0;
        }
    }
    if (pid1 == 0 && pid2 == 0){
        printf("child id: %d ; parent id: %d\n", getpid(), getppid());
    }
    return 0;
}
