#include <stdio.h>
#include <conio.h>

#define MAX 5
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
	if((front==0 && rear==MAX-1) || ((front==rear && front!=-1)&&(front!=0 && rear!=0)) ||(front==rear+1))
		printf("\n\t\tOVERFLOW!!\n");
	else
	{
		printf("\nEnter number to  be inserted in Queue : ");
		scanf("%d",&num);
		
		if(front==-1 && rear==-1)
		{
			front=0;rear=0;
			queue[rear]=num;
		}
		else if(rear==MAX-1 && front!=0)
		{
			rear=0;
			queue[rear]=num;
		}
		else
		{
			rear++;
			queue[rear]=num;
		}
	}
	
}

int delete_element()
{
	int num;
	if(front==-1)
	{
		printf("\n\t\tUNDERFLOW!!\n");
		return 1;
	}
	num = queue[front];
	if(front==rear)
	{
		front=-1;rear=-1;
	}
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;	
	}
	return num;
}
int peek()
{
	return queue[front];
}
void display()
{
	int i;
	printf("\n***Queue***\n");
	if(front!=-1 && rear!=-1)
	{
		if(rear==0 && front==0)
			printf("\t%d",queue[0]);
		else if(front<rear)
			for (i = front; i <=rear; ++i)
				printf("\t%d",queue[i]);
		else
		{
			for (int i = front; i <= MAX-1; ++i)
				printf("\t%d",queue[i]);
			for (int i = 0; i <= rear; ++i)
				printf("\t%d",queue[i]);
		}
	}
}