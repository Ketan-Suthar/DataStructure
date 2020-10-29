#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int k; cin>>k;
	
	deque<int> deq(k);
	int i=0;

	for(;i<k;i++)
	{
		while(!deq.empty() && arr[deq.back()] <= arr[i])
			deq.pop_back();
		deq.push_back(i);
	}

	for(;i<n;i++)
	{
		cout<<arr[deq.front()]<<" ";
		while(!deq.empty() && (deq.front()<=(i-k)))
			deq.pop_front();

		while(!deq.empty() && arr[deq.back()] <= arr[i])
			deq.pop_back();
		deq.push_back(i);
	}
	cout<<arr[deq.front()]<<" ";
	return 0;
}