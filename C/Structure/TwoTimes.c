#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
typedef struct time
{
	int min,hrs,sec;
}TIME;

TIME add_time (TIME,TIME);
TIME sub_time (TIME,TIME);
int main(int argc, char const *argv[])
{
	TIME t1,t2,t3;
	int op;
	do
	{
		printf("\n***********MAIN MENU************\n");
		printf("1. Read times\n");
		printf("2. Display times\n");
		printf("3. Add the times\n");
		printf("4. subtract times\n");
		printf("5. EXIT\n");
		printf("\tEnter your choice :: ");
		scanf("%d",&op);
		printf("\n\n");
		switch(op)
		{
			case 1:
				printf("Enter HRS, MIN and SEC of first time : ");
				scanf("%d %d %d",&t1.hrs,&t1.min,&t1.sec);
				printf("Enter HRS, MIN and SEC of second time : ");
				scanf("%d %d %d",&t2.hrs,&t2.min,&t2.sec);
				break;

			case 2:
				printf("HRS, MIN and SEC of first time is :: %dhrs %dmins %dsecs\n",t1.hrs,t1.min,t1.sec);
				printf("HRS, MIN and SEC of second time is :: %dhrs %dmins %dsecs\n",t2.hrs,t2.min,t2.sec);
				break;
			case 3:
				t3 = add_time(t1, t2);
				printf("HRS, MIN and SEC of of  sum of time is :: %dhrs %dmins %dsecs\n",t3.hrs,t3.min,t3.sec);
				break;
			case 4:
				t3 = sub_time(t1, t2);
				printf("HRS, MIN and SEC of of  subtraction of time is :: %dhrs %dmins %dsecs\n",t3.hrs,t3.min,t3.sec);
				break;
			case 5:
				break;
			default:
				printf("Oppps! Wrong Choice\n");
		}
	}while(op!=5);
	printf("******************Thank You**********************\n");
	getch();
	return 1;
}

TIME add_time(TIME t1, TIME t2)
{
	TIME sum;
	sum.sec = t1.sec+t2.sec;
	sum.min = t1.min+ t2.min;
	while(sum.sec>=60)
	{
		sum.sec-=60;
		sum.min+=1;
	}
	
	while(sum.min>=60)
	{
		sum.min-=60;
		sum.hrs+=1;
	}
	sum.hrs = t1.hrs+ t2.hrs;
	return sum;
}
TIME sub_time(TIME t1, TIME t2)
{
	TIME sub;
	if(t1.hrs > t2.hrs)
	{
		if(t1.sec < t2.sec)
		{
			t1.sec += 60;
			t1.min--;
		}
		sub.sec= t1.sec- t2.sec;
		if(t1.min< t2.min)
		{
			t1.min += 60;
			t1.hrs--;
		}
		sub.min = t1.min- t2.min;
		sub.hrs= t1.hrs- t2.hrs;
	}
	else
	{
		if(t2.sec < t1.sec)
		{
			t2.sec += 60;
			t2.min--;
		}
		sub.sec= t2.sec- t1.sec;
		if(t2.min < t1.min)
		{
			t2.min += 60;
			t2.hrs--;
		}
		sub.min = t2.min- t1.min;
		sub.hrs = t2.hrs- t1.hrs;
	}
	
	return sub;
}