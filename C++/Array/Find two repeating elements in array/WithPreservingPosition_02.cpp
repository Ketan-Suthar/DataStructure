#include <iostream>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n; int a[n+2];
	    for(int i=0;i<n+2;i++) {cin>>a[i];}
	    for(int i=0;i<n+2;i++)
	    {
	      int ind = abs(a[i]);
	      if(a[ind]>=0)
	        a[ind] *= -1;
	       else
	        cout<<ind<<' ';
	    }
	    cout<<endl;
	}
	return 0;
}