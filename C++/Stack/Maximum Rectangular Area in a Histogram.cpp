#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

void findNSL(ll arr[], ll n, vector<ll> &left, int minEle)
{
    stack<pair<ll, ll>> stk;
    for(ll i=0; i < n; i++)
    {
        while(!stk.empty() && stk.top().first > arr[i])
            stk.pop();
        if(stk.empty())
            left.push_back(minEle);
        else
            left.push_back(stk.top().second);
            
        stk.push(make_pair(arr[i], i));
    }
}

void findNSR(ll arr[], ll n, vector<ll> &right, int minEle)
{
    stack<pair<ll, ll>> stk;
    for(ll i=n-1; i >= 0; i--)
    {
        while(!stk.empty() && stk.top().first > arr[i])
            stk.pop();
        if(stk.empty())
            right.push_back(minEle);
        else
            right.push_back(stk.top().second);
            
        stk.push(make_pair(arr[i], i));
    }
}

ll fun(ll arr[], ll n)
{
    vector<ll> left, right;
    findNSL(arr, n, left, -1);
    findNSR(arr, n, right, n);
    
    reverse(right.begin(), right.end());

    ll ans = INT_MIN;

    for(ll i=0; i < n; i++)
    {
        ll width = (right[i] - left[i]) - 1;
        //cout << width << " ";
        if((width * arr[i]) > ans)
            ans = (width * arr[i]);
    }

    return ans;
}

int main()
{
    FAST;
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    ll n;
	    cin >> n;
	    ll arr[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	   cout << fun(arr, n) << "\n";
	}
	return 0;
}