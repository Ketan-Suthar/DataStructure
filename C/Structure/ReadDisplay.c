#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
typedef struct student
{
	int roll_no;
	float fees;
	char name[80];
	char DOB[80];
}STUDENT;

int main(int argc, char const *argv[])
{
	STUDENT std1;
	
	printf("Enter roll_no :: ");
	scanf("%d",&std1.roll_no);

	printf("\nEnter name :: ");
	scanf("%s",std1.name);

	printf("\nEnter fees :: ");
	scanf("%f",&std1.fees);

	printf("\nEnter DOB :: ");
	scanf("%s",std1.DOB);

	printf("**********STUDENT DETAILS******************\n");
	printf("\tName :: %s\n",std1.name);
	printf("\troll_no :: %d\n",std1.roll_no);
	printf("\tfees :: %f\n",std1.fees);
	printf("\tDOB :: %s\n",std1.DOB);
	getch();
	return 1;
}