int isSumTreeHelper(Node *root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;
    
    int leftSum = isSumTreeHelper(root->left);
    if(leftSum == -1)
        return -1;
    int rightSum = isSumTreeHelper(root->right);
    if(rightSum == -1)
        return -1;
    if(root->data == (leftSum + rightSum))
        return root->data * 2;
    return -1;
}
bool isSumTree(Node* root)
{
     int sum = isSumTreeHelper(root);
     return (sum==-1) ? 0 : 1;
}