#include <iostream>
using namespace std;
#define swap(a, b) a^=b^=a^=b
void _sort(int arr[], int left, int right)
{
    int start = left, end = right;
    while(start < end)
    {
        swap(arr[start], arr[end]);
        ++start;
        --end;
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
        int left = 0, right = left + k -1;
        while(right < n)
        {
            _sort(arr, left, right);
            left += k;
            right += k;
        }
        if(n % k)
        {
            _sort(arr, left, n-1);
        }
	    for(int i=0;i<n;i++) cout<<arr[i]<<' ';
	    cout<<'\n';
	}
	return 0;
}