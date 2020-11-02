#include <bits/stdc++.h>
using namespace std;

int possibleTriangles(int *arr, int n)
{
    sort(arr, arr+n);
    int count = 0;
    for(int a=0;a<n-2;a++)
    {
        int k = a + 2;
        for(int b=a+1;b<n-1;b++)
        {
            int c = arr[a] + arr[b];
            while(k<n && c > arr[k]) k++;
            count += (k - b - 1);
        }
    }
    return count;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    
	    cout << possibleTriangles(arr, n) << '\n';
	}
	return 0;
}