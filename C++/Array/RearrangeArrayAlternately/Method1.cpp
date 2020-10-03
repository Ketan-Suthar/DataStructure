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
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    int start = 0, end = n - 1;
	    int result[n], i = 0;
	    while(start <= end)
	    {
	        result[i++] = arr[end--];
	        if(start <= end)
	            result[i++] = arr[start++];
	    }
	    for(int i=0; i<n; i++)
	        cout<<result[i]<<' ';
	    cout<<'\n';
	}
	return 0;
}