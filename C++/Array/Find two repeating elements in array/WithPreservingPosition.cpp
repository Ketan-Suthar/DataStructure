#include <iostream>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n; int a[n+2],b[n+2]={0};
	    for(int i=0;i<n+2;i++) {cin>>a[i];}
	    for(int i=0;i<n+2;i++)
	    {
	      b[a[i]]=b[a[i]]+1;
	      if(b[a[i]]==2) {cout<<a[i]<<" ";}
	    }
	    cout<<endl;
	}
	return 0;
}