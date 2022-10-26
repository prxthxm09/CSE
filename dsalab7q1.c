#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char string[30];
}Que;

int front=0;
int rear=0;

void init(Que* q,int size)
{
	q=(Que*)calloc(size,sizeof(Que));

}

void enqueue(Que* q,int size)
{
	char str[30];
	if(front==(rear+1)%size)
	{
		printf("QUEUE IS Full\n");
	}
	else
	{
		printf("ENTER THE ELEMENT\n");
		scanf("%s",str);
		rear=(rear+1)%size;
		strcpy(q[rear].string,str);
	}
}
void deque(Que *q,int size)
{
	if(front==rear)
		printf("THE QUEUE IS EMPTY\n");
	else
	{
		char str[30];
		front=(front+1)%size;
		strcpy(str,q[front].string);
		printf("THE STRING DELETED IS \n%s\n",str);
	}
}

void display(Que* q,int size)
{
	if(rear>front){
		for(int i=front+1;i<=rear;i++)
			printf("%s\t",q[i].string);
	}
	else
	{
		for(int i=front+1;i<size;i++)
			printf("%s",q[i].string);
		for(int i=0;i<=rear;i++)
			printf("%s",q[i].string);
	}
}

int main()
{
	Que q;
	int size,op;
	printf("ENTER THE SIZE OF THE QUEUE\n");
	scanf("%d",&size);
	init(&q,size);
	do
	{
		printf("ENTER THE CHOICE 1.INSERT\n 2.DELETE\n 3.DISPLAY \n 4.EXIT\n");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
			enqueue(&q,size);
			break;
			case 2:
			deque(&q,size);
			break;
			case 3:
			display(&q,size);
			break;
			case 4:
			exit(0);
			break;
		}
	}while(op!=4);
}
