void leftViewHelper(Node *root, vector<int> &res, int currLevel, int &maxLevel)
{
    if(root)
    {
        if(currLevel > maxLevel)
        {
            res.push_back(root->data);
            maxLevel = currLevel;
        }
        leftViewHelper(root->left, res, currLevel+1, maxLevel);
        leftViewHelper(root->right, res, currLevel+1, maxLevel);
    }
}

vector<int> leftView(Node *root)
{
   vector<int> res;
   int maxLevel = 0;
   leftViewHelper(root, res, 1, maxLevel);
   return res;
}
