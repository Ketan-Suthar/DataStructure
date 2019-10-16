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
void print_list(Node* node)
{
	Node* cur=node->next;
	cout<<"\n Curcular List is: ";
	while(cur!=node)
	{
		cout<<cur->data<<" - ";
		cur=cur->next;
	}
}

int main() 
{ 
	Node* last=NULL;
	Node* current=NULL;
	bool yn=1;
	// allocate 3 nodes in the heap
	last = NULL;
	
	cout<<"create linked list :";
	while(yn)
	{
		Node* new_node = new Node();

		cout<<"\nEnter number: ";
		cin>>new_node->data;
		new_node->next = NULL;
		if(last==NULL)
		{
			last=new_node;
			last->next = last;
		}
		else
		{
			current = new_node;
			current->next = last->next;
			last->next = current;
			last = current;
		}
		cout<<"\n do you want to enter another node (1/0): ";
		cin>>yn;
	}
	print_list(last);
	return 0; 
} 

