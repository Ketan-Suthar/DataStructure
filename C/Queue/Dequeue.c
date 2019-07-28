#include <stdio.h>
#include <conio.h>

#define MAX 5
int left=-1,right=-1;
int dequeue[MAX];

void input_dequeue(void);
void ouptu_dequeue(void);
void insert_left(void);
void insert_right(void);
int delete_left(void);
int delete_right(void);
void display(void);


int main(int argc, char const *argv[])
{
	int op;

	printf("\n***********MAIN MENU************\n");
		printf("1. Input restricted queue\n");
		printf("2. output restricted queue\n");
		printf("\tEnter your choice :: ");
		scanf("%d",&op);
		printf("\n\n");
		switch(op)
		{
			case 1:
					input_dequeue();
					break;
			case 2:
					ouptu_dequeue();
					break;
			default:
				printf("\nWrong choice!!");
		}
	getch();
	return 0;
}

void input_dequeue()
{
	int op;
	do
	{
		printf("\n***********input_dequeue MENU************\n");
		printf("1. insert at right\n");
		printf("2. delete from left\n");
		printf("3. delete from right\n");
		printf("4. display\n");
		printf("5. EXIT\n");
		printf("\tEnter your choice :: ");
		scanf("%d",&op);
		printf("\n\n");
		switch(op)
		{
			case 1:
				insert_right();
				break;
			case 2:
				delete_left();
				break;
			case 3:
				delete_right();
				break;
			case 4:
				display();
				break;	
		}
	}while(op!=5);

}

void ouptu_dequeue()
{
	int op;
	do
	{
		printf("\n***********ouptu_dequeue MENU************\n");
		printf("1. insert at right\n");
		printf("2. insert from left\n");
		printf("3. delete from left\n");
		printf("4. display\n");
		printf("5. EXIT\n");
		printf("\tEnter your choice :: ");
		scanf("%d",&op);
		printf("\n\n");
		switch(op)
		{
			case 1:
				insert_right();
				break;
			case 2:
				insert_left();
				break;
			case 3:
				delete_left();
				break;
			case 4:
				display();
				break;	
		}
	}while(op!=5);

}

void insert_right()
{
	int num;
	//((left==right && left!=-1)&&(left!=0 && right!=0)) ||
	if((left==0 && right==MAX-1) || (left==right+1))
	{
		printf("\n\t\tOVERFLOW!!\n");
		return;
	}
	printf("\nEnter number to  be inserted in Deueue : ");
		scanf("%d",&num);
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(right==MAX-1)
			right=0;
		else
			right+=1;
	}
	dequeue[right]=num;
}

void insert_left()
{
	int num;
	//((left==right && left!=-1)&&(left!=0 && right!=0)) ||
	if((left==0 && right==MAX-1) || (left==right+1))
	{
		printf("\n\t\tOVERFLOW!!\n");
		return;
	}
	printf("\nEnter number to  be inserted in Deueue : ");
		scanf("%d",&num);
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(left==0)
			right=MAX-1;
		else
			left-=1;
	}
	dequeue[left]=num;
}

void delete_left()
{
	if(left==-1)
	{
		printf("\n\t\tUNDERFLOW!!\n");
		return;
	}
	printf("\nElement Deleted Is :: %d",dequeue[left]);
	if(left==right)
	{
		left=-1;right=-1;
	}
	else
	{
		if(left==MAX-1)
			left=0;
		else
			left+=1;
	}
}

void delete_right()
{
	if(left==-1)
	{
		printf("\n\t\tUNDERFLOW!!\n");
		return;
	}
	printf("\nElement Deleted Is :: %d",dequeue[right]);
	if(left==right)
	{
		left=-1;right=-1;
	}
	else
	{
		if (right==0)
			right=MAX-1;
		else
			right-=1;
	}
}

void display()
{
	int front=left,rear=right;
	if(left=-1)
	{
		printf("\n----Dequeue Is Empty----");
		return;
	}
	printf("\n***Deueue***\n");
	if(front<=rear)
		while(front<=rear)
		{
			printf("\t%d",dequeue[front]);
			++front;
		}
	else
	{
		while(front<=MAX-1)
		{
			printf("\t%d",dequeue[front]);
			++front;
		}
		front=0;
		while(front<=rear)
		{
			printf("\t%d",dequeue[front]);
			++front;
		}
	}	
}