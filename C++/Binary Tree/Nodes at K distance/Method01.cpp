
void KdistanceHelper(struct Node *root, int k, vector<int> &res)
{
    if(!root) return;
    if(!k)
    {
        res.push_back(root->data);
        return;
    }
    KdistanceHelper(root->left, k-1, res);
    KdistanceHelper(root->right, k-1, res);
}

vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> res;
    KdistanceHelper(root, k, res);
    return res;
}