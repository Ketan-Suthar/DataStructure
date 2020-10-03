class Solution {
public:
    int getNextIndex(vector<int> &nums, int n, int index, int ifForward)
    {
        bool direction = nums[index] > 0;
        
        if(direction != ifForward)
            return -1;
        
        int nextIndex = (index + nums[index]) % n;
        
        if(nextIndex < 0)
            nextIndex = nextIndex + n;
        if(nextIndex == index)
            return -1;
        return nextIndex;
    }
    
    bool circularArrayLoop(vector<int>& nums)
    {
        int n = nums.size();
        int slow, fast, ifForward;
        if(n <= 1)
            return false;
        for(int i=0; i<n; i++)
        {
            slow = fast = i;
            ifForward = nums[i] > 0;
            while(true)
            {
                slow = getNextIndex(nums, n, slow, ifForward);
                if(slow == -1)
                    break;
                fast = getNextIndex(nums, n, fast, ifForward);
                if(fast == -1)
                    break;
                fast = getNextIndex(nums, n, fast, ifForward);
                if(fast == -1)
                    break;
                if(slow == fast)
                    return true;
            }
        }
        return false;
    }
};