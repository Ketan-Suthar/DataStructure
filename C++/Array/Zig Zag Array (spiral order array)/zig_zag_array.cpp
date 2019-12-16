// C++ program to remove the duplicates from the array. 
#include "iostream" 
#include "unordered_map" 
using namespace std; 

void swap(int &a,int &b)
{
	int temp=b;
	b=a;
	a=temp;
}

void printArray(const int arr[], const int n)
{
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
}

void createZigZagArray(int arr[], int n)
{
	int i=0;
	bool flag =0;
	while(i<n-1)
	{
		if(flag)
		{
			if(arr[i]<arr[i+1])
				swap(arr[i],arr[i+1]);
			flag = !flag;
		}
		else
		{
			if(arr[i]>arr[i+1])
				swap(arr[i],arr[i+1]);
			flag = !flag;
		}
		++i;
	}
}

int main(int argc, char const* argv[]) 
{ 
	int n,i=0;
	cout<<"enter size of aaray(>0): ";
	cin>>n;
	int arr[n];
	cout<<"\nenter "<<n<<" unique numbers: ";
	while(i<n)
	{
		cin>>arr[i];
		++i;
	}

	cout<<"\nyou entered array: ";
	printArray(arr,n);
	createZigZagArray(arr, n); 

	cout<<"\nZig Zag array: ";
	printArray(arr,n);
	return 0; 
} 
