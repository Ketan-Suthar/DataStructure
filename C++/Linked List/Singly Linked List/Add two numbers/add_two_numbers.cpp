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

int lengthoflist(Node *head)
{
	int cout=0;
	Node *temp = head;
	while(temp)
	{
		++cout;
		temp = temp->next;
	}
	return cout;
}

Node *reverseLinkedList(Node *head)
{
	Node *p , *q;

	if(head == NULL)
		return head;

	p = head;
	q = p->next;

	if(q == NULL)
		return p;

	q = reverseLinkedList(q);

	p->next->next = p;
	p->next = NULL;
	return q;	
}

void addTwoNumbers(Node **list1, Node **list2, Node **newlist)
{
	*list1 = reverseLinkedList(*list1);
	*list2 = reverseLinkedList(*list2);

	Node *l1 = *list1, *l2 = *list2;
	int sum=0, rem=0, carry=0;
	
	int len1 = lengthoflist(*list1);
	int len2 = lengthoflist(*list2);

	int maxlen = len1>len2 ? len1 : len2;

	while(lengthoflist(*list1) < maxlen)
		push(&(*list1),0);
	while(lengthoflist(*list2) < maxlen)
		push(&(*list2),0);

	//cout<<"\nlist 1: ";
	// printlist(*list1);
	// cout<<"\nlist 2: ";
	// printlist(*list2);
	//l1 = l1->next;
	cout<<l2->data<<endl;

	while(l1!= nullptr)
	{
		sum = l1->data + l2->data + carry;
		rem = sum%10;
		carry = sum/10;
		push(&(*newlist),rem);

		l1 = l1->next;
		l2 = l2->next;
	}

	if(carry!=0)
		push(&(*newlist),carry);

	*newlist = reverseLinkedList(*newlist);
}


int main(int argc, char const *argv[])
{
	int temp=1;
	int value;
	Node *list1=nullptr, *list2 = nullptr, *sumlist = nullptr;
	cout<<"\nenter data for list 1: \n";
	while(temp!=0)
	{
		cout<<"\nenter Node value: ";
		cin>>value;
		
		push(&list1,value);

		cout<<"\nwant to add another 1/0 : ";
		cin>>temp;
	}
	temp=1;
	cout<<"\nenter data for list 2: \n";
	while(temp!=0)
	{
		cout<<"\nenter Node value: ";
		cin>>value;
	
		push(&list2,value);
	
		cout<<"\nwant to add another 1/0 : ";
		cin>>temp;
	}
	// cout<<"\nlist 1: ";
	// printlist(list1);
	// cout<<"\nlist 2: ";
	// printlist(list2);

	addTwoNumbers(&list1,&list2,&sumlist);

	cout<<"\nlinked list of sumed list is : ";
	printlist(sumlist);
	return 0;
}