#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
typedef struct distance
{
	int kms,meters;
}DISTANCE;

DISTANCE add_distance (DISTANCE,DISTANCE);
DISTANCE sub_distance (DISTANCE,DISTANCE);
int main(int argc, char const *argv[])
{
	DISTANCE d1,d2,d3,d4;
	int op;
	do
	{
		printf("\n***********MAIN MENU************\n");
		printf("1. Read distances\n");
		printf("2. Display distances\n");
		printf("3. Add the distances\n");
		printf("4. subtract distances\n");
		printf("5. EXIT\n");
		printf("\tEnter your choice :: ");
		scanf("%d",&op);
		printf("\n\n");
		switch(op)
		{
			case 1:
				printf("Enter KMS and METERS of first distance : ");
				scanf("%d %d",&d1.kms,&d1.meters);
				printf("Enter KMS and METERS of second distance : ");
				scanf("%d %d",&d2.kms,&d2.meters);
				break;

			case 2:
				printf("KMS and METERS of first distance is :: %d %d \n",d1.kms,d1.meters);
				printf("KMS and METERS of second distance is :: %d %d \n",d2.kms,d2.meters);
				break;
			case 3:
				d3 = add_distance(d1, d2);
				printf("KMS and METERS of  sum of distance is :: %d %d \n",d3.kms,d3.meters);
				break;
			case 4:
				d4 = sub_distance(d1, d2);
				printf("KMS and METERS of  subtraction of distance is :: %d %d \n",d4.kms,d4.meters);
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

DISTANCE add_distance(DISTANCE d1, DISTANCE d2)
{
	DISTANCE sum;
	sum.meters = d1.meters+d2.meters;
	sum.kms = d1.kms+d2.kms;
	while(sum.meters>1000)
	{
		sum.meters=sum.meters%1000;
		sum.kms+=1;
	}
	return sum;
}
DISTANCE sub_distance(DISTANCE d1, DISTANCE d2)
{
	DISTANCE sub;
	if(d1.kms> d2.kms)
	{
		sub.meters = d1.meters - d2.meters;
		sub.kms= d1.kms-d2.kms;
	}
	else
	{
		sub.meters = d2.meters - d1.meters;
		sub.kms= d2.kms - d1.kms;
	}
	
	if(sub.meters<0)
	{
		sub.kms = sub.kms-1;
		sub.meters = sub.meters+1000;
	}
	return sub;
}