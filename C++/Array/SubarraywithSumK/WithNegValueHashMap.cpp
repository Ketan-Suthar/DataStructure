class Solution
{
  public:
    int subArraySum(int arr[], int n, int sum)
    {
    	//code here.
    	unordered_map<int, int> hm;
    	int curr_sum = 0, count = 0;
    	for(int i=0; i<n; i++)
    	{
    	    curr_sum += arr[i];
    	    
    	    if(curr_sum == sum)
    	        ++count;
    	    if(hm.find(curr_sum - sum) != hm.end())
    	        count += hm[curr_sum - sum];
    	    hm[curr_sum] += 1;
    	}
    	return count;
    }
};