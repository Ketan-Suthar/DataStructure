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
void rotateArray(int arr[],const int n, const int r)
{
	reverseArray(arr,0,n-r-1);
	reverseArray(arr,n-r,n-1);
	reverseArray(arr,0,n-1);
}
int main(int argc, char const *argv[])
{
	int n,r;
	cout<<"enter size of array: ";
	cin>>n;
	int arr[n];
	cout<<"\nenter "<<n<<" numbers: ";
	for(int i=0;i<n;++i)
		cin>>arr[i];

	cout<<"\narra before rotating: ";
	printArray(arr,n);

	cout<<"\nenter size of rotation: ";
	cin>>r;

	rotateArray(arr,n,r);
	cout<<"\narra after rotating: ";
	printArray(arr,n);
	return 0;
}