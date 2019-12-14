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

Node *swapNodesPairWise(Node *head)
{
	Node *p , *q;
	Node *newstart = nullptr;
	if(head == NULL || head->next == nullptr)
		return head;
	newstart = head->next;
	p = head;
	while(1)
	{
		q = p->next;
		Node* temp = q->next;
		q->next = p;
		if(temp == nullptr || temp->next == nullptr)
		{
			p->next = temp;
			break;
		}
		p->next = temp->next;
		p = temp;
	}
	return newstart;	
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
	
	list1 = swapNodesPairWise(list1);

	cout<<"\nlinked list after swaping nodes pair wise: ";
	printlist(list1);
	return 0;
}