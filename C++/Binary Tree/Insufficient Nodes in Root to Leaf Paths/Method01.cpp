class Solution {
public:
    int sufficientSubsetHelper(TreeNode* root, int limit, int pathSum)
    {
        if(!root) return INT_MIN;
        pathSum += root->val;
        if(!root->left && !root->right)            
            return pathSum;
        
        int leftSum = sufficientSubsetHelper(root->left, limit, pathSum);
        if(leftSum < limit)
            root->left = nullptr;
        int rightSum = sufficientSubsetHelper(root->right, limit, pathSum);
        if(rightSum < limit)
            root->right = nullptr;
        
        return max(leftSum, rightSum);
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit)
    {
        if(!root)
            return root;
        int sum = 0;
        int totalsum = sufficientSubsetHelper(root, limit, sum);
        if(totalsum < limit)
            return nullptr;
        return root;
    }
};