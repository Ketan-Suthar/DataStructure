int helper(Node *root, int &res)
{
    if(root)
    {
        if(!root->left && !root->right)
            return root->data;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        int minimum = min(left, right);
        int diff = root->data - minimum;
        res = max(res, diff);
        return min(root->data, minimum);
    }
    return INT_MAX;
}

int maxDiff(Node* root)
{
    int result = INT_MIN;
    helper(root, result);
    return result;
}
