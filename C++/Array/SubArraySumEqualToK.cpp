#include <bits/stdc++.h>
using namespace std;

int fun(int *arr, int n, int k)
{
    unordered_map<int, int> sumExist;
    int currSum = 0, i=0, count=0;
    while(i < n)
    {
        currSum += arr[i];
        if(currSum == k)
            count += 1;
        if(sumExist.find(currSum - k) != sumExist.end())
        {
            count += sumExist[currSum - k];
        }
        sumExist[currSum] += 1;
        ++i;
    }
    return count;
}

int main()
{
	//code
	int t;
	cin>>t;
	while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout << fun(arr, n, k) << '\n';
    }
	return 0;
}