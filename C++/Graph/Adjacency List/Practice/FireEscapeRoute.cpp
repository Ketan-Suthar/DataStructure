#include <bits/stdc++.h>
using namespace std;

#define size 100001
#define mod 1000000007
#define endl "\n"

vector<int> arr[size+1];
int ccs=0;
int n,e,t;
bool vis[size+1];

void dfs(int s)
{
	++ccs;
	vis[s]=1;
	for(int c: arr[s])
		if(vis[c]==0)
			dfs(c);
}

int main(int argc, char const *argv[])
{
	cin>>t;
	int a,b;
	while(t--)
	{
		for(int i=0; i<=size; i++)
	        arr[i].clear(), vis[i]=0;
		cin>>n>>e;
		for (int i = 0; i < e; ++i)
		{
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		int pre=0, cc=0;
		long long int res=1;
		for(int i=1; i<=n; i++)
		{
			if(vis[i]==0)
			{
				ccs=0;
				++cc;
				dfs(i);
				res = (res%mod * ccs%mod)%mod;
			}
		}
		cout<<cc<<" "<<res<<endl;
	}
	return 0;
}