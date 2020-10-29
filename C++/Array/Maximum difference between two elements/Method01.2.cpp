#include <bits/stdc++.h>
using namespace std;

int findMaximumDifference(int *arr, int n)
{
    int diff = arr[1]-arr[0]; 
    int preDiff = diff; 
    int max_sum = preDiff; 
  
    for(int i=1; i<n-1; i++) 
    {
        diff = arr[i+1]-arr[i]; 
        if (preDiff > 0) 
            preDiff += diff; 
        else
            preDiff = diff; 
        if (preDiff > max_sum) 
            max_sum = preDiff; 
    } 
  
    return max_sum; 
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