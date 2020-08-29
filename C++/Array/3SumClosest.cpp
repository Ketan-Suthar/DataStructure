class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int size=nums.size();
        sort(nums.begin() , nums.end());
        int res = nums[0] + nums[1] + nums[size-1];

        for(int i=0; i<size-2; i++)
        {
            int aptr = i+1;
            int bptr = size-1;
            while(aptr < bptr)
            {
                int sum = nums[i] + nums[aptr] + nums[bptr];
                if(sum > target)
                    bptr--;
                else
                    aptr++;
            
                if(abs(target-sum) < abs(target-res))
                    res = sum;
            }
        }
        return res;
    }
};