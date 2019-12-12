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
void mergeTwoSortedLinkedList(Node **list1, Node **list2, Node **newlist)
{
	Node *ptr1 = *list1, *ptr2= *list2, *curr = nullptr;

	if(ptr1 == nullptr)
	{
		*newlist = ptr2;
		return;
	}
	if(ptr2 == nullptr)
	{
		*newlist = ptr1;
		return;
	}
	if(ptr1 && ptr2)
	{
		if(ptr1->data < ptr2->data)
		{
			curr = ptr1;
			ptr1 = ptr1->next;
		}	
		else
		{
			curr = ptr2;
			ptr2 = ptr2->next;
		}
	}
	*newlist = curr;

	while(ptr1 && ptr2)
	{
		if(ptr1->data <= ptr2->data)
		{
			curr->next = ptr1;
			curr = ptr1;
			ptr1 = curr->next;
		}
		else
		{
			curr->next = ptr2;
			curr = ptr2;
			ptr2 = curr->next;
		}
	}
	if(ptr1 == nullptr)
		curr->next = ptr2;
	if(ptr2 == nullptr)
		curr->next = ptr1;
}


int main(int argc, char const *argv[])
{
	bool temp=1;
	int value, a, b, prevValue= INT_MIN;
	Node *list1=nullptr, *list2 = nullptr, *mergelist = nullptr;
	cout<<"\nenter data for list 1: \n";
	while(temp!=0)
	{
		cout<<"\nenter Node value: ";
		cin>>value;
		if(value > prevValue)
		{
			prevValue = value;
			push(&list1,value);
		}
		else
			cout<<"\nplease enter data in ascending order!!";
		cout<<"\nwant to add another 1/0 : ";
		cin>>temp;
	}
	temp = 1;
	prevValue= INT_MIN;
	cout<<"\nenter data for list 2: \n";
	while(temp!=0)
	{
		cout<<"\nenter Node value: ";
		cin>>value;
		if(value > prevValue)
		{
			prevValue = value;
			push(&list2,value);
		}
		else
			cout<<"\nplease enter data in ascending order!!";
		cout<<"\nwant to add another 1/0 : ";
		cin>>temp;
	}
	cout<<"\nlist 1: ";
	printlist(list1);
	cout<<"\nlist 2: ";
	printlist(list2);

	mergeTwoSortedLinkedList(&list1,&list2,&mergelist);

	cout<<"\n list after merging list1 and list2: ";
	printlist(mergelist);
	return 0;
}