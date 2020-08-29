int minDiff(Node *root, int K)
{
    //Your code here
    Node *curr = root;
    int closet = root->data;
    while(curr != NULL)
    {
        if(abs(curr->data - K) < abs(closet - K))
            closet = curr->data;
        if(curr->data < K)
            curr = curr->right;
        else if(curr->data > K)
            curr = curr->left;
        else
        {
            closet = curr->data;
            break;
        }
    }
    return abs(closet - K);
}