void helper(Node *root, int k, vector<Node*> &path, set<Node*> &res)
{
    if(root)
    {
        path.push_back(root);
        if(!root->left && !root->right)
        {
            int dis_k = path.size() - k - 1;
            if(dis_k >= 0)
                res.insert(path[dis_k]);
            // cout << path.size() << k << path[dis_k] <<'\n';
        }
        helper(root->left, k, path, res);
        helper(root->right, k, path, res);
        path.pop_back();
    }
}

int printKDistantfromLeaf(Node* root, int k)
{
	set<Node*> res;
	vector<Node*> path;
	helper(root, k, path, res);
	return res.size();
}