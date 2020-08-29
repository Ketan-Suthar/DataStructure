/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool utility(TreeNode* root, int sum)
    {
        if(!root)
            return false;
        if(root->left == nullptr && root->right == nullptr)
        {
            if((sum-root->val) == 0)
                return true;
            else
                return false;
        }
        return (utility(root->left, sum-root->val) ||  
                utility(root->right, sum - root->val));
    }
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(root == nullptr)
            return false;
    
        return utility(root, sum);
    }
};