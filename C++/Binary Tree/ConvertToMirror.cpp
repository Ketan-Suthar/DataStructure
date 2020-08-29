// first way

void mirror(Node* node) 
{
    // Your Code Here
    if(!node)
        return;
    if(!node->left && !node->right)
        return;
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
    if(node->left)
        mirror(node->left);
    if(node->right)
        mirror(node->right);
}

// second way

class Solution {
public:
    void swapNodes(TreeNode *node)
    {
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    void mirror(TreeNode *node)
    {
        if(!node)
            return;
        swapNodes(node);
        mirror(node->left);
        mirror(node->right);
        
    }
    TreeNode* invertTree(TreeNode* root)
    {
        mirror(root);
        return root;
    }
};
