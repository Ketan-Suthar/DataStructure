#include<bits/stdc++.h>

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

void utilityFunction(Node *root, unordered_set<int> &allNodes, unordered_set<int> &leafNodes)
{
	if(root == nullptr)
		return;

    allNodes.insert(root->data);

	if(root->left == nullptr && root->right == nullptr)
	{
		leafNodes.insert(root->data);
		return;
	}

	utilityFunction(root->left, allNodes, leafNodes);
	utilityFunction(root->right, allNodes, leafNodes);
}

bool containDeadNode(Node *root)
{ 
	if(root == nullptr)
		return false;

	unordered_set<int> allNodes, leafNodes;

	allNodes.insert(0);
	utilityFunction(root, allNodes, leafNodes);

	for (auto i = leafNodes.begin() ; i != leafNodes.end(); i++)
	{
		int x = *i;
		cout << x << " \n";
		 if (allNodes.find(x+1) != allNodes.end() &&
            allNodes.find(x-1) != allNodes.end())
            return true;
	}
	return false;
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

	if(containDeadNode(root))
		cout << "\nTree Contain Dead Node";
	else
		cout << "\nTree Does Not Contain Dead Node";
	return 0;
}