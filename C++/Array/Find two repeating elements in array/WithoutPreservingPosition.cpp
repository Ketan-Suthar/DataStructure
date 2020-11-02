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
        int i=0;
        for(i=0;i<n+2;i++) cin>>arr[i];
        
        int xy=0;
        for(i=0;i<n+2;i++)
            xy ^= arr[i];
        for(i=1;i<=n;i++)
            xy ^= i;
        
        int x=0,y=0;
        
        int set_bit = (xy & (~(xy-1)));
        // cout<<set_bit<<" ";
        for(i=0;i<n+2;i++)
        {
            if(arr[i] & set_bit)
                x ^= arr[i];
            else
                y ^= arr[i];
        }
        for(i=1;i<=n;i++)
        {
            if(i & set_bit)
                x ^= i;
            else
                y ^= i;
        }
        cout<<x<<' '<<y<<'\n';
    }
	return 0;
}