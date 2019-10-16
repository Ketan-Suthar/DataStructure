// A simple CPP program to introduce 
// a linked list 
#include <bits/stdc++.h> 
using namespace std; 

class Node
{ 
public: 
	int data;
	Node* next;
};

void append(Node** last)
{
	Node* new_node= new Node();
	Node* cur=NULL;
	cout<<"Enter number: ";
	cin>>new_node->data;

	if(*last==NULL)
	{
		*last=new_node;
		(*last)->next = (*last);
	}
	else
	{
		cur = new_node;
		cur->next = (*last)->next;
		(*last)->next = cur;
		*last = cur;
	}	
}

void push(Node** last)
{

}
void insertAfter(Node** last)
{

}
void delete_number(Node** last)
{
	Node* temp= (*last)->next,*prev;
	int num;
	cout<<"\nenter number to delete: ";
	cin>>num;

	if(num==temp->data)
	{
		Node* t = temp;
		(*last)->next = temp->next;
		free(t);
		cout<<num<<" is delete suceessfully";
		return;
	}
	prev = temp;
	temp = temp->next;
	while(temp!=(*last)->next && temp->data!=num)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp == (*last)->next)
	{
		cout<<num<<" is not found in Curcular linked list!!";
		return;
	}
	if(temp == (*last))
	{
		(*last) = prev;
		(*last)->next =temp->next;
	}
	prev->next = temp->next;
	free(temp);
	cout<<num<<" is delete suceessfully"<<(*last)->data;
	
}
void printList(Node* last)
{
	Node* cur=last->next;
	cout<<"\n Curcular List is: ";
	while(cur!=last)
	{
		cout<<cur->data<<" => ";
		cur=cur->next;
	}
	cout<<cur->data;
}

int main() 
{ 
	
	Node* last = NULL; 
	int choice;
	bool yn=1;
	
	while(1)
	{
		cout<<"\n===MENU===\n";
		cout<<"1. append (insert at beginning)\n";
		cout<<"2. push (insert at last)\n";
		cout<<"3. inset after N number\n";
		cout<<"4. delete number\n";
		cout<<"5. delete position\n";
		cout<<"6. display\n";
		cout<<"7. EXIT\n";
		cout<<"\n Enter your choice :: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				append(&last);
				break;
			case 2:
				push(&last);
				break;
			case 3:
				insertAfter(&last);
				break;
			case 4:
				delete_number(&last);
				break;	
			case 6:
				printList(last);
				break;	
			default:
				cout<<"\nWrong Choice!!\n";
		}
	}
	return 0; 
}  

