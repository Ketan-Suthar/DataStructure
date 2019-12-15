#include <iostream>
#include <climits>
using namespace std;

void remove_duplicates(int arr[], int &n)
{
	int j=0;
	for(int i=0;i<n-1;++i)
	{
		if(arr[i]!=arr[i+1])
		{
			arr[j] = arr[i];
			++j;
		}
	}
	arr[j] = arr[n-1];
	n=j+1;
}

int main(int argc, char const *argv[])
{
	int n,i=0, prev=INT_MIN, value;
	cout<<"enter size of aaray(>0): ";
	cin>>n;
	int arr[n];
	cout<<"\nenter "<<n<<" in ascending order: ";
	while(i<n)
	{
		cin>>value;
		if(value>=prev)
		{
			arr[i] = value;
			prev = value;
			++i;
		}
	}

	remove_duplicates(arr,n);
	
	cout<<"\narray after removing duplicate items: ";
	for(i=0;i<n;++i)
		cout<<arr[i]<<" ";
	return 0;
}