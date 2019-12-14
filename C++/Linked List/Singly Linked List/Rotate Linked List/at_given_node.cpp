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

Node *rotateAtGivenNode(Node **head, int rotatenode)
{
	Node *newstart=nullptr, *temp=*head, *end= nullptr;

	while(temp!=nullptr && temp->data != rotatenode)
		temp = temp->next;

	if(temp == nullptr)
	{
		cout<<"\n"<<rotatenode<<" is not present in list!!\n";
		return *head;
	}
	if((*head)->next == nullptr || temp->next == nullptr)
		return *head;

	newstart = temp->next;
	temp->next = nullptr;
	end = newstart;

	while(end->next != nullptr)
		end = end->next;
	end->next = *head;

	return newstart;	
}

int main(int argc, char const *argv[])
{
	bool temp=1;
	int value, rotatenode=-1;
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
	
	cout<<"\nenter node value where you want to rotate list: ";
	cin>>rotatenode;


	list1 = rotateAtGivenNode(&list1,rotatenode);

	cout<<"\nlinked list after rotating: ";
	printlist(list1);
	return 0;
}