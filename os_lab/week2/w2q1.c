#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

void printdir(char *dir)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }

    chdir(dir);
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)) {

            if(strcmp(".",entry->d_name) == 0 ||strcmp("..",entry->d_name) == 0)
                continue;

            //printdir(entry->d_name);
        }
        else {
            int flag;
            printf("%s\n",entry->d_name);
            printf ("Press 0 to delete and 1 to keep: ");
            scanf ("%d", &flag);
            if (flag == 0){
                remove (entry->d_name);
            }
            printf("\n");

        }
    }
    chdir("..");
    closedir(dp);
}


int main () {
    printdir (".");
}