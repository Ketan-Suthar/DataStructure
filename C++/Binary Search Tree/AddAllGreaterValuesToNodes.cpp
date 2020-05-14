#include <iostream>
#include <stack>
using namespace std;

typedef struct treeNode
{
	int data;
	treeNode *left;
	treeNode *right;
	treeNode *parent;
}Node;

Node *createNewNode(int item) 
{ 
	Node *temp = new Node(); 
	temp->data = item; 
	temp->left = temp->right = temp->parent = nullptr; 
	return temp; 
}

void insert(Node **root,int item)
{
	Node *newNode = createNewNode(item);
	Node *y = nullptr;
	Node *x = *root;
	while(x!=nullptr)
	{
		y = x;
		if(item < x->data)
			x = x->left;
		else
			x = x->right;
	}
	newNode->parent = y;

	if((*root)==nullptr)
		*root = newNode;
	else
	{
		if(item < y->data)
			y->left = newNode;
		else
			y->right = newNode;
	}
}

// A utility function to do inorder traversal of BST 
void inorder(Node *root) 
{ 
	Node *p = root;
	stack <Node*> s;
	cout<<"\nInorder traversal: ";
	while(1)
	{
		while(p)
		{
			s.push(p);
			p = p->right;
		}
		if(s.empty())
			break;
		p = s.top();
		s.pop();
		cout<<p->data<<" ";
		p = p->left;
	}
}

void addGreaterValues(Node *root) 
{ 
	Node *p = root;
	stack <Node*> s;
	long int prevSum = 0;
	cout<<"\nrunning addGreaterValues()\n";
	while(1)
	{
		while(p)
		{
			s.push(p);
			p = p->right;
		}
		if(s.empty())
			break;

		p = s.top();
		prevSum = p->data += prevSum;
		s.pop();

		cout<<p->data<<" ";
		p = p->left;
	}
}

int main(int argc, char const *argv[])
{
	int ch=1,val; 
	Node *root = nullptr; 
	do
	{
		cout<<"\nenter Node value:: ";
		cin>>val;
		
		insert(&root, val);
		
		cout<<"\ndo want to enter nother Node(1/0): ";
		cin>>ch;
	}while(ch!=0);

	addGreaterValues(root);
	cout<<"\nBST is:\n";
	inorder(root);
	return 0;
}