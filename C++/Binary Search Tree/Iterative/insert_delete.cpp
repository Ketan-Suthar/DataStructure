#include <iostream>

using namespace std;

typedef struct treeNode
{
	int key;
	treeNode *left;
	treeNode *right;
	treeNode *parent;
}Node;

Node *createNewNode(int item) 
{ 
	Node *temp = (Node *)malloc(sizeof(Node)); 
	temp->key = item; 
	temp->left = temp->right = temp->parent = nullptr; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(Node *root) 
{ 
	if (root != nullptr) 
	{ 
		inorder(root->left); 
		printf("%d \n", root->key);
		inorder(root->right);
	} 
}
Node *search(Node *root,int item)
{
	Node *temp = root;
	while(temp!=nullptr && item!=temp->key)
	{
		if(item < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}
Node * insert(Node *root,int item)
{
	Node *newNode = createNewNode(item);
	Node *y = nullptr;
	Node *x = root;
	while(x!=nullptr)
	{
		y = x;
		if(item < x->key)
			x = x->left;
		else
			x = x->right;
	}
	newNode->parent = y;
	if(y == nullptr)
		return newNode;
	else if(item < y->key)
		y->left = newNode;
	else
		y->right = newNode;
	return newNode;
}
Node *minimum(Node *n)
{
	Node *temp = n;
	if(temp)
		while(temp->left!=nullptr)
			temp = temp->left;
	return temp;
}
void transplant(Node *root,Node *u,Node *v)
{
	if(u->parent == nullptr)
		root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if(v != nullptr)
		v->parent = u->parent;
}
void deletenumber(Node *root,int item)
{
	Node *z = search(root,item);
	if(!z)
		cout<<"oops! "<<item<<" is NOT PRESENT.";
	else
	{
		if(z->left == nullptr)
			transplant(root,z,z->right);
		else if(z->right == nullptr)
			transplant(root,z,z->left);
		else
		{
			Node *y = minimum(z->right);
			if(y->parent != z)
			{
				transplant(root,y,y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			transplant(root,z,y);
			y->left = z->left;
			y->left->parent = y;
		}
	}
}
int main(int argc, char const *argv[])
{
	int ch=1; 
	Node *root = nullptr; 
	do
	{
		cout<<"\n===MAIN MENU===";
		cout<<"\n1.insert Node to BST";
		cout<<"\n2.display BST";
		cout<<"\n3.delete";
		cout<<"\n4.Search";
		cout<<"\n5.EXIT";
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
				int n;
				cout<<"\nenter number:";
				cin>>n;
				deletenumber(root,n);
				cout<<"\ntree after deleting :\n"<<n;
				inorder(root);
				break;	
			case 4:
	
				cout<<"\nenter number: ";
				cin>>n;
				if(search(root,n))
					cout<<n<<" is PRESENT in tree!";
				else
					cout<<n<<" is NOT PRESENT in tree!";
				break;
		}
	}while(ch!=5);

	return 0;
}