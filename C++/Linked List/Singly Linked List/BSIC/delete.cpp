
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

void delete_number(Node** head_ref)
{
	Node* temp= *head_ref,*prev;
	int num;
	if(temp==NULL)
	{
		cout<<"\nList is EMPTY!!";
		return;
	}
	cout<<"enter number for delete: ";
	cin>>num;
	if(temp->data==num)
	{
		*head_ref = temp->next;
		free(temp);
		cout<<num<<" deleted successfully.";
		return;
	}
	while (temp != NULL && temp->data != num)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL)
	{
		cout<<num<<" not found in list";
		return;
	}
	prev->next = temp->next;
	free(temp);
	cout<<num<<" deleted successfully.";
}
void delete_position(Node** head_ref)
{
	Node* temp= *head_ref,*prev;
	int in=1,pos;
	if(temp==NULL)
	{
		cout<<"\nList is EMPTY!!";
		return;
	}
	cout<<"enter position to be delete: ";
	cin>>pos;

	if(pos==in)
	{
		*head_ref = temp->next;
		free(temp);
		cout<<pos<<"th node deleted successfully.";
		return;
	}

	while (temp != NULL)
	{
		if(pos==in)
			break;
		++in;
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL)
	{
		cout<<pos<<"th node not found in list";
		return;
	}
	prev->next = temp->next;
	free(temp);
	cout<<pos<<"th node deleted successfully.";
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
		cout<<"3. delete number\n";
		cout<<"4. delete at position\n";
		cout<<"5. display\n";
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
				delete_number(&head);
				break;
			case 4:
				delete_position(&head);
				break;
			case 5:
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
