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

int find_length(Node *start)
{
	int cnt = 0;
	Node *p;
	p = start;
	while(p!=NULL)
	{
		cnt++;
		p = p->next;
	}

	return cnt;
}

void reverseLinkedList(Node **head)
{
	Node *curr= *head, *next= *head, *prev= nullptr;

	while(curr!=nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

Node *reverseInKSize(Node **head, int k)
{
	Node *newstart= nullptr, *atk =  *head, *knext = nullptr, *p=nullptr;
	Node *q= nullptr;
	int listlen = find_length(*head);
	int cnt=0;

	if(listlen < k || (*head)==nullptr)
		return *head;

	if(listlen == k)
	{
		reverseLinkedList(head);
		return *head;
	}


	for(int i=1;i<=k;++i)
		atk = atk->next;

	knext = atk->next;
	newstart = atk; //newstart of linked list
	p = atk;
	q = atk;

	while(1)
	{
		p = *head;
		knext = q->next;
		if(knext == nullptr)
		{
			reverseLinkedList(&p);
			return newstart;
		}
		q->next = nullptr;
		q= knext;
		*head = knext;

		cnt = 0;
		//in the last outside while loop , if remainder is non-zero number of nodes
		while(cnt != k-1) 
		{
			if(knext->next == NULL)
				{
					reverseLinkedList(&p);	
					p->next = q;
					return newstart;
				}		
			knext = knext->next;
			cnt++;
		}
		
		reverseLinkedList(&p);
		p->next = knext;
		q = knext;
	}

	return newstart;	
}

int main(int argc, char const *argv[])
{
	bool temp=1;
	int value, k=-1;
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
	
	cout<<"\nenter size of K: ";
	cin>>k;

	list1 = reverseInKSize(&list1,k);

	cout<<"\nlinked list after reversing in "<<k<<" size: ";
	printlist(list1);
	return 0;
}