// C++ program to find predecessor and successor in a BST 
#include <iostream>
#include <climits>
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
bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
   
        // Allows only distinct valued nodes  
        if (prev != NULL && root->key <= prev->key) 
          return false; 
   
        prev = root; 
   
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
} 
  
bool isBST(Node *root) 
{ 
   Node *prev = NULL; 
   return isBSTUtil(root, prev); 
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
	int key = 78; //Key to be searched in BST 

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
	
	if(isBST(root))
		cout<<"\nTree is BST";
	else
		cout<<"\nTree is NOT BST";
} 
