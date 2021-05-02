/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    map<TreeNode*, TreeNode*> parent;
    set<TreeNode*> visited;
    
    void setParent(TreeNode* node)
    {
        if(!node) return;
        if(node->left)
        {
            parent[node->left] = node;
            setParent(node->left);
        }
        if(node->right)
        {
            parent[node->right] = node;
            setParent(node->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        if(!root) return {};
        setParent(root);
        dfs(target, k);
        return result;
    }
    
    void dfs(TreeNode* node, int k)
    {
        if(visited.find(node) != visited.end())
            return;
        visited.insert(node);
        if(k == 0)
        {
            result.push_back(node->val);
            return;
        }
        if(node->left)
            dfs(node->left, k-1);
        if(node->right)
            dfs(node->right, k-1);
        TreeNode* p = parent[node];
        if(p)
            dfs(p, k-1);
    }
};
