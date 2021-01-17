class Solution {
public:
    TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int start, int end)
    {
        if(start > end)
            return nullptr;
        int middle = (end + start)/2;
        TreeNode *node = new TreeNode(nums[middle]);
        node->left = sortedArrayToBSTHelper(nums, start, middle-1);
        node->right = sortedArrayToBSTHelper(nums, middle+1, end);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        TreeNode *root = sortedArrayToBSTHelper(nums, 0, nums.size()-1);
        return root;
    }
};