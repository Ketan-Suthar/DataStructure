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
	while(node!=NULL)
	{
		cout<<node->data<<" - ";
		node=node->next;
	}
}


int main() 
{ 
	Node* head = new Node();
	Node* current = NULL;
	bool yn=1;
	// allocate 3 nodes in the heap 
	head = NULL;
	current = new Node(); 
	cout<<"create linked list :";
	while(yn)
	{
		Node* new_node = new Node();

		cout<<"\nEnter number: ";
		cin>>new_node->data;
		new_node->next = NULL;
		if(head==NULL)
		{
			head=new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		cout<<"\n do you want to enter another node (1/0): ";
		cin>>yn;
	}
	print_list(head);
	return 0; 
} 

