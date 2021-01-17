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
#define SIZE 10000
class Solution
{
public:
    void storeBSTNodes(TreeNode *root, TreeNode *arr[], int &n)
    {
        if(root)
        {
            storeBSTNodes(root->left, arr, n);
            arr[n++] = root;
            storeBSTNodes(root->right, arr, n);
        }
    }
    TreeNode* arrayToBST(TreeNode *arr[], int start, int end)
    {
        if(start > end) return nullptr;
        int middle = (start + end)/2;
        TreeNode *root;
        root = arr[middle];
        root->left = arrayToBST(arr, start, middle-1);
        root->right = arrayToBST(arr, middle+1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root)
    {
        TreeNode *arr[SIZE];
        int n=0;
        storeBSTNodes(root, arr, n);
        return arrayToBST(arr, 0, n-1);
    }
};