#include<bits/stdc++.h>
using namespace std;

#define size 1000001
#define endl "\n"

vector<int> arr[size];
queue<int>q;
int low[size], intime[size];
bool vis[size];
int n,e,t,a,b, timer;

void dfs(int node, int par)
{
	vis[node]=1;
	low[node] = intime[node] = timer;
	++timer;

	for(int child: arr[node])
	{
		if(child == par)
			continue;
		if(vis[child]==0)
		{
			dfs(child, node);
			
			if(low[child] > intime[node])
				cout<<node<<" -> "<<child<<" is bridge\n";

			low[node] = min(low[node], low[child]);
		}
		else
			low[node] = min(low[node], intime[child]);	
		
	}
}


int main(int argc, char const *argv[])
{
	cin>>n>>e;
	while(e--)
		cin>>a>>b, arr[a].push_back(b), arr[b].push_back(a);

	dfs(1, -1);
	return 0;
}