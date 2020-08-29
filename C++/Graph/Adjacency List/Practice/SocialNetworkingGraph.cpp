#include<bits/stdc++.h>
using namespace std;

#define size 1000001
#define endl "\n"

vector<int> arr[size];
queue<int>q;
int dis[size], level[size];
bool vis[size];
int n,e,t,a,b;

void bfs(int src)
{
	q.push(src);
	vis[src]=1;
	dis[src]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int child: arr[node])
			if(vis[child]==0)
			{
				q.push(child);
				dis[child]=dis[node]+1;
				vis[child]=1;
				level[dis[child]]++;
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>e;
	while(e--)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		for(int i=0;i<size; i++)
			vis[i]=0, dis[i]=0, level[i]=0;
		bfs(a);
		cout<<level[b]<<endl;
	}
}