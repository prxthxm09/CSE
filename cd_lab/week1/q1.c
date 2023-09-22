#include <stdio.h>
#include <stdlib.h> int main()
{
FILE *fptr1;
char filename[100],c;
int count =0,count1=0;
printf("Enter the filename to open for reading: \n");
scanf("%s", filename);
fptr1 = fopen(filename, "r");
if (fptr1 == NULL)
{
printf("Cannot open file %s \n", filename);
exit(0);
}

c = fgetc(fptr1);

while (c != EOF)
{
	count1++;
	if(c == '\n') count++;
	c = fgetc(fptr1);

}
printf("\nNumber of lines are:%d  and no. char are :%d\n" , count,count1);
fclose(fptr1);
return 0;
}