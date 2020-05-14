#include <bits/stdc++.h>
using namespace std;

void fun(long int arr[], int n)
{
    stack<pair<int, int>> stk;
    vector<int> result(n);
    
    for(long int i=0; i<n; i++)
    {
        if(stk.empty())
            result[i] = (-1);
        else if(arr[i] < stk.top().first)
            result[i] = (stk.top().second);
        else
        {
            while(!stk.empty() && stk.top().first <= arr[i])
                stk.pop();
            if(stk.empty())
                result[i] = (-1);
            else
                result[i] = (stk.top().second);
        }
        stk.push(make_pair(arr[i], i));
    }
    for(int i=0; i<result.size(); i++)
        cout << i - result[i] << " ";
}

int main()
{
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    long int n;
	    cin >> n;
	    long int arr[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	   fun(arr, n);
	   cout << "\n";
	}
	return 0;
}