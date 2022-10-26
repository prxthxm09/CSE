#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 6
typedef struct{
	char s[30];
}queue;

queue q[MAX];

void insertq(int *rear,int *front){
	char str[30];
	if(*front==(*rear+1)%MAX){
		printf("Overflow");
	}
	else{
		*rear=(*rear+1)%MAX;
		printf("Enter the string to be inserted:");
		scanf("%s",str);
		strcpy(q[*rear].s,str);
	}
}
void deleteq(int *rear,int *front){
	char str[30];
	if(*front==0){
		printf("Underflow");
	}
	else{
		strcpy(str,q[*front].s);
		*front+=1;
		printf("Element deleted is:%s",str);
	}
    
}
void display(int *rear,int *front){
	int i;
	for(i=*front+1;i<=*rear;i++)
	{
		printf("%s\n",q[i].s);
	}
}
int main(){
	int rear,front;
	int ch,n;
	rear=0;
	front=0;
	
	do{
		printf("Enter 1 to insert 2 to delete 3 to display:\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: insertq(&rear,&front);
		break;
		case 2: deleteq(&rear,&front);
		break;
		case 3: display(&rear,&front);
		default: break;
	}
}while(ch!=4);
}
