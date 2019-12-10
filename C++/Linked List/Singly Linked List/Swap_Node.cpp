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
void swapNodes(Node **head_ref, int x, int y)  
{  
	// Nothing to do if x and y are same  
	if (x == y) return;  
	  
	// Search for x (keep track of prevX and CurrX  
	Node *prevX = NULL, *currX = *head_ref;  
	while (currX && currX->data != x)  
	{  
	    prevX = currX;  
	    currX = currX->next;  
	}  
	 
	// Search for y (keep track of prevY and CurrY  
	Node *prevY = NULL, *currY = *head_ref;  
	while (currY && currY->data != y)  
	{  
	    prevY = currY;  
	    currY = currY->next;  
	}  
	  
	// If either x or y is not present, nothing to do  
	if (currX == NULL || currY == NULL)  
	    return;  
	  
	// If x is not head of linked list  
	if (prevX != NULL)  
	    prevX->next = currY;  
	else // Else make y as new head  
	    *head_ref = currY;  
	  
	// If y is not head of linked list  
	if (prevY != NULL)  
	    prevY->next = currX;  
	else // Else make x as new head  
	    *head_ref = currX;  
	  
	// Swap next pointers  
	Node *temp = currY->next;  
	currY->next = currX->next;  
	currX->next = temp;  
} 
int main(int argc, char const *argv[])
{
	bool temp=1;
	int value, a, b;
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
	
	cout<<"\nenter two node to swap: ";
	cin>>a>>b;
	swapNodes(&head,40,20);
	cout<<"\nlinked list after swaping "<<a<<" and "<<b<<" : ";
	printlist(head);
	return 0;
}