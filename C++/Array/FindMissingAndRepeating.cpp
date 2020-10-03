#include <bits/stdc++.h>
using namespace std;

#define swap(a, b) a^=b^=a^=b

vector<vector<int>> findMissingAndDuplicate(int *arr, int n)
{
    vector<vector<int>> result;
    if(n==0)
        return result;
    int i=0;
    int currectPosition;
    while(i < n)
    {
        if(arr[i] != arr[arr[i]-1])
        {
            currectPosition = arr[i]-1;
            swap(arr[i], arr[currectPosition]);
        }
        else
            i = i + 1;
    }
    vector<int> missing, duplicates;
    int ind=0;
    for(i=0; i < n; i++)
        if(arr[i] != i+1)
        {
            missing.push_back(i+1);
            duplicates.push_back(arr[i]);
        }
    
    result.push_back(duplicates);
    result.push_back(missing);
    return result;
}

int main()
{
	//code
	int n,t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    vector<vector<int>> result= findMissingAndDuplicate(arr, n);
	    for(auto res: result)
	    {
	        for(int j: res)
	            cout<<j<<' ';
	    }
	    cout<<'\n';
	}
	return 0;
}