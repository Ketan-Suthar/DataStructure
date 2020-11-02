int maxLen(int nums[], int n)
{
    unordered_map<int, int> map;
    
    int arr[n];
    arr[0] = (nums[0] == 0) ? -1 : 1;
    for(int i=1;i<n;i++)
        arr[i] = arr[i-1] + ((nums[i] == 0) ? -1 : 1);
    int curr_sum;
    int up=0, low=0, max_size = -1;
    for(int i=0;i<n;i++)
    {
        curr_sum = arr[i];
        if(curr_sum == 0)
        {
            up = i;
            low = 0;
            max_size = i+1;
            continue;
        }
        if(map.find(curr_sum) == map.end())
             map[curr_sum] = i;
        else
        {
            int curr_size = i - map[curr_sum];
            if(curr_size > max_size)
            {
                up = i;
                low = map[curr_sum]+1;
                max_size = curr_size;
            }
        }
    }
    if(max_size==-1)
        return 0;
    return max_size;
}
