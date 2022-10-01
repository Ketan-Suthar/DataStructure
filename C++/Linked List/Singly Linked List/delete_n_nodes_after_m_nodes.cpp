// C++ program to delete N nodes after M nodes of a linked list
#include <bits/stdc++.h>
using namespace std;

// Linked list node
class Node
{
	public:
	int data;
	Node *next;
};

/* Function to insert a node at the beginning */
void push(Node ** head_ref, int new_data)
{
	Node* new_node = new Node();
  new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

// Function to skip M nodes and then delete N nodes of the linked list.
void skipMdeleteN(Node *head, int M, int N)
{
	Node *curr = head, *t;
	int count;
	while (curr)
	{
		// iterate to skip M nodes
		for (count = 1; count < M &&
				curr!= NULL; count++)
			curr = curr->next;

		// If it is end of the list, then return
		if (curr == NULL)
			return;

		// Begin with next node and delete N nodes
		t = curr->next;
		for (count = 1; count<=N && t!= NULL; count++)
		{
			Node *temp = t;
			t = t->next;
			free(temp);
		}
		
		// Link the previous list with remaining nodes
		curr->next = t;

		// Set current pointer for next iteration
		curr = t;
	}
}

int main()
{
	/* Create following linked list
	1->2->3->4->5->6->7->8->9->10 */
	Node* head = NULL;
	int M=2, N=3;
	push(&head, 10);
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << "M = " << M<< " N = " << N << "\nLinked list is :\n";
	printList(head);

	skipMdeleteN(head, M, N);

	cout<<"\nLinked list after deletion:\n";
	printList(head);

	return 0;
}

// This code is contributed by rathbhupendra
