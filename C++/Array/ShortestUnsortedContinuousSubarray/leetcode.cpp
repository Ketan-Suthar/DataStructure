class Solution {
public:
    bool isOutOfOrder(int index, int num, vector<int>& array)
    {
        if(index == 0)
            return num > array[index+1];
        if(index == array.size() - 1)
            return num < array[index-1];
        return num > array[index+1] || num < array[index-1];
    }
    int findUnsortedSubarray(vector<int>& nums)
    {
        int minOutOfOrder = INT_MAX;
        int maxOutOfOrder = INT_MIN;
        int size = nums.size();
        if(!size || size==1)
            return 0;
        for(int i=0; i<size; i++)
        {
            int x = nums[i];
            if(isOutOfOrder(i, x, nums))
            {
                minOutOfOrder = min(x, minOutOfOrder);
                maxOutOfOrder = max(x, maxOutOfOrder);
            }
        }
        if(minOutOfOrder == INT_MAX)
            return 0;
        int left = 0;
        int right = size-1;
        while(minOutOfOrder >= nums[left])
            ++left;
        while(maxOutOfOrder <= nums[right])
            --right;
        return (right - left + 1);
    }
};