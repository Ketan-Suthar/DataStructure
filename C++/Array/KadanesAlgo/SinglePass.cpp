#include <bits/stdc++.h>
using namespace std;

int main() 
{
	//code
	int n,t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    int result = INT_MIN;
	    int sum=0;
	    for(int i=0; i<n ;i++)
	    {
	        sum = max(arr[i], arr[i]+sum);
	        if(sum > result)
	            result = sum;
	    }
	    cout<<result<<'\n';
	}
	return 0;
}