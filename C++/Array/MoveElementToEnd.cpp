#include <bits/stdc++.h>
using namespace std;

#define swap(a, b) a^=b^=a^=b

void moveElementToEnd(int *arr, int size, int element)
{
	int start = 0, end = size-1;
	while(start < end)
	{
		while((start < end) && arr[end] == element)
			--end;
		if(arr[start] == element)
			swap(arr[start], arr[end]);
		++start;
	}
}

int main(int argc, char const *argv[])
{
	int n, element;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cin>>element;
	moveElementToEnd(arr, n, element);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i];
	}
	return 0;
}