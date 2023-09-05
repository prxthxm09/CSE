#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
int main(){
    int status;
    pid_t pid = fork();
    switch(pid){
    case 0: 
        printf("Child process\n");
        break;
    case -1:
        printf("Error\n");
        break;
    default:
        wait(&status);
        printf("I'm the parent\n");
        printf("Child returned: %d\n",status);
        break;
    }
}
