#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

char *filterdir;

int filter_dir(const struct dirent *e)
{
    char buf[NAME_MAX];
    struct stat st;

    if (filterdir) {
        snprintf(buf, sizeof(buf), "%s/%s", filterdir, e->d_name);    
        stat(buf, &st);
    } else {    
        stat(e->d_name, &st);
    }
    return (st.st_mode & S_IFDIR);
}


void printdir (char *path)
{
    struct dirent **namelist;
    int n;

    filterdir = path;
    n = scandir(path, &namelist, filter_dir, alphasort);
    filterdir = NULL;

    if (n < 0) {
        perror("scandir");
    } else {
        int i;

        for (i = 0; i < n; i++) {
            if(strcmp(".",namelist[i]->d_name) == 0 ||strcmp("..",namelist[i]->d_name) == 0)
                continue;
            printf("%s\n", namelist[i]->d_name);
            free(namelist[i]);
        }
        free(namelist);
    }
}

int main () {
    printdir("../a");
}

 

 

 

4. 

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