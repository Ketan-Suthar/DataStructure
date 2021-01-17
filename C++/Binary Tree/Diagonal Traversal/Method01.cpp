/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(TreeNode *root, map<int, vector<int>> &map, int dis)
{
    if(root)
    {
        map[dis].push_back(root->val);
        helper(root->left, map, dis+1);
        helper(root->right, map, dis);
    }
}
vector<int> Solution::solve(TreeNode* A)
{
    map<int, vector<int>> map;
    helper(A, map, 0);
    vector<int> res;
    for(auto item: map)
        for(int val: item.second)
            res.push_back(val);
    return res;
}
