#include <bits/stdc++.h>
using namespace std;

int findMaximumDifference(int *arr, int n)
{
    int diff[n-1];
    for(int i=0;i<n-1;i++)
        diff[i] = arr[i+1] - arr[i];
        
    int currDiff = diff[0];
    for(int i=1;i<n-1;i++)
    {
        if(diff[i-1] > 0)
            diff[i] = diff[i] + diff[i-1];
        if(diff[i] > currDiff)
            currDiff = diff[i];
    }
    if(currDiff < 0)
        return -1;
    return currDiff;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    int diff = findMaximumDifference(arr, n);
	    cout<<diff<<"\n";
	}
	return 0;
}