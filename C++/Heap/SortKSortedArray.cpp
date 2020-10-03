#include <bits/stdc++.h>
using namespace std;

#define MinHeap priority_queue<int, vector<int>, greater<int>>

void sortUsingHeap(int *arr, int n, int k)
{
    MinHeap minHeap;
    int j=0;
    for(int i=0; i<n; i++)
    {
        minHeap.push(arr[i]);
        if(minHeap.size() > k)
        {
            arr[j++] = minHeap.top();
            minHeap.pop();
        }
    }
    while(minHeap.size() > 0)
    {
        arr[j++] = minHeap.top();
        minHeap.pop();
    }
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
        cin>>k;
        int  arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        
        sortUsingHeap(arr, n, k);
        for(int i=0; i<n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    return 0;
}