#include<stdio.h>
#include<stdlib.h>
int main()
		{
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen("q1in.c", "r");
	if (fa == NULL){
	printf("Cannot open file \n");
	exit(0); 
		}
	fb = fopen("q1out.c", "w");
	while (ca != EOF)
		{	
			ca = getc(fa);
			if(ca==' '|| ca=='\t' )
			{
				while(ca==' '|| ca=='\t')
				{
					ca = getc(fa);
				}
				putc(' ',fb);
				putc(ca,fb);
				ca = getc(fa);
			}
			else 
			{
				putc(ca,fb);
				ca=getc(fa);
			}
			}
fclose(fb);
fclose(fa);
return 0;
}