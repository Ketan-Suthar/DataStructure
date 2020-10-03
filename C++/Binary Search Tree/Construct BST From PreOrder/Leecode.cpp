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
    TreeNode* getNode(int val)
    {
        TreeNode *newNode = new TreeNode;
        newNode->val = val;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    int buildBST(const vector<int> &preorder,const int n, int pos,
                    TreeNode *currNode, int minimum, int maximum)
    {
        if(pos == n || preorder[pos] < minimum || preorder[pos] > maximum)
            return pos;
        if(preorder[pos] < currNode->val)
        {
            currNode->left = getNode(preorder[pos]);
            pos += 1;
            pos = buildBST(preorder, n, pos, currNode->left, minimum, currNode->val-1);
        }
        if(pos == n || preorder[pos] < minimum || preorder[pos] > maximum)
            return pos;
        currNode->right = getNode(preorder[pos]);
        pos += 1;
        pos = buildBST(preorder, n, pos, currNode->right, currNode->val+1, maximum);
        return pos;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int n = preorder.size();
        if(n == 0)
            return nullptr;
        TreeNode *root = getNode(preorder[0]);
        if(n == 1)
            return root;
        buildBST(preorder, n, 1, root, INT_MIN, INT_MAX);
        return root;
    }
};