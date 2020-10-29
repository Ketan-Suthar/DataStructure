#include <bits/stdc++.h>
using namespace std;

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
	    
	    int minSoFar = arr[0], diff=-1, currDiff = -1;
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i] < minSoFar)
	            minSoFar = arr[i];
	        else
	        {
	            currDiff = arr[i] - minSoFar;
	            if(currDiff>diff)
	                diff = currDiff;
	        }
	    }
	    cout<<diff<<"\n";
	}
	return 0;
}