#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    struct stat s;
    int ret, unret;
    if(argc < 3){
        printf("Enter the old and new file name\n");
        return 1;
    }
    ret = symlink(argv[1],argv[2]);
    if (ret)
        perror ("link");
    printf("%s linked to %s\n",argv[1],argv[2]);
    unret = unlink(argv[2]);
    if(unret != 0){
        perror ("unlink");
    }
    printf("%s unlinked\n",argv[2]);
    return 0;
}
