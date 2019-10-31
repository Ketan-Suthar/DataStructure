#include <iostream>

using namespace std;

typedef struct treeNode
{
	int key;
	treeNode *left;
	treeNode *right;
	treeNode *parent;
}node;

node *newNode(int item) 
{ 
	node *temp = (node *)malloc(sizeof(node)); 
	temp->key = item; 
	temp->left = temp->right = temp->parent = nullptr; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(node *root) 
{ 
	if (root != nullptr) 
	{ 
		inorder(root->left); 
		printf("%d \n", root->key);
		inorder(root->right);
	} 
}
node *search(node *root,int item)
{
	node *temp = root;
	while(temp!=nullptr && item!=temp->key)
	{
		if(item < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}
node * insert(node *root,int item)
{
	node *newnode = newNode(item);
	node *y = nullptr;
	node *x = root;
	while(x!=nullptr)
	{
		y = x;
		if(item < x->key)
			x = x->left;
		else
			x = x->right;
	}
	newnode->parent = y;
	if(y == nullptr)
		return newnode;
	else if(item < y->key)
		y->left = newnode;
	else
		y->right = newnode;
	return newnode;
}
node *minimum(node *n)
{
	node *temp = n;
	if(temp)
		while(temp->left!=nullptr)
			temp = temp->left;
	return temp;
}
void transplant(node *root,node *u,node *v)
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
void deletenumber(node *root,int item)
{
	node *z = search(root,item);
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
			node *y = minimum(z->right);
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
	node *root = nullptr; 
	do
	{
		cout<<"\n===MAIN MENU===";
		cout<<"\n1.insert node to BST";
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
				cout<<"\nenter node value:: ";
				cin>>val;
				if(root==nullptr)
					root = insert(root, val);
				else
					insert(root, val);
				break;
			case 2:
				// print inoder traversal of the BST 
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