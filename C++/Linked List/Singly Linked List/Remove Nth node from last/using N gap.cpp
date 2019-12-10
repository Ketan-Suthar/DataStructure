#include <iostream>

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
	newNode->next = *head;
	(*head) = newNode;
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
/* Function to swap Nodes x and y in linked list by  
changing links */
Node* removennode(Node **head_ref, int n)
{  
	Node *dummy =new Node();
	dummy->next = *head_ref;

	Node *first = dummy;
	Node *second = dummy;

	for(int i=1;i<=n+1;++i)
		first = first->next;

	while(first)
	{
		second = second->next;
		first = first->next;
	}
	second->next = second->next->next;

	return dummy->next;
}

int main(int argc, char const *argv[])
{
	bool temp=1;
	int value, n;
	Node *head=nullptr;
	while(temp)
	{
		cout<<"\nenter Node value: ";
		cin>>value;
		push(&head,value);
		cout<<"\nwant to add another 1/0 : ";
		cin>>temp;
	}
	printlist(head);
	
	cout<<"\nenter Nth value from last to be remove: ";
	cin>>n;
	head = removennode(&head,n);
	cout<<"\nlinked list after removing "<<n<<"th node from last ";
	printlist(head);
	return 0;
}