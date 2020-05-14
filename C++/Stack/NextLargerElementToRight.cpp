#include <bits/stdc++.h>
using namespace std;

void fun(long int arr[], long int n)
{
    vector<long int> result;
    stack<long int> stk;
    
    for(long int i=n-1; i>=0; i--)
    {
        if(stk.empty())
            result.push_back(-1);
        else if(stk.size() > 0 && arr[i] < stk.top())
            result.push_back(stk.top());
        else
        {
            while(stk.size() > 0 && stk.top() <= arr[i])
                stk.pop();
            if(stk.empty())
                result.push_back(-1);
            else
                result.push_back(stk.top());
        }
        stk.push(arr[i]);
    }
    for(long int i=result.size()-1; i>=0; i--)
        cout << result[i] << " ";
    cout << "\n";
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
	}
	return 0;
}