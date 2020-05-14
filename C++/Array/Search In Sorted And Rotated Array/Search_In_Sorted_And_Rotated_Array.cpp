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
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++;
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 	
		int pi = partition(arr, low, high); 

		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
}

int binarySearch(const int arr[], int l, int r,const int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 

		// If the element is present at the middle 
		// itself 
		if (arr[mid] == x) 
			return mid; 

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, mid + 1, r, x); 
	} 

	// We reach here when element is not 
	// present in array 
	return -1; 
}

int modifiedBinarySearch(const int arr[],int l, int r) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 

		if (arr[mid] > arr[mid+1]) 
			return mid;
	
		if (arr[l] > arr[mid]) 
			return modifiedBinarySearch(arr, l, mid - 1); 
 
		return modifiedBinarySearch(arr, mid + 1, r); 
	} 

	return -1; 
}


void searchInSortedRotateArray(const int arr[],const int n)
{
	int pivot=0, x, result; //index where array changes;

	pivot = modifiedBinarySearch(arr,0,n-1);

	if(pivot == -1)
		cout<<"\narray is not rotated!!";
	else
	{
		cout<<"\npivot is: "<<pivot<<"\n";
		cout<<"\nenter number to be search: ";
		cin>>x;

		if(x>= arr[pivot+1] && x<=arr[n-1])
			result = binarySearch(arr,pivot+1,n-1,x);
		else
			result = binarySearch(arr,0,pivot,x);

		if(result == -1)
			cout<<"\nops!! "<<x<<" is not present!!";
		else
			cout<<x<<" is present at: "<<result;
	}
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

	quickSort(arr, 0, n - 1); 
	cout << "Sorted array: \n"; 
	printArray(arr, n);

	cout<<"\nenter size of rotation: ";
	cin>>r;

	rotateArray(arr,n,r);
	cout<<"\narra after rotating: ";
	printArray(arr,n);

	searchInSortedRotateArray(arr,n);

	return 0;
}