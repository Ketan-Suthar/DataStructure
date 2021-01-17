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
    int preInd = 0;
    int search(vector<int> &arr, int start, int end, int key)
    {
        int i;
        for(i=start; i<=end; i++)
            if(arr[i]==key)
                return i;
        return i;
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                             int start, int end)
    {
        if(start > end)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[preInd]);
        ++preInd;        
        if(start==end)
            return node;
        int index = search(inorder, start, end, node->val);
        node->left = buildTreeHelper(preorder, inorder, start, index-1);
        node->right = buildTreeHelper(preorder, inorder, index+1, end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int pre_size = preorder.size(), in_size = inorder.size();
        if(pre_size != in_size)
            return nullptr;
        if(pre_size==0)
            return nullptr;
        if(pre_size==1)
            return new TreeNode(preorder[0]);
        TreeNode *root = buildTreeHelper(preorder, inorder, 0, pre_size-1);
        return root;
    }
};