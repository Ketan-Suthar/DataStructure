#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n; i++) cin>>arr[i];
	    int result[n], ind = 0;
	    int max = arr[n-1];
	    result[ind++] = max;
	    for(int i=n-2;i>=0; i--)
	    {
	        if(arr[i]>=max)
	        {
	            max=arr[i];
	            result[ind++] = max;
	        }
	    }
	    for(int i=ind-1; i>=0; i--)
	       cout<<result[i]<<' ';
	    cout<<'\n';
	}
	return 0;
}