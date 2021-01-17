#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n;cin>>n;
	    ll arr[n], i;
	    for(i=0;i<n;i++) cin>>arr[i];
	    
	    for(i=0;i<n;i++)
	        arr[i] = arr[i] + ((arr[arr[i]] % n) * n);
	    for(i=0;i<n;i++)
	        arr[i] = arr[i] / n;
	    for(i=0;i<n;i++) cout<<arr[i]<<' ';
	    cout<<'\n';
	}
	return 0;
}