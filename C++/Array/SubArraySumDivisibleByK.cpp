#include <bits/stdc++.h>
using namespace std;

int fun(int *arr, int n, int k)
{
    int mod[k];
    memset(mod, 0, sizeof(mod));
    int currSum = 0, i=0;
    for(int i=0; i<n; i++)
    {
        currSum += arr[i];
        ++mod[((currSum % k) + k) % k];
    }
    int result = 0;
    for (int i = 0; i < k; i++) 
        if (mod[i] > 1) 
            result += (mod[i] * (mod[i] - 1)) / 2;
    result += mod[0]; 
  
    return result; 
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