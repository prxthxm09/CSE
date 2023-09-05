#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fa, *fb;
    int ca, cb;
    int flag = 1;
    fa = fopen("q1.c", "r");
    if (fa == NULL){
        printf("Cannot open file \n");
        exit(0); 
    }
    fb = fopen("te1.c", "w");
    ca = getc(fa);
    while (ca != EOF)
    {
        if(ca == '"'){
            putc(ca,fb);
            ca = getc(fa);
            while(ca != '"'){
                putc(ca,fb);
                ca = getc(fa);
            }
            putc(ca,fb);
            ca = getc(fa);
        }
        if (ca=='/')
        {
            ca = getc(fa);
            if (ca == '/')
            {
            while(ca != '\n')
            ca = getc(fa);
            }
            else if (ca == '*')
            {
                do
                {
                    while(ca != '*')
                    {
                        ca = getc(fa);
                    }
                    ca = getc(fa);
                } while (ca != '/');
            }
        }
        else if (ca == '#'){
                while(ca != '\n'){
                    ca = getc(fa);
                }
                putc('\n',fb);
                ca = getc(fa);
            }
            else
            {
                putc(ca,fb);
                ca = getc(fa);
            }
    }
    fclose(fa);
    fclose(fb);
    return 0;
}
