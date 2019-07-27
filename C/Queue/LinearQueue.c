#include <stdio.h>
#include <conio.h>

#define MAX 10
int front=-1,rear=-1;
int queue[MAX];

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
	int op,value;

	do
	{
		printf("\n***********MAIN MENU************\n");
		printf("1. Inert Element\n");
		printf("2. Delete Element\n");
		printf("3. Peek\n");
		printf("4. Diplay The Queue\n");
		printf("5. EXIT\n");
		printf("\tEnter your choice :: ");
		scanf("%d",&op);
		printf("\n\n");
		switch(op)
		{
			case 1:
					insert();
					break;
			case 2:
					value= delete_element();
					printf("\nElement Deleted Is :: %d",value);
					break;
			case 3:
					value=peek();
					printf("\nFirst value in Queue is :: %d",value);
					break;
			case 4:
					display();
					break;
		}
	}while(op!=5);

	getch();
	return 0;
}

void insert()
{
	int num;
	printf("\nEnter number to  be inserted in Queue : ");
	scanf("%d",&num);
	if(rear==MAX-1)
		printf("\nOVERFLOW!!");
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
	}
	else
		rear++;
	queue[rear]=num;
}

int delete_element()
{
	int val;
	if(front==-1 || front>rear)
	{
		printf("\nUNDERFLOW!!");
		return 1;
	}
	else
	{
		val=queue[front];
		front++;
		return val;
	}
}

int peek()
{
	return queue[front];
}

void display()
{
	int i;
	printf("\n***QUEUE***\n");
	for(i=front;i<=rear;++i)
		printf("\t%d",queue[i]);
}