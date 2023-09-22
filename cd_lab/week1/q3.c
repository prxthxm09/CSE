#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fptr1, *fptr2,*fptr3;
    char filename[100],c1,c2;
    printf("Enter name of file 1 \n");
    scanf("%s",filename);
    fptr1=fopen(filename, "r");
    if(fptr1==NULL){
        printf("Nothing here!");
        exit(0);
    }
    printf("Enter name of file 2 \n");
    scanf("%s",filename);
    fptr2=fopen(filename, "r");
    if(fptr2==NULL){
        printf("Nothing here!");
        exit(0);
    }
    printf("Enter name of file to write in\n");
    scanf("%s",filename);
    fptr3=fopen(filename, "w+");
    c1=fgetc(fptr1);
    c2=fgetc(fptr2);
    int count =1;
    while(c1 != EOF || c2 != EOF)
    {
        c1 = fgetc(fptr1);
        while(c1 != EOF && c1 != '\n')
        {
            fputc(c1,fptr3);
            c1 = fgetc(fptr1);
        }
        if(count == 1)
        {
            fputc(c2,fptr3);
            count = 0;
        }
        c2 = fgetc(fptr2);
        while(c2 != EOF && c2 != '\n')
        {
            fputc(c2,fptr3);
            c2 = fgetc(fptr2);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return 0;
}