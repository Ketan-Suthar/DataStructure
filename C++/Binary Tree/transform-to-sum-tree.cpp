
int toSumTreeHelper(Node *root)
{
    if(!root)
        return 0;
    int currData = root->data;
    int leftData = toSumTreeHelper(root->left);
    int rightData = toSumTreeHelper(root->right);
    
    root->data = leftData + rightData;
    return root->data + currData;
}