// C++ program to find predecessor and successor in a BST 
#include <iostream> 
using namespace std; 


int main() 
{ 
	int n;
	cout<<"enter numbers of node: ";
	cin>>n;
	int arr[n];
	arr[0] = arr[1] = 1;

	for(int i=2;i<=n;++i)
	{
		arr[i] =0;
		for(int j=0;j<i;++j)
			arr[i] += arr[j]*arr[i-j-1];
	}
	cout<<"\nTotal number posssible BST wiht "<<n<<" nodes is: "<<arr[n];
	return 0; 
} 
