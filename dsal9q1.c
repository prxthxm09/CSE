#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct node{
	int data;
	struct node* next;
}*head=NULL;
struct node *rear=NULL,*front=NULL;
void create(){
	struct node *temp,*newnode;
	static int count=1;
	if(count<=MAX){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(front==NULL){
		front=newnode;
	}
	else{
		temp=front;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
		rear=newnode;
	}
	count++;}
	else{
		printf("Queue is full\n");
	}
}
void delete(){
	struct node *temp;
	temp=front;
	front=front->next;
	if(front==rear)
		printf("Queue is empty\n");
	else{
		free(temp);
	}
}
void display(){
	struct node *temp;
	temp=front;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}printf("\n");
}
int main(){
	int ch;
	do{
		printf("Enter 1.Enter an element 2.Delete an element 3.Display 4.Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			create();
			break;
			case 2:
			delete();
			break;
			case 3:
			display();
			break;
			case 4:
			exit(0);
			break;
		}
	}while(ch!=4);
}