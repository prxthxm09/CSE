#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

int main(int argc, char const *argv[]){
if(argc < 2){
printf("Incorrect number of arguments, Expected 1, Got: %d", argc-1);
return 0;
}
struct stat file_stat;
int return_value = stat(argv[1], &file_stat);
if(return_value != 0){
perror("stat");
return 1;
}
printf("File: %s\nInode: %ld\nDevice Container ID: %ld\nMode: %10.10s\nHard Links:
%ld\nUser ID: %d\nGroup ID: %d\nDevice ID: %ld\nTotal Size: %ld\nBlock Size: %ld\nNumber
of blocks: %ld\nLast Access Time: %sLast Modified: %sLast Status: %s", argv[1], file_stat.st_ino,
file_stat.st_dev, file_stat.st_nlink, file_stat.st_uid, file_stat.st_gid,
file_stat.st_rdev, file_stat.st_size, file_stat.st_blksize, file_stat.st_blocks, ctime(&file_stat.st_atime),
ctime(&file_stat.st_mtime), ctime(&file_stat.st_ctime));
return 0;
}
