#include <iostream>

using namespace std;

typedef struct treeNode
{
	int data;
	treeNode *left;
	treeNode *right;
}Node;

Node *createNewNode(int item) 
{ 
	Node *temp = (Node *)malloc(sizeof(Node)); 
	temp->data = item; 
	temp->left = temp->right = nullptr; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(Node *root) 
{ 
	if (root != nullptr) 
	{ 
		inorder(root->left); 
		printf("%d \n", root->data);
		inorder(root->right);
	} 
}
Node * insert(Node *root,int item)
{
	Node *newNode = createNewNode(item);
	Node *y = nullptr;
	Node *x = root;
	while(x!=nullptr)
	{
		y = x;
		if(item < x->data)
			x = x->left;
		else
			x = x->right;
	}
	if(y == nullptr)
		return newNode;
	else if(item < y->data)
		y->left = newNode;
	else
		y->right = newNode;
	return newNode;
}

void displayDLL(Node *head)
{
	Node *temp = head;
	cout<<"\nprev\tcurrent\tnext\n";
	while(temp)
	{
		if(temp->left == nullptr)
		{
			if(temp->right == nullptr)
				cout<<"NULL\t"<<temp->data<<"\t"<<"NULL"<<"\n";
			else
				cout<<"NULL\t"<<temp->data<<"\t"<<temp->right->data<<"\n";
		}
		else
		{
			if(temp->right == nullptr)
				cout<<temp->left->data<<"\t"<<temp->data<<"\t"<<"NULL"<<"\n";
			else
				cout<<temp->left->data<<"\t"<<temp->data<<"\t"<<temp->right->data<<"\n";
		}
		temp= temp->right;
	}
}

void convertToDLL(Node *root, Node **head)
{
	if(root == nullptr)
		return;
	static Node *prev = nullptr;
	convertToDLL(root->left, head);

	if(prev == nullptr)
		*head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	convertToDLL(root->right, head);
}

int main(int argc, char const *argv[])
{
	int ch=1; 
	Node *root = nullptr, *head = nullptr; 
	do
	{
		cout<<"\n===MAIN MENU===";
		cout<<"\n1.insert Node to BST";
		cout<<"\n2.display BST";
		cout<<"\n3.convert to doubly linked list";
		cout<<"\n4.EXIT";
		cout<<"\n\tEnter your choice:: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				int val;
				cout<<"\nenter Node value:: ";
				cin>>val;
				if(root==nullptr)
					root = insert(root, val);
				else
					insert(root, val);
				break;
			case 2:
				// print iNoder traversal of the BST 
				cout<<"\nBST is:\n";
				inorder(root);
				break;
			case 3:
				convertToDLL(root, &head);
				cout<<"\nBST after converting to DLL:\n";
				displayDLL(head);
				break;
		}
	}while(ch!=4);

	return 0;
}