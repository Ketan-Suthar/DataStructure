class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            sort(arr, arr+n);
            int curr_sum, closest_sum = INT_MAX, l_index=0, r_index=n-1,
                min_l_index=l_index, min_r_index=r_index;
            while(l_index < r_index)
            {
                curr_sum = arr[l_index] + arr[r_index];
                if(abs(curr_sum) < abs(closest_sum))
                {
                    closest_sum = curr_sum;
                    min_l_index=l_index;
                    min_r_index=r_index;
                }
                if(curr_sum < 0)
                    ++l_index;
                else
                    --r_index;
            }
            return arr[min_l_index] + arr[min_r_index];
        }
};