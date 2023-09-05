#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fptr1,*fptr2;
	char filename[100], c;
	printf("Enter the filename to open for reading: \n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	
	if (fptr1 == NULL)
		{
			printf("Cannot open file %s \n", filename);
			exit(0);
		}
	printf("Enter the filename to open for reversing: \n");
	scanf("%s", filename);
	fptr2 = fopen(filename, "w+");
	
	fseek(fptr1, 0, SEEK_END);
	int fsiz=ftell(fptr1);
	printf("The size of file is:%d\n",fsiz);
	int end=fsiz-1;
	while(end>=0)
	{	fseek(fptr1,end,SEEK_SET);
		c=fgetc(fptr1);
		fputc(c,fptr2);
		end--;
	}
	fclose(fptr1);
	fclose(fptr2);

}
