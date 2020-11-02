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
	    int sum=0;
	    for(int i=0;i<n;i++) cin>>arr[i], sum+=arr[i];
	    if(n==1)
	    {
	        cout<<"1\n";
	        continue;
	    }
	    int i=0,currSum=0;
	    for(; i<n; i++)
	    {
	        int temp = sum - arr[i] - currSum;
	        if(currSum == temp) break;
	        currSum += arr[i];
	    }
	    if(i==n)
	        cout<<"-1"<<'\n';
	    else
	        cout<<i+1<<'\n';
	}
	
	return 0;
}