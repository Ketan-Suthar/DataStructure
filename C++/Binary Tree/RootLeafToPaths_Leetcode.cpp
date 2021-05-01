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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> result;
        list<int> stk;
        helper(root, result, stk);
        return result;
    }
    void helper(TreeNode* root, vector<string> &result, list<int> &stk)
    {
        if(root)
        {
            cout << root->val << ' ';
            stk.push_back(root->val);
            if(!root->left && !root->right)
            {
                string str;
                int size = stk.size(), i=0;
                list <int> :: iterator it;
                for(it = stk.begin(); it != stk.end(); ++it, ++i)
                {
                    str = str + std::to_string(*it);
                    if(i==(size-1))
                        continue;
                    str+="->";
                }
                result.push_back(str);
            }
            helper(root->left, result, stk);
            helper(root->right, result, stk);
            stk.pop_back();
        }
    
    }
};
