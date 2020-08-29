#include<bits/stdc++.h> 
using namespace std;

#define size 2000
int t,n,e;
int col[size+1];
vector<int> arr[size+1];
bool vis[size+1];

bool dfs(int s, int color)
{
	vis[s] = 1;
	col[s] = color;
	for(int child: arr[s])
	{
		if(vis[child]==0)
			if(dfs(child, color^1) == false)
				return false;
		if(col[s] == col[child])
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	cin>>t;
	int a,b;
	for (int tc = 1; tc <= t; ++tc)
	{
		for (int i = 0; i <= size; ++i)
			arr[i].clear(), vis[i] = 0, col[i] = -1;

		cin>>n>>e;
		for (int i = 1; i <= e; ++i)
			cin>>a>>b,arr[a].push_back(b), arr[b].push_back(a);

		bool res = 1;
		for (int i = 1; i <= n; ++i)
			if(vis[i] == 0)
			{
				bool temp = dfs(i, 0);
				if(temp==false)
					res=temp;
			}
		
		cout<<"Scenario #"<<tc<<":\n";
		if(res)
			cout<<"No suspicious bugs found!\n";
		else
			cout<<"Suspicious bugs found!\n";
	}
	return 0;
}