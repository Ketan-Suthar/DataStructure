#include <iostream>
using namespace std;

int main() {
	//code
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        if(arr[0]<arr[1])
            swap(arr[0], arr[1]);
        for(int i=2;i<n;i+=2)
        {
            if((i!=0) && arr[i]<arr[i-1])
                swap(arr[i], arr[i-1]);
            if((i!=n-1) && arr[i]<arr[i+1])
                swap(arr[i], arr[i+1]);
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<' ';
        cout<<'\n';
    }
	return 0;
}