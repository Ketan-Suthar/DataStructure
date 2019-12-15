#include <iostream>

using namespace std;

void printArray(const int arr[], const int n)
{
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
}

void reverseArray(int arr[],const int start, const int end)
{
	int s=start, e=end,temp;
	while(s<e)
	{
		temp = arr[s];
		arr[s] = arr[e];
		arr[e] = temp;
		++s;
		--e;
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

	cout<<"\narra before reversing: ";
	printArray(arr,n);
	reverseArray(arr,0,n-1);
	cout<<"\narra after reversing: ";
	printArray(arr,n);
	return 0;
}