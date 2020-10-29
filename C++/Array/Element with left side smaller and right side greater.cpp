#include <bits/stdc++.h>
using namespace std;

int main()
{
	//code
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        int premax[n], suffmin[n];
        premax[0] = arr[0];
        suffmin[n-1] = arr[n-1];
        for(int i=1;i<n;i++)
            premax[i] = max(premax[i-1], arr[i]);
        for(int i=n-2;i>=0;i--)
            suffmin[i] = min(suffmin[i+1], arr[i]);
        int ind = -1;
        for(int i=1;i<n-1;i++)
            if(premax[i]==suffmin[i])
            {
                ind = i;
                break;
            }
        if(ind != -1)    
            cout<<arr[ind]<<'\n';
        else
            cout<<"-1\n";
    }
	return 0;
}