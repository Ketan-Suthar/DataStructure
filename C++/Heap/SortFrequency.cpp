#include <bits/stdc++.h>
using namespace std;
struct compare
{
bool operator()(pair<int,int> const &p1, pair<int,int> const &p2)
{
    if(p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}
};
void fun(int nums[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++)
        mp[nums[i]]++;
    
    priority_queue<pair<int,int>, vector<pair<int, int>>, compare>pq;
    
    for(auto it=mp.begin();it!=mp.end();it++)
        pq.push({it->second,it->first});

    while(!pq.empty())
    {
        int ele = pq.top().second;
        for(int i=0; i<pq.top().first; i++)
            cout << ele << " ";
        pq.pop();
    }
    cout << "\n";
}

static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

int main()
{
    //Solution();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int  arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        fun(arr, n);
    }
    return 0;
}