// C++ program to find predecessor and successor in a BST 
#include <iostream> 
using namespace std; 

// BST Node 
struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 
void inorderTraversal(Node *root)
{
	if(root!=NULL)
	{
		inorderTraversal(root->left);
		cout<<root->key<<" ";
		inorderTraversal(root->right);
	}
}
// This function finds predecessor and successor of key in BST. 
// It sets pre and suc as predecessor and successor respectively 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
	// Base case 
	if (root == NULL) return ; 
	cout<<"\nhii "<<root->key;
	// If key is present at root 
	if (root->key == key) 
	{ 
		// the maximum value in left subtree is predecessor 
		
		if (root->left != NULL) 
		{ 
			Node* tmp = root->left; 
			while (tmp->right) 
				tmp = tmp->right;
			
			pre = tmp ; 
		} 

		// the minimum value in right subtree is successor 
		if (root->right != NULL) 
		{ 
			Node* tmp = root->right ; 
			while (tmp->left) 
				tmp = tmp->left ; 
			suc = tmp ; 
		} 
		return ; 
	} 

	// If key is smaller than root's key, go to left subtree 
	if (root->key > key) 
	{ 
		suc = root ; 
		findPreSuc(root->left, pre, suc, key) ; 
	} 
	else if(root->key < key) // go to right subtree 
	{ 
		pre = root ; 
		findPreSuc(root->right, pre, suc, key) ; 
	} 
} 

// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
	if (node == NULL) return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 
	return node; 
} 

// Driver program to test above function 
int main() 
{ 
	int key; //Key to be searched in BST 

/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	Node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 16); 
	insert(root, 14); 
	insert(root, 10); 
	insert(root, 15); 
	insert(root, 5); 
	insert(root, 40); 
	insert(root, 35);
	insert(root, 32);
	insert(root, 36);
	insert(root, 37);
	insert(root, 45);
	insert(root, 90);
	insert(root, 78);
	insert(root, 75);
	insert(root, 100);
	insert(root, 82);
	insert(root, 81);
	insert(root, 79);
	insert(root, 85);
	insert(root, 87);
	//insert(root, 30); 


	Node* pre = NULL, *suc = NULL; 
	inorderTraversal(root);

	cout<<"\nfind value to find successor and predecessor: ";
	cin>>key;

	findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << "\nPredecessor is " << pre->key << endl; 
	else
	cout << "\nNo Predecessor"; 

	if (suc != NULL) 
	cout << "\nSuccessor is " << suc->key; 
	else
	cout << "\nNo Successor"; 
	return 0; 
} 
