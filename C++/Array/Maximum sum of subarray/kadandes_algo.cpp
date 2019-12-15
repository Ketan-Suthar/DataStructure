#include <iostream>
#include <climits>
using namespace std;

void kadanesAlgorithm(const int arr[], const int n)
{
	int s=0, start=0, end=0, max_far=arr[0], max_end=0;
	for(int i=0;i<n;++i)
	{
		max_end = max_end + arr[i];
		if(max_far < max_end)
		{
			max_far = max_end;
			start = s;
			end = i;
		}
		if(max_end<0)
		{
			max_end = 0;
			s=i+1;
		}
	}
	cout<<"\n maximum in subarray: "<<max_far;
	cout<<"\nsubaaray which contain max: ";
	for(int i=start;i<=end;++i)
		cout<<arr[i]<<" ";
}

int main(int argc, char const *argv[])
{
	int n,i=0;
	cout<<"enter size of aaray(>0): ";
	cin>>n;
	int arr[n];
	cout<<"\nenter "<<n<<" numbers: ";
	while(i<n)
	{
		cin>>arr[i];
		++i;
	}

	kadanesAlgorithm(arr,n);

	return 0;
}