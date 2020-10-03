#include <bits/stdc++.h>
using namespace std;

#define swap(a, b) a^=b^=a^=b

int main() 
{
	//code
	int n,t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    int start = 0, end = n - 1;
	    long maxEle = arr[end]+1;
	    for(int i=0; i<n; i++)
	    {
	        if(i & 1)
	            arr[i] += ((arr[start++] % maxEle ) * maxEle);
	        else
	            arr[i] += ((arr[end--] % maxEle ) * maxEle);
	    }
	    for(int i=0; i<n; i++)
	        cout<<arr[i]/maxEle<<' ';
	    cout<<'\n';
	}
	return 0;
}