#include <iostream>
#include <climits>

using namespace std;

typedef struct linkNode
{
	int data;
	struct linkNode *next;
}Node;

void push(Node **head, int value)
{
	Node *newNode = new Node();
	newNode->data = value;
	newNode->next = nullptr;
	if((*head)==nullptr)
	{
		newNode->data = value;
		(*head) = newNode;
	}
	else
	{
		Node *curr = *head;
		while(curr->next != nullptr)
			curr = curr->next;
		curr->next = newNode;
	}
	
}

void printlist(Node *head)
{
	Node *temp = head;
	cout<<"\nlinked list is: ";
	while(temp)
	{
		cout<<temp->data<<" - ";
		temp = temp->next;
	}
}

void check_even_odd_length(Node *start)
{
	Node *p;
	p = start;
	while(1)
	{
		if(p == NULL)
		{
			printf("Even");
			break;
		}
		
		if(p->next == NULL)
		{
			printf("odd");
			break;
		}
		
		p = p->next->next;
	}
	
}

int main(int argc, char const *argv[])
{
	bool temp=1;
	int value;
	Node *list1=nullptr;
	cout<<"\nenter data for list 1: \n";
	while(temp!=0)
	{
		cout<<"\nenter Node value: ";
		cin>>value;
		
		push(&list1,value);

		cout<<"\nwant to add another 1/0 : ";
		cin>>temp;
	}
	
	cout<<"\nlist 1: ";
	printlist(list1);

	cout<<"\nlength of list is: ";
	check_even_odd_length(list1);

	return 0;
}