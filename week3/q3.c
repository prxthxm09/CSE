#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
int main(){
    int status;
    pid_t piid = getpid();
    pid_t ppid = getppid();
    pid_t pid = fork();
    switch(pid){
    case 0: 
        piid = getpid();
        ppid = getppid();
        printf("Child\n PID : %d\nPPID : %d\n",piid,ppid);
        break;
    case -1:
        printf("Error\n");
        break;
    default:
        piid = getpid();
        ppid = getppid();
        printf("Parent\n PID : %d\nPPID : %d\n",piid,ppid);
        break;
    }
}
