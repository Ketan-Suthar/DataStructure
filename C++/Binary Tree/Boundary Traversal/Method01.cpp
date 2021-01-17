/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void leftView(Node *root, vector<int> &res)
{
    if(root)
    {
        if(root->left)
        {
            res.push_back(root->data);
            leftView(root->left, res);
        }
        else if(root->right)
        {
            res.push_back(root->data);
            leftView(root->right, res);
        }
    }
}

void rightView(Node *root, vector<int> &res)
{
    if(root)
    {
        if(root->right)
        {
            rightView(root->right, res);
            res.push_back(root->data);
        }
        else if(root->left)
        {
            rightView(root->left, res);
            res.push_back(root->data);
        }
    }
}


void leaves(Node *root, vector<int> &res)
{
    if(root)
    {
        leaves(root->left, res);
        if(!root->left && !root->right)
            res.push_back(root->data);
        leaves(root->right, res);
    }
}

vector <int> printBoundary(Node *root)
{
    vector<int> res;
    if(!root) return res;
    res.push_back(root->data);
    leftView(root->left, res);
    leaves(root->left, res);
    leaves(root->right, res);
    rightView(root->right, res);
    return res;
}