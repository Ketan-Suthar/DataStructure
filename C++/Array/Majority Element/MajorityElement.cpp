class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int index = 0, count = 1;
        int size = nums.size();
        for(int i=1; i<size; i++)
        {
            if(nums[i] != nums[index])
                count--;
            else
                count ++;
            if(count == 0)
                index = i, count = 1;
        }
        int candidate = nums[index];
        cout<<candidate<<' '<<count;
        return candidate;
    }
};