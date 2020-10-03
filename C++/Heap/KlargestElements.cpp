#include <bits/stdc++.h>
using namespace std;

#define MinHeap priority_queue<int, vector<int>, greater<int>>

void printHeap(MinHeap minHeap)
{
    if(minHeap.size()<1)
        return;
    int top = minHeap.top();
    minHeap.pop();
    printHeap(minHeap);
    cout<<top<<' ';
}

int printKLargestElements(int *arr, int n, int k)
{
    MinHeap minHeap;
    for(int i=0; i<n; i++)
    {
        minHeap.push(arr[i]);
        if(minHeap.size() > k)
            minHeap.pop();
    }
    // while(minHeap.size() > 0)
    // {
    //     cout << minHeap.top()<<' ';
    //     minHeap.pop();
    // }
    printHeap(minHeap);
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
        cin >> k;
        int  arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        
        printKLargestElements(arr, n, k);
        cout << '\n';
    }
    return 0;
}