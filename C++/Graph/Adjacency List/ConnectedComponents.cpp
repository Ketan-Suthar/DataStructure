#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define pb push_back
vector<int> arr[MAX];
int n,e, cc;
bool isVis[MAX];

void dfs(int s)
{
	isVis[s] = 1;
	for(int child: arr[s])
		if(isVis[child] == 0)
			dfs(child);
}

int main()
{
	int a,b;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[b].pb(a);
		arr[a].pb(b);
	}
	for(int i=1; i<=n; i++)
		if(isVis[i] == 0)
			dfs(i), ++cc;
	cout<<cc;
}
