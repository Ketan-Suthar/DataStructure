#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
typedef struct complex
{
	int real,imag;
}COMPLEX;

int main(int argc, char const *argv[])
{
	COMPLEX c1,c2,add_c,sub_c;
	int op;
	do
	{
		printf("\n***********MAIN MENU************\n");
		printf("1. Read complex numbers\n");
		printf("2. Display complex numbers\n");
		printf("3. Add complex numbers\n");
		printf("4. subtract complex numbers\n");
		printf("5. EXIT\n");
		printf("\tEnter your choice :: ");
		scanf("%d",&op);
		printf("\n\n");
		switch(op)
		{
			case 1:
				printf("Enter REAL and IMAGINARY parts of first complex number ");
				scanf("%d %d",&c1.real,&c1.imag);
				printf("Enter REAL and IMAGINARY parts of second complex number ");
				scanf("%d %d",&c2.real,&c2.imag);
				break;

			case 2:
				printf("REAL and IMAGINARY parts of first complex number is :: %d %d \n",c1.real,c1.imag);
				printf("REAL and IMAGINARY parts of second complex number is :: %d %d \n",c2.real,c2.imag);
				break;
			case 3:
				add_c.real= c1.real+c2.real;
				add_c.imag= c1.real+c2.imag;
				printf("REAL and IMAGINARY parts of sum of numbers is :: %d %d \n",add_c.real,add_c.imag);
				break;
			case 4:
				sub_c.real= c1.real-c2.real;
				sub_c.imag= c1.real-c2.imag;
				printf("REAL and IMAGINARY parts of subtraction of numbers is :: %d %d \n",sub_c.real,sub_c.imag);
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