#include <iostream>

using namespace std;

void printArray(const int arr[], const int n)
{
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
}

void leadersInArray(const int arr[],const int n)
{
	int max = arr[n-1];
	cout<<"\nLeaders In Array are: "<<max<<" ";
	for(int i=n-2;i>=0;--i)
	{
		if(arr[i]>max)
		{
			cout<<arr[i]<<" ";
			max = arr[i];
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	int arr[n];
	cout<<"\nenter "<<n<<" numbers: ";
	for(int i=0;i<n;++i)
		cin>>arr[i];

	cout<<"\nyou entered: ";
	printArray(arr,n);

	leadersInArray(arr,n);

	return 0;
}