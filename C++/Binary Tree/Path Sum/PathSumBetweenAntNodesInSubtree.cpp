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
    int paths=0; vector<int> v;
    void helper(TreeNode* node,int sum)
    {
        if(node==NULL) return;
        v.push_back(node->val);
        helper(node->left,sum);
        helper(node->right,sum);
        int target=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            target+=v[i];
            if(target==sum) paths++;
        }
        v.pop_back();
        return;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        
        helper(root,sum);
        return paths;
        
    }
};