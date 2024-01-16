
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
        execlp("./q1","q1",NULL);
        break;
    case -1:
        printf("Error\n");
        break;
    default:
        wait(NULL);
        printf("Child completed\n");
        //printf("Child returned: %d\n",status);
        break;
    }
}
