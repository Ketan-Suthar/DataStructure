#include <iostream>
#include <climits>
using namespace std;

void swap(int &a,int &b)
{
	int temp=b;
	b=a;
	a=temp;
}

void segregate(int arr[],const int n)
{
	int mid=0,high=n-1,low=0;
	while(mid<=high)
	{
		switch(arr[mid])
		{
			case 0:
				swap(arr[low],arr[mid]);
				++low;
				++mid;
				break;
			case 1:
				++mid;
				break;
			case 2:
				swap(arr[mid],arr[high]);
				--high;
		}
	}
	cout<<"\narray after sagragating 0,1,2's: ";
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
}

int main(int argc, char const *argv[])
{
	int n,i=0;
	cout<<"enter size of aaray(>0): ";
	cin>>n;
	int arr[n];
	cout<<"\nenter "<<n<<" in ascending order: ";
	while(i<n)
	{
		cin>>arr[i];
		++i;
	}

	segregate(arr,n);

	return 0;
}