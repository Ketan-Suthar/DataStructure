#include <bits/stdc++.h>
using namespace std;

void fun(int *arr, int n, int k)
{
    int start = 0, end = 0, sum=0;
    sum = arr[start];
    while(start<n && end<n)
    {
        if(sum == k)
            break;
        else if(sum < k)
        {
            ++end;
            sum += arr[end];
        }
        else
        {
            sum -= arr[start];
            ++start;
        }
    }
    if(sum == k)
        cout<<start+1<<' '<<end+1;
    else
        cout<<"-1";
}

int main() {
	//code
	int n,k,t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    fun(arr, n, k);
	    cout<<'\n';
	}
	return 0;
}