#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fun(ll arr[], int n)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0; i<n; i++)
        pq.push(arr[i]);
    ll sum = 0, a,b;
    while(pq.size()>1)
    {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        sum += (a+b);
        pq.push(a+b);
    }
    cout << sum;
}

int main() 
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    ll arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   fun(arr, n);
	   cout <<"\n";
	}
	return 0;
}