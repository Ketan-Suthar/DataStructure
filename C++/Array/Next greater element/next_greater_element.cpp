#include <iostream>
#include <stack>

using namespace std;

void printArray(const int arr[], const int n)
{
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
}

void findNextGreaterElemet(const int arr[], const int n)
{
	int j=0;
	stack <int> s;
	s.push(arr[0]);
	cout<<"\n";
	for(int i=1;i<n;++i)
	{
		if (s.empty())
		{ 
      		s.push(arr[i]); 
      		continue; 
    	}

	    while (s.empty() == false && s.top() < arr[i]) 
	    {          
	        cout << s.top() << " --> " << arr[i] << endl; 
	        s.pop(); 
	    } 

    	s.push(arr[i]); 
	}
	while (s.empty() == false)
	{ 
	    cout << s.top() << " --> " << -1 << endl; 
	    s.pop(); 
	} 
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
	printArray(arr,n);
	findNextGreaterElemet(arr,n);
	return 0;
}