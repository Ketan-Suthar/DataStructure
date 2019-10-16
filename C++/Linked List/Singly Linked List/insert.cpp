
#include <bits/stdc++.h> 
using namespace std; 

class Node 
{
	public:
	int data;
	Node *next;
};

void push(Node** head_ref) 
{ 
	
	Node* new_node = new Node();
	
	cout<<"Enter number: ";
	cin>>new_node->data;

	new_node->next = (*head_ref);
	(*head_ref) = new_node; 
} 

void insertAfter(Node** prev_node, Node** cur_node) 
{ 
	
	int num;
	Node* temp= *prev_node;
	
	cout<<"Enter number after which you want to insert: ";
	cin>>num;

	while(temp!=NULL)
	{
		if(temp->data==num)
			break;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"Opps! number not found!!";
		return;
	}

	Node* new_node = new Node(); 
	int data;
	cout<<"enter number to be insert: ";
	cin>>new_node->data;
	new_node->next = temp->next;

	temp->next=new_node;
} 

void append(Node** head_ref, Node** cur_node) 
{ 
	Node* new_node = new Node();
	*cur_node = new Node(); 

	Node *last = *head_ref; 

	cout<<"Enter number: ";
	cin>>new_node->data; 

	new_node->next = NULL; 

	if (*head_ref == NULL) 
	{ 
		*head_ref = new_node;
		*cur_node = new_node;
		return; 
	} 

	while (last->next != NULL) 
		last = last->next; 

	last->next = new_node;
	*cur_node = last;
	return; 
} 


void printList(Node *node) 
{ 
	cout<<"Linked List is: ";
	while (node != NULL) 
	{ 
		cout<<" "<<node->data; 
		node = node->next; 
	} 
} 


int main() 
{ 
	
	Node* head = NULL; 
	
	int choice;
	head = new Node();
	Node* current = NULL;
	bool yn=1;
	
	head = NULL;
	current = new Node();
	
	while(1)
	{
		cout<<"\n===MENU===\n";
		cout<<"1. append (insert at beginning)\n";
		cout<<"2. push (insert at last)\n";
		cout<<"3. inset after N number\n";
		
		cout<<"4. display\n";
		cout<<"n. EXIT\n";
		cout<<"\n Enter your choice :: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				append(&head,&current);
				break;
			case 2:
				push(&head);
				break;
			case 3:
				insertAfter(&head,&current);
				break;
			case 4:
				printList(head);
				break;	
			default:
				cout<<"\nWrong Choice!!\n";
		}
	}

	
	cout<<"Created Linked list is: "; 
	printList(head); 
	
	return 0; 
}  
