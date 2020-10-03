#include <bits/stdc++.h>
using namespace std;

int getKthSmallestElement(int *arr, int n, int k)
{
    priority_queue<int> maxHeap;
    for(int i=0; i<n; i++)
    {
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k)
            maxHeap.pop();
    }
    return maxHeap.top();
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
        int n, k;
        cin >> n;
        int  arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        cin>>k;
        cout << getKthSmallestElement(arr, n, k) << '\n';
    }
    return 0;
}