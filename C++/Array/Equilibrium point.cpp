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
	    for(int i=0;i<n;i++) cin>>arr[i];
	    
	    int pre[n]{0};
	    pre[0] = arr[0];
	    for(int i=1; i<n; i++) pre[i] = pre[i-1] + arr[i];
	    if(n==1)
	    {
	        cout<<"1\n";
	        continue;
	    }
	    int i=1;
	    for(; i<n; i++)
	    {
	        if(pre[i-1] == (pre[n-1] - pre[i])) break;
	    }
	    if(i==n)
	        cout<<"-1"<<'\n';
	    else
	        cout<<i+1<<'\n';
	}
	
	return 0;
}