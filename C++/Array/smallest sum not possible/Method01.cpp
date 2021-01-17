class Solution{   
public:
    long long findSmallest(long long arr[], int n)
    {
        long long ans = 1;
        sort(arr, arr+n);
        for(int i=0;i<n;i++)
        {
            if(arr[i] > ans)
                break;
            else
                ans = arr[i] + ans;
        }
        return ans;
    }
};