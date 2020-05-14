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
	if(root!=nullptr)
	{
		inorderTraversal(root->left);
		cout<<root->key<<" ";
		inorderTraversal(root->right);
	}
}

// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = nullptr; 
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
int heightOfTree(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = heightOfTree(node->left);  
        int rDepth = heightOfTree(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}
int findDiameter(Node *p)
{
	if(p == nullptr)
		return 0;
	int lheight = heightOfTree(p->left);
	int rheight = heightOfTree(p->right);

	int ldia = findDiameter(p->left);
	int rdia = findDiameter(p->right);

	int maxdia = max(lheight+rheight, max(ldia,rdia));

	return maxdia;
}
// Driver program to test above function 
int main() 
{ 
	int key, ch=1; //Key to be searched in BST 

	Node *root = nullptr;
	while(ch)
	{
		cout<<"\nenter node value: ";
		cin>>key;
		if(root == nullptr)
			root = insert(root, key);
		else
			insert(root, key);
		cout<<"\ndo you want to add another node (1/0): ";
		cin>>ch;
	}
	
	int dia = findDiameter(root);

	cout<<"\ndiameter of tree: ";
	cout<<dia;
	return 0; 
} 
