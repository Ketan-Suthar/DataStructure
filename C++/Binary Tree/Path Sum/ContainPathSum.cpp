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
class Solution 
{
private:
    
public:
    bool traverse( TreeNode* root, int sum, int curr_sum)
    {
        if(root ==  NULL)
            return false;
        if(root ->left == NULL && root->right == NULL)
            return (root->val+curr_sum == sum)?true:false;
        return traverse(root->left , sum , root->val+curr_sum) || traverse(root->right , sum , root->val+curr_sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return traverse(root,sum,0);
    }
};