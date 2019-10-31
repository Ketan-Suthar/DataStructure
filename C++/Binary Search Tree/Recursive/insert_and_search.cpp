// Cpp program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
using namespace std;
struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d \n", root->key);
		inorder(root->right);
	} 
} 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 
// function to search a given key in a given BST 
struct node* search(struct node* root, int key) 
{ 
	//this is recursive solution
		// Base Cases: root is null or key is present at root 
		if (root == NULL || root->key == key) 
			return root; 
		
		// Key is greater than root's key 
		if (root->key < key) 
		return search(root->right, key); 

		// Key is smaller than root's key 
		return search(root->left, key);
	/*
		//this is non recursive solution
		struct node *temp = root;
		while(temp!=NULL && key!=temp->key)
		{
			if(key < temp->key)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	*/	
} 

// Driver Program to test above functions 
int main() 
{
	int ch=1; 
	struct node *root = NULL; 
	do
	{
		cout<<"\n===MAIN MENU===";
		cout<<"\n1.insert node to BST";
		cout<<"\n2.display BST";
		cout<<"\n3.search value in BST";
		cout<<"\n4.EXIT";
		cout<<"\n\tEnter your choice:: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				int val;
				cout<<"\nenter node value:: ";
				cin>>val;
				if(root==NULL)
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
				cout<<"\nenter value to be search:: ";
				cin>>val;
				if(search(root,val))
					cout<<"\nvalue "<<val<<" is PRESENT in BST";
				else
					cout<<"\nvalue "<<val<<" is NOT PRESENT in BST!!";
				break;
		}
	}while(ch!=4);

	return 0; 
} 
