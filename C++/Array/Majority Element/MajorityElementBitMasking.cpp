#include <iostream>
using namespace std;

int main()
{
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    int bits = sizeof(int) * 8;
	    int majo = (n/2);
	    int count = 0, num=0;
	    for(int i=0; i<bits; i++)
	    {
	        count = 0;
	        for(int j=0; j<n; j++)
	            if(arr[j] & (1<<i))
	                ++count;
	        if(count > majo)
	            num += (1<<i);
	    }
	    count =0;
	    for(int j=0; j<n; j++)
	            if(arr[j] == num)
	                ++count;
	    if(count > majo)       
	        cout<<num<<'\n';
	    else
	        cout<<"-1\n";
	}
	return 0;
}